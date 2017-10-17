//
//  threadexample.c
//  lecturenotes'
//
//  Created by Chelsea Benony on 7/13/17.
//  Copyright © 2017 Chelsea Benony. All rights reserved.
//
/*
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void* howdy(void* vargp);

int main(){
    pthread_t tid;
    int s;
    s = pthread_create(&tid, NULL, howdy, NULL);
    pthread_join(tid, NULL);
    exit(0);
}
void* howdy(void* vargp){
    printf("Hello World!\n");
    return NULL;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    
    printf("Hello World! \n");
}
