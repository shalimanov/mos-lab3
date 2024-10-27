#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "matrix_multiplication.h"
#include "utils.h"

// Функція для створення матриці розміром size x size
int** create_matrix(int size) {
    int** matrix = (int**)malloc(size * sizeof(int*));
    for (int i = 0; i < size; i++) {
        matrix[i] = (int*)malloc(size * sizeof(int));
    }
    return matrix;
}

// Функція для заповнення матриці випадковими значеннями
void fill_matrix(int** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

// Послідовне множення матриць для ефективного кешування
void sequential_multiply(int** matA, int** matB, int** result, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}

// Випадковий порядок множення матриць для демонстрації кеш-промахів
void random_multiply(int** matA, int** matB, int** result, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[j][i] = 0;
            for (int k = 0; k < size; k++) {
                result[j][i] += matA[k][j] * matB[i][k];
            }
        }
    }
}

// Основна функція для виконання множення і логування результатів
void perform_matrix_multiplication(int size) {
    int** matA = create_matrix(size);
    int** matB = create_matrix(size);
    int** result = create_matrix(size);

    fill_matrix(matA, size);
    fill_matrix(matB, size);

    struct timespec start;
    
    log_info("Starting sequential matrix multiplication...");
    start_timer(&start);
    sequential_multiply(matA, matB, result, size);
    log_execution_time(&start);

    log_info("Starting random access matrix multiplication...");
    start_timer(&start);
    random_multiply(matA, matB, result, size);
    log_execution_time(&start);

    // Очищення пам'яті
    for (int i = 0; i < size; i++) {
        free(matA[i]);
        free(matB[i]);
        free(result[i]);
    }
    free(matA);
    free(matB);
    free(result);
}
