/******** DO NOT EDIT THIS FILE ********/
#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include "rft_util.h"

#define INF_MSG_SIZE 256    // max size of information messages to print out

/* struct to capture transfer information for report */
typedef struct trans_inf {
    off_t file_size;        // size of file being transferred
    size_t valid_payload;   // total valid bytes of payload
    int total_segs;         // total segments received
    int corrupt_segs;       // total corrupted segments
    int expected_sq;        // record of expected sequence number
} trans_inf_t;

/*
 * This file contains the main function for the server.
 * Do NOT change anything in this file.
 * 
 * For a usage message for the server type:
 * 
 *      rft_server
 *    
 * this will output a message explaining the command line options.
 *
 * Or start server as:
 *      
 *      rft_server <port>
 *
 * where port is a port for the server to listen on in the range 1025 to 65535
 */

/* 
 * receive_file - receive a file on the given socket from the given client 
 * with given file metadata (expected size and name to write output to)
 */
static void receive_file(int sockfd, struct sockaddr_in* client, 
    metadata_t* file_inf, trans_inf_t* tr_inf);

/* 
 * process_data_msg - function used by receive_file to process a single data
 * segment and send ack to client and write payload to file
 * returns indication of whether still in receiving state.
 */
static bool process_data_msg(int sockfd, struct sockaddr_in* client, 
    segment_t* data_msg, FILE* out_file, trans_inf_t* tr_inf);

/* 
 * Functions for information and error messages.
 */
static void print_sep();                        // print separator to stdout
static void fprint_sep(FILE* stream);           // print separator to stream
static void print_msg(char* msg);               // print information message
static void print_err(int line, char* msg);     // print error message
static void exit_err(int sockfd, FILE* out_file, int line, char* msg);    
                                                // exit with error message
static void print_summary(char* inf_msg_buf, metadata_t* file_inf, 
    trans_inf_t* tr_inf);

/* the main function and entry point for rft_server */
int main(int argc,char *argv[]) {
    /* user needs to enter the port number */
    if (argc < 2) {
        printf("usage: %s <port>\n", argv[0]);
        printf("       port is a number between 1025 and 65535\n");
        exit(EXIT_FAILURE);
    }
    
    uint16_t port = atoi(argv[1]);
    
    if (port < PORT_MIN || port > PORT_MAX) 
        exit_err(-1, NULL, __LINE__, "Port is outside valid range");
    
    /* create a socket */
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    
    if (sockfd == -1)
        exit_err(-1, NULL, __LINE__, "Failed to open socket"); 
        
    print_msg("Socket created");
 
    /* set up address structures */
    struct sockaddr_in server;
    struct sockaddr_in client;
    socklen_t sock_len = (socklen_t) sizeof(struct sockaddr_in); 
    memset(&server, 0, sock_len);
    memset(&client, 0, sock_len);
    
    /* Fill in the server address structure */
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = htonl(INADDR_ANY);
    server.sin_port = htons(port);
    
    /* bind/associate the socket with the server address */
    if(bind(sockfd, (struct sockaddr *) &server, sock_len))
        exit_err(sockfd, NULL, __LINE__, "Bind failed");
    
    char inf_msg_buf[INF_MSG_SIZE];              
    snprintf(inf_msg_buf, INF_MSG_SIZE, 
            "Bind success, server listening on port %d\n"
            "Ready to receive meta data from client", port); 
    print_msg(inf_msg_buf);
    print_sep();
      
    metadata_t file_inf;
    size_t metadata_size = sizeof(metadata_t);
    memset(&file_inf, 0, sizeof(metadata_t));
    socklen_t addr_len = sock_len;
    ssize_t bytes = -1;

    //receive metadata from the client    
    bytes = recvfrom(sockfd, &file_inf, metadata_size, 0, 
                    (struct sockaddr*) &client, &addr_len);
                    
    if (bytes != metadata_size) {
        snprintf(inf_msg_buf, INF_MSG_SIZE, 
            "Expected metadata size %zd bytes, received %zd bytes",
                metadata_size, bytes);
        exit_err(sockfd, NULL, __LINE__, inf_msg_buf);
    } else if (!file_inf.name[0] || file_inf.size < 0) {
        errno = EINVAL;
        exit_err(sockfd, NULL, __LINE__,  
            "Metadata file name is empty or size < 0");
    } else {
        print_msg("Meta data received successfully");
        snprintf(inf_msg_buf, INF_MSG_SIZE, 
            "Output file name: %s, expected file size: %ld", file_inf.name, 
            (long) file_inf.size);
        print_msg(inf_msg_buf);
    }
    
    print_msg("Waiting for the file ..."); 
    
    trans_inf_t tr_inf;
    tr_inf.file_size = file_inf.size;
    tr_inf.valid_payload = 0;
    tr_inf.total_segs = 0;
    tr_inf.corrupt_segs = 0;
    tr_inf.expected_sq = 0;
    
    receive_file(sockfd, &client, &file_inf, &tr_inf);
    
    close(sockfd);
    
    print_summary(inf_msg_buf, &file_inf, &tr_inf);
    
    return EXIT_SUCCESS;
}

