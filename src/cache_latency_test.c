#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "cache_latency_test.h"
#include "utils.h"

void induce_cache_latency(int* array, int size) {
    long sum = 0;
    for (int i = 0; i < size; i++) {
        array[i] = array[i] + 1;
        sum += array[i];
    }
    printf("Sum after inducing latency: %ld\n", sum);
}

void perform_cache_latency_test(int array_size) {
    int* array = create_large_array(array_size);
    struct timespec start;

    log_info("Starting cache latency test...");
    start_timer(&start);
    induce_cache_latency(array, array_size);
    log_execution_time(&start);

    free(array);
}
