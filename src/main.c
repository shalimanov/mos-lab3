#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "memory_test.h"
#include "matrix_multiplication.h"
#include "shared_memory_access.h"
#include "cache_miss_test.h"
#include "cache_latency_test.h"
#include "utils.h"

int main(int argc, char* argv[]) {
    if (argc < 4) {
        log_error("Usage: ./main <test_method> <param1> <param2>");
        return -1;
    }

    const char* test_method = argv[1];
    int param1 = atoi(argv[2]);
    int param2 = atoi(argv[3]);

    log_info("Starting test with parameters:");
    printf("Method: %s, Param1: %d, Param2: %d\n", test_method, param1, param2);

    int result = 0;
    if (strcmp(test_method, "memory_test") == 0) {
        result = perform_memory_test(param1, param2);
    } else if (strcmp(test_method, "matrix_multiplication") == 0) {
        perform_matrix_multiplication(param1);
    } else if (strcmp(test_method, "shared_memory_access") == 0) {
        perform_shared_memory_access(param1, param2);
    } else if (strcmp(test_method, "cache_miss_test") == 0) {
        perform_cache_miss_test(param1);
    } else if (strcmp(test_method, "cache_latency_test") == 0) {
        perform_cache_latency_test(param1);
    } else {
        log_error("Unknown test method.");
        return -1;
    }

    if (result == 0) {
        log_info("Test completed successfully.");
    } else {
        log_error("Test failed with errors.");
    }

    return result;
}
