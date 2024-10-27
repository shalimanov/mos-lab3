#include <stdio.h>
#include <time.h>
#include "utils.h"
#include <stdlib.h>

void log_info(const char* message) {
    printf("[INFO]: %s\n", message);
}

void log_error(const char* message) {
    printf("[ERROR]: %s\n", message);
}

void start_timer(struct timespec* start) {
    clock_gettime(CLOCK_MONOTONIC, start);
}

double end_timer(struct timespec* start) {
    struct timespec end;
    clock_gettime(CLOCK_MONOTONIC, &end);
    return (end.tv_sec - start->tv_sec) + (end.tv_nsec - start->tv_nsec) / 1e9;
}


void log_execution_time(struct timespec* start) {
    double elapsed_time = end_timer(start);
    printf("[INFO]: Execution time: %.5f seconds\n", elapsed_time);
}

int* create_large_array(int size) {
    int* array = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++) {
        array[i] = i;
    }
    return array;
}