static void receive_file(int sockfd, struct sockaddr_in* metadata_client, 
    metadata_t* file_inf, trans_inf_t* tr_inf) {
    socklen_t addr_len = (socklen_t) sizeof(struct sockaddr_in);
    segment_t data_msg;
    char inf_msg_buf[INF_MSG_SIZE];

    /* Open the output file */
#ifndef _SILENCE_LOGGING
    printf("file_inf->name: %s\n", file_inf->name);
#endif
    FILE* out_file = fopen(file_inf->name, "w");
    
    if (!out_file) 
        exit_err(sockfd, NULL, __LINE__, "Could not open output file");
        
    // don't wait for empty file
    if (!file_inf->size) {
        fclose(out_file);
        return;
    }
                
    print_sep();
    print_sep();
    
    bool receiving = true;
    bool first_seg = true;
    size_t seg_size = sizeof(segment_t);
    
    /* while still receiving segments */
    while (receiving) {
        struct sockaddr_in client;
        socklen_t client_addr_len = addr_len;
        memset(&data_msg, 0, seg_size);
        memset(&client, 0, addr_len);
        ssize_t bytes = recvfrom(sockfd, &data_msg, seg_size, 0,
                        (struct sockaddr*) &client, &client_addr_len);
        
        if (bytes != seg_size) {
            snprintf(inf_msg_buf, INF_MSG_SIZE, 
                "Expected data message size %zd bytes, received %zd bytes",
                seg_size, bytes);
            exit_err(sockfd, out_file, __LINE__, inf_msg_buf);
        } 
        
        if (client_addr_len != addr_len 
            || client.sin_family != metadata_client->sin_family
            || client.sin_port != metadata_client->sin_port
            || client.sin_addr.s_addr != metadata_client->sin_addr.s_addr) {
            exit_err(sockfd, out_file, __LINE__, 
                "Client that sent metadata does not match client sending data");
        }
        
        if (first_seg) /* first segment to be received */
            print_msg("File transfer started"); 

        receiving = process_data_msg(sockfd, &client, &data_msg, out_file,
                        tr_inf);
                        
        first_seg = false;

#ifdef _SILENCE_LOGGING
        printf(".");
        fflush(stdout);
#endif
    }
    
    print_msg("File copying complete");
    
    fclose(out_file);
}

static bool process_data_msg(int sockfd, struct sockaddr_in* client, 
    segment_t* data_msg, FILE* out_file, trans_inf_t* tr_inf) {
    bool receiving = true;
    char inf_msg_buf[INF_MSG_SIZE];
    size_t seg_size = sizeof(segment_t);
    
    tr_inf->total_segs++;

    snprintf(inf_msg_buf, INF_MSG_SIZE, 
        "Received segment with sq: %d, file data: %zd, checksum: %d", 
        data_msg->sq, data_msg->file_data, data_msg->checksum);
    print_msg(inf_msg_buf);
    
    if (data_msg->sq != tr_inf->expected_sq) {
        snprintf(inf_msg_buf, INF_MSG_SIZE, 
            "Data message sequence number: %d != expected sequence number: %d",
            data_msg->sq, tr_inf->expected_sq);
        exit_err(sockfd, out_file, __LINE__, inf_msg_buf);
    }
    
    if (data_msg->payload[PAYLOAD_SIZE - 1]) {
        errno = EINVAL;
        exit_err(sockfd, out_file, __LINE__, "Payload not terminated");
    }

    size_t payload_len = strnlen(data_msg->payload, PAYLOAD_SIZE);
    
    if (payload_len != data_msg->file_data) {
        errno = EINVAL;
        snprintf(inf_msg_buf, INF_MSG_SIZE, 
            "Segment file data is: %zd bytes\nactual size: %zd",
            data_msg->file_data, payload_len);
        exit_err(sockfd, out_file, __LINE__, inf_msg_buf);
    }
        
    snprintf(inf_msg_buf, INF_MSG_SIZE, "Received payload:\n%s",
        data_msg->payload);
    print_msg(inf_msg_buf);
    
    int cs = checksum(data_msg->payload, false);

    /* 
     * If the calculated checksum is same as that of received 
     * checksum then send corresponding ack
     */
    if (cs == data_msg->checksum) {
        tr_inf->valid_payload += data_msg->file_data;
        
        /* is there still data to receive */
        receiving = tr_inf->file_size > tr_inf->valid_payload; 
                 
        snprintf(inf_msg_buf, INF_MSG_SIZE, "Calculated checksum %d VALID",
            cs);
        print_msg(inf_msg_buf);
        
        /* write the payload of the data segment to output file */
        if (fprintf(out_file, "%s", data_msg->payload) < 0) {
            exit_err(sockfd, out_file, __LINE__, 
                "Writing payload to file failed");
        } else {
            snprintf(inf_msg_buf, INF_MSG_SIZE, 
                "Payload for segment %d written to file", data_msg->sq);
            print_msg(inf_msg_buf);
        }
            
        /* Prepare the Ack segment */
        segment_t ack_msg;
        memset(&ack_msg, 0, seg_size);
        ack_msg.sq = data_msg->sq;
        ack_msg.type= ACK_SEG;
    
        snprintf(inf_msg_buf, INF_MSG_SIZE, "Sending ACK with sq: %d",
            ack_msg.sq);
        print_msg(inf_msg_buf);
    
        /* Send the Ack segment */
        ssize_t bytes = sendto(sockfd, &ack_msg, seg_size, 0,
                    (struct sockaddr*) client, sizeof(struct sockaddr_in));
                    
        if (bytes != seg_size) {
            snprintf(inf_msg_buf, INF_MSG_SIZE, 
                "Expected ack sent size %zd bytes, actual sent size %zd bytes",
                seg_size, bytes);
            exit_err(sockfd, out_file, __LINE__, inf_msg_buf);
        } else {
#ifndef _SILENCE_LOGGING
            printf("        >>>> NETWORK: ACK sent successfully <<<<\n");
#endif
            tr_inf->expected_sq += 1;
        }
     
        print_sep();
        print_sep();
    } else {
        tr_inf->corrupt_segs++;
        
        snprintf(inf_msg_buf, INF_MSG_SIZE, "Segment checksum %d INVALID",
            cs);
        print_msg(inf_msg_buf);
        print_msg("Did NOT send any ACK");
    }    
    
    return receiving;
}



