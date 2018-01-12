//
//  main.c
//  finalexampractice
//
//  Created by Chelsea Benony on 7/26/17.
//  Copyright © 2017 Chelsea Benony. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ROWS 100
#define COLS 100
#define MAX 32

pthread_mutex_t mutex_matrix;
pthread_cond_t cv_matrix;
int count = 0, sum = 0;

void* create_stuff();
void* destroy_stuff();

int main(int argc, const char * argv[]) {
    int *array = malloc(ROWS*COLS*sizeof(int));
    create_stuff();
    pthread_t thread[ROWS];
    for (int i = 0; i < ROWS; i++){
        pthread_create(&thread[i], NULL, matrix_sum((void*)i), NULL);
    }
    destroy_stuff();
    for (int i = 0; i < ROWS; i++){
        pthread_join(thread[i], NULL);
    }
   
    return 0;
}
void* creates_tuff(){
    pthread_mutex_init(&mutex_matrix, NULL);
    pthread_cond_init(&cv_matrix, NULL);
    
}
void* destroy_stuff(){
    pthread_mutex_destroy(&mutex_matrix);
    pthread_cond_destroy(&cv_matrix);
}
void* matrix_sum(void* arg){
    pthread_mutex_lock(&mutex_matrix);
    
    if (count >= MAX)
        pthread_cond_wait(&cv_matrix, &mutex_matrix);
    count++;
    pthread_mutex_unlock(&mutex_matrix);
    int row_sum = 0;
    for (int i = 0; i < ROWS; i++){
        rows_sum +=
    }
}
