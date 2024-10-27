#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdatomic.h>
#include "shared_memory_access.h"
#include "utils.h"

static int shared_data_no_sync = 0;
static volatile int shared_data_volatile = 0;
static atomic_int shared_data_atomic = 0;

void* increment_no_sync(void* arg) {
    int iterations = *(int*)arg;
    for (int i = 0; i < iterations; i++) {
        shared_data_no_sync++;
    }
    return NULL;
}

void* increment_volatile(void* arg) {
    int iterations = *(int*)arg;
    for (int i = 0; i < iterations; i++) {
        shared_data_volatile++;
    }
    return NULL;
}

void* increment_atomic(void* arg) {
    int iterations = *(int*)arg;
    for (int i = 0; i < iterations; i++) {
        atomic_fetch_add(&shared_data_atomic, 1);
    }
    return NULL;
}

void perform_shared_memory_access(int num_threads, int num_iterations) {
    pthread_t threads[num_threads];
    struct timespec start;

    // Без синхронізації
    log_info("Starting no sync access...");
    shared_data_no_sync = 0;
    start_timer(&start);
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, increment_no_sync, &num_iterations);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    log_execution_time(&start);
    printf("Final value without sync: %d\n", shared_data_no_sync);

    // Використання volatile
    log_info("Starting volatile access...");
    shared_data_volatile = 0;
    start_timer(&start);
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, increment_volatile, &num_iterations);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    log_execution_time(&start);
    printf("Final value with volatile: %d\n", shared_data_volatile);

    // Використання atomic
    log_info("Starting atomic access...");
    atomic_store(&shared_data_atomic, 0);
    start_timer(&start);
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, increment_atomic, &num_iterations);
    }
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    log_execution_time(&start);
    printf("Final value with atomic: %d\n", shared_data_atomic);
}
