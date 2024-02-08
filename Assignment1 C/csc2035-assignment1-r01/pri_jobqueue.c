/*
 * Replace the following string of 0s with your student number
 * C1023544
 */
#include <stdlib.h>
#include <stdbool.h>
#include "pri_jobqueue.h"

/* 
 * TODO: you must implement this function that allocates a job queue and 
 * initialise it.
 * Hint:
 * - see job_new in job.c
 */
pri_jobqueue_t* pri_jobqueue_new() {
    
    pri_jobqueue_t* new_jobqueue = (pri_jobqueue_t*) malloc(sizeof(pri_jobqueue_t));
    
    if (new_jobqueue == NULL){
        
        return NULL;
    }
    
    pri_jobqueue_init(new_jobqueue);
    
    return new_jobqueue;
}

/* 
 * TODO: you must implement this function.
 */
void pri_jobqueue_init(pri_jobqueue_t* pjq) {
    
    if (pjq!= NULL){
        pjq->buf_size = JOB_BUFFER_SIZE;
        pjq->size = 0;
        for (int i = 0; i < JOB_BUFFER_SIZE; i++) {
            job_init(&pjq->jobs[i]);
        }
    }
    else{
        return;
    }
}

/* 
 * TODO: you must implement this function.
 * Hint:
 *      - if a queue is not empty, and the highest priority job is not in the 
 *      last used slot on the queue, dequeueing a job will result in the 
 *      jobs on the queue having to be re-arranged
 *      - remember that the job returned by this function is a copy of the job
 *      that was on the queue
 */
job_t* pri_jobqueue_dequeue(pri_jobqueue_t* pjq, job_t* dst) {
    
    if (!pri_jobqueue_is_empty(pjq)){
        
        if (pjq != NULL){
            
            job_t* highest = &pjq->jobs[pjq->size - 1];
            dst = job_copy(highest, dst);
            
            job_init(highest);
            
            pjq->size --;
            
            return dst;
        }
    }
    
    return NULL;
}

/* 
 * TODO: you must implement this function.
 * Hints:
 * - if a queue is not full, and if you decide to store the jobs in 
 *      priority order on the queue, enqueuing a job will result in the jobs 
 *      on the queue having to be re-arranged. However, it is not essential to
 *      store jobs in priority order (it simplifies implementation of dequeue
 *      at the expense of extra work in enqueue). It is your choice how 
 *      you implement dequeue (and enqueue) to ensure that jobs are dequeued
 *      by highest priority job first (see pri_jobqueue.h)
 * - remember that the job passed to this function is copied to the 
 *      queue
 */
void pri_jobqueue_enqueue(pri_jobqueue_t* pjq, job_t* job) {
    
    if (job == NULL || pjq == NULL || job->priority <= 0){
        
        return;
        
    }
    
    if (!pri_jobqueue_is_full(pjq)){
        
        int insert = 0;
        for (int i = 0; i < pjq->size; i++){
            if (job->priority <= pjq->jobs[i].priority){
                insert = 0;
                break;
            }
        }
        
        for (int h = pjq->size; h> insert; h--){
            
            job_copy(&pjq->jobs[h-1], &pjq->jobs[h]);
        }
        
        job_copy(job, &pjq->jobs[insert]);
        
        pjq->size++;
    }
        
    job_t sort_job;
        
    for (int i = 0; i < pjq->size; i++){
            
        for(int h = i + 1; h < pjq->size; h++){
                
            if(pjq->jobs[i].priority < pjq->jobs[h].priority){
                job_copy(&pjq->jobs[i], &sort_job);
                job_copy(&pjq->jobs[h], &pjq->jobs[i]);
                job_copy(&sort_job, &pjq->jobs[h]);
            }
        }
    }
}
   
/* 
 * TODO: you must implement this function.
 */
bool pri_jobqueue_is_empty(pri_jobqueue_t* pjq) {
    
    if (pjq == NULL){
        return true;
    }
    
    if (pjq->size == 0){
        return true;
    }
    
    else{
        return false;
    }
}

/* 
 * TODO: you must implement this function.
 */
bool pri_jobqueue_is_full(pri_jobqueue_t* pjq) {
    
        
    if (pjq == NULL){
        return true;
    }
    
    if (pjq->size == JOB_BUFFER_SIZE){
        return true;
    }
    
    else{
        return false;
    }
    
}

/* 
 * TODO: you must implement this function.
 * Hints:
 *      - remember that the job returned by this function is a copy of the 
 *      highest priority job on the queue.
 *      - both pri_jobqueue_peek and pri_jobqueue_dequeue require copying of 
 *      the highest priority job on the queue
 */
job_t* pri_jobqueue_peek(pri_jobqueue_t* pjq, job_t* dst) {
    
    if (pjq == NULL || pri_jobqueue_is_empty(pjq)){
        return NULL;
    }
    
    job_t* highest = &pjq->jobs[pjq->size - 1];
    dst = job_copy(highest, dst);
    
    return dst;
    
}

/* 
 * TODO: you must implement this function.
 */
int pri_jobqueue_size(pri_jobqueue_t* pjq) {
    
    if (pjq == NULL || pjq->size < 0){
        return 0;
    }
    
    else{
        return pjq->size;
    }
}

/* 
 * TODO: you must implement this function.
 */
int pri_jobqueue_space(pri_jobqueue_t* pjq) {
    
    if (pjq == NULL || pjq->size < 0){
        return 0;
    }
    else{
        return JOB_BUFFER_SIZE - pjq->size;
    }
}

/* 
 * TODO: you must implement this function.
 *  Hint:
 *      - see pri_jobqeue_new
 */
void pri_jobqueue_delete(pri_jobqueue_t* pjq) {
    
    if (pjq !=NULL){
        free(pjq);
    }
}

