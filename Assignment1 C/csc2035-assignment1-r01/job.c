/*
 * Replace the following string of 0s with your student number
 * C1023544
 */
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "job.h"

/* 
 * DO NOT EDIT the job_new function.
 */
job_t* job_new(pid_t pid, unsigned int id, unsigned int priority, 
    const char* label) {
    return job_set((job_t*) malloc(sizeof(job_t)), pid, id, priority, label);
}

/* 
 * TODO: you must implement this function
 */
job_t* job_copy(job_t* src, job_t* dst) {
    
    if (src == NULL){
        return NULL;
    }
    
    if (strlen(src->label) != MAX_NAME_SIZE - 1){
            return NULL;
        }
    
    if (dst == NULL){
        job_t* new_job = malloc(sizeof(src));
        new_job = job_new(src->pid, src->id, src->priority, src->label);
        return new_job;
    }
    
    if (src == dst){
        return src;
    }
    
    else{
        job_set(dst, src->pid, src->id, src->priority, src->label);
        return dst;
    }
    
    return src;
}

/* 
 * TODO: you must implement this function
 */
void job_init(job_t* job) {
    
    if (job !=NULL){
        job->pid = 0;
        job->id = 0;
        job->priority = 0;
        snprintf(job->label, 32, PAD_STRING);
    }
    else{
        return;
    }
    
}

/* 
 * TODO: you must implement this function
 */
bool job_is_equal(job_t* j1, job_t* j2) {
    
    if ((j1 == NULL) && (j2 == NULL)){
        return true;
    }
    
    else if ((j1 == NULL) || (j2 == NULL)){
        return false;
    }
    
    if((j1->pid == j2->pid) && (j1->id == j2->id) && (j1->priority == j2->priority) && (strcmp(j1->label, j2->label) == 0)){
        return true;
    }
    
    else{
        return false;
    }
}

/*
 * TODO: you must implement this function.
 * Hint:
 * - read the information in job.h about padding and truncation of job
 *      labels
 */
job_t* job_set(job_t* job, pid_t pid, unsigned int id, unsigned int priority,
    const char* label) {
        
        if (job == NULL){
            return NULL;
        }
        
        else{
            
            job->pid = pid;
            job->id = id;
            job->priority = priority;
            
            if (label == NULL){
                snprintf(job->label, MAX_NAME_SIZE, PAD_STRING);
            }
            else{
                snprintf(job->label, MAX_NAME_SIZE, "%s%s", label, PAD_STRING);
            }
            
            return job;
        }   
}

/*
 * TODO: you must implement this function.
 * Hint:
 * - see malloc and calloc system library functions for dynamic allocation, 
 *      and the documentation in job.h for when to do dynamic allocation
 */
char* job_to_str(job_t* job, char* str) {
    
    if (job == NULL){
        return NULL;
    }
    
    if (strlen(job->label) != MAX_NAME_SIZE -1){
        return NULL;
    }
    
    if (str == NULL){
        char* buffer = malloc(sizeof(str) * JOB_STR_SIZE);
        snprintf(buffer, JOB_STR_SIZE, JOB_STR_FMT, job->pid, job->id, job->priority, job->label);
        
        if (buffer != NULL && strlen(buffer) == 68){
            return buffer;
        }
    }
        
    snprintf(str, JOB_STR_SIZE, JOB_STR_FMT, job->pid, job->id, job->priority, job->label);
        
    if(strlen(str) == 68){
        return str;
    }
    
    return NULL;
}

/*
 * TODO: you must implement this function.
 * Hint:
 * - see the hint for job_to_str
 */
job_t* str_to_job(char* str, job_t* job) {
    
    int pid = 0;
    unsigned int id = 0;
    unsigned int priority = 0;
    char label[MAX_NAME_SIZE];
    
    if (str == NULL){
        return NULL;
    }
    
    if (strlen(str) != JOB_STR_SIZE - 1){;
        return NULL;
    }
    
    if (job == NULL){
       job = (job_t*)malloc(sizeof(job_t));
    }
    
    if (sscanf(str, JOB_STR_FMT, &pid, &id, &priority, label) == 4 && strlen(label) == MAX_NAME_SIZE - 1 ){
    
        return job_set(job, pid, id, priority, label);
        
    }
    
    return NULL;
}

/* 
 * TODO: you must implement this function
 * Hint:
 * - look at the allocation of a job in job_new
 */
void job_delete(job_t* job) {
    
    free(job);
    
    return;
}