static void print_sep() {
#ifndef _SILENCE_LOGGING
    fprint_sep(stdout);
#endif
}

static void fprint_sep(FILE* stream) {
    fprintf(stream, 
            "----------------------------------------------------------"
            "---------------------\n");
}

void print_msg(char* msg) {
#ifndef _SILENCE_LOGGING
    print_sep();
    printf("SERVER: %s\n", msg);
    print_sep();
#endif
}

void print_err(int line, char* msg) {
    fprint_sep(stderr);
    if (errno) {
        fprintf(stderr, "SERVER ERROR: [%s:%d - %s]\n%s\n", __FILE__, line,
            strerror(errno), msg);
    } else {
        fprintf(stderr, "SERVER ERROR: [%s:%d]\n%s\n", __FILE__, line, msg);
    }      
}

static void exit_err(int sockfd, FILE* out_file, int line, char* msg) {
    if (sockfd != -1) close(sockfd);
    if (out_file) fclose(out_file);
    print_err(line, msg);
    exit(EXIT_FAILURE);
}

static void print_summary(char* inf_msg_buf, metadata_t* file_inf,
    trans_inf_t* tr_inf) {
    snprintf(inf_msg_buf, INF_MSG_SIZE, "Transfer summary for output file: %s",
        file_inf->name);
#ifdef _SILENCE_LOGGING
    printf("\n==================================================================="
        "=====\n");
    printf("\n%s\n", inf_msg_buf);
#else
    print_msg(inf_msg_buf);
#endif
    
    struct stat stat_buf;
    stat(file_inf->name, &stat_buf);
    
    printf("        %ld bytes expected, %ld bytes written to file, "
           "%ld bytes valid payload\n", (long) file_inf->size,
           (long) stat_buf.st_size, (long) tr_inf->valid_payload);
    printf("            payload validation: ");
    if (file_inf->size == stat_buf.st_size 
        && stat_buf.st_size == tr_inf->valid_payload) {
        printf("SUCCESS\n");
    } else {
        printf("FAILURE - see discrepancy in above values\n");
    }

    int segs_expected = file_inf->size / (PAYLOAD_SIZE - 1) +
        (file_inf->size % (PAYLOAD_SIZE - 1) ? 1 : 0);
    
    printf("        %d segments expected, %d valid segments received\n",
        segs_expected, tr_inf->total_segs - tr_inf->corrupt_segs);
    printf("            segment validation: ");
    if (segs_expected == (tr_inf->total_segs - tr_inf->corrupt_segs)) {
        printf("SUCCESS\n");
    } else {
        printf("FAILURE - see discrepancy in above values\n");
    }

    if (segs_expected) {
        printf("        %d total segments, %d corrupt segments\n", 
            tr_inf->total_segs, tr_inf->corrupt_segs);
        printf("            segment loss: %5.1f%%\n",
            100.0 * (float) tr_inf->corrupt_segs / (float) tr_inf->total_segs);
    }
    
#ifdef _SILENCE_LOGGING
    printf("==================================================================="
        "=====\n");
#endif

    print_sep();
    print_sep();
}




 