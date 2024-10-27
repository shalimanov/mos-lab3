#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "cache_miss_test.h"
#include "utils.h"

void sequential_access(int* array, int size) {
    long sum = 0;
    for (int i = 0; i < size; i++) {
        sum += array[i];
    }
    printf("Sequential access sum: %ld\n", sum);
}

void random_access(int* array, int size) {
    long sum = 0;
    for (int i = 0; i < size; i++) {
        int index = rand() % size;
        sum += array[index];
    }
    printf("Random access sum: %ld\n", sum);
}

void perform_cache_miss_test(int array_size) {
    int* array = create_large_array(array_size);
    struct timespec start;

    log_info("Starting sequential memory access...");
    start_timer(&start);
    sequential_access(array, array_size);
    log_execution_time(&start);

    log_info("Starting random memory access...");
    start_timer(&start);
    random_access(array, array_size);
    log_execution_time(&start);

    free(array);
}
