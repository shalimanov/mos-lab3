#include <pthread.h>
#include <stdio.h>
#include <stdatomic.h>
#include "memory_test.h"
#include "utils.h"

static atomic_int shared_data = 0;

void* increment_shared_data(void* arg) {
    int iterations = *(int*)arg;
    for (int i = 0; i < iterations; i++) {
        atomic_fetch_add(&shared_data, 1);
    }
    return NULL;
}

int perform_memory_test(int num_threads, int num_iterations) {
    pthread_t threads[num_threads];
    shared_data = 0;

    struct timespec start;
    start_timer(&start);

    for (int i = 0; i < num_threads; i++) {
        if (pthread_create(&threads[i], NULL, increment_shared_data, &num_iterations) != 0) {
            log_error("Failed to create thread.");
            return -1;
        }
    }

    for (int i = 0; i < num_threads; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            log_error("Failed to join thread.");
            return -1;
        }
    }

    log_info("Final shared data value:");
    printf("%d\n", shared_data);

    log_execution_time(&start);

    return 0;
}
