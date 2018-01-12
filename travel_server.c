//
//  travel_server.c
//  Assignment2-3
//
//  Created by Chelsea Benony on 7/28/17.
//  Copyright © 2017 Chelsea Benony. All rights reserved.
//

#include <stdio.h>
#define _GNU_SOURCE

#include <assert.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "hashmap.h"

//Synchronize access to flight_map
pthread_mutex_t flight_map_mutex;

/// @brief contains socket information
/// includes file descriptor port pair.
typedef struct {
    int fd;
    int port;
    char * ip_address;
    int enabled;
    map_t * map;
} socket_info;

void add_flight(map_t flight_map, char * flight_token, char * seats_token) {
    // assign persistent memory for hash node
    char * flight = malloc(sizeof(char) * strlen(flight_token) + 1);
    char * seats = malloc(sizeof(char) * strlen(seats_token) + 1);
    
    // TODO: free memory in request on server thread
    
    // copy temp strings into memory
    strcpy(flight, flight_token);
    strcpy(seats, seats_token);
    
    // acquire lock to flight_map
    pthread_mutex_lock(&flight_map_mutex);
    assert(hashmap_put(flight_map, flight, seats) == MAP_OK);
    pthread_mutex_unlock(&flight_map_mutex);
    
    printf("server: reserving %s seats on flight %s\n", seats, flight);
} // add_flight

int main(int argc, char* argv[]){
    
    char * ip_address = argv[1];
    int start_port = atoi(argv[2]);
    int no_ports = atoi(argv[3]);
    char * in_filename = argv[4];
    char * out_filename = argv[5];
    

   return 0;
}
