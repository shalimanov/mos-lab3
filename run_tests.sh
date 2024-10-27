#!/bin/bash

make clean && make

TEST_METHODS=("memory_test" "matrix_multiplication" "shared_memory_access" "cache_miss_test" "cache_latency_test")
THREAD_COUNTS=(2 4 8)
ITERATION_COUNTS=(100000 500000 1000000)
MATRIX_SIZES=(100 200 500)
ARRAY_SIZES=(1000000 5000000 10000000)

echo "---"
echo "Start testing..."

for METHOD in "${TEST_METHODS[@]}"; do
  if [ "$METHOD" == "memory_test" ]; then
    for THREADS in "${THREAD_COUNTS[@]}"; do
      for ITERATIONS in "${ITERATION_COUNTS[@]}"; do
        echo "Testing $METHOD with THREADS=$THREADS, ITERATIONS=$ITERATIONS"
        ./main $METHOD $THREADS $ITERATIONS
        echo "---"
      done
    done
  elif [ "$METHOD" == "matrix_multiplication" ]; then
    for SIZE in "${MATRIX_SIZES[@]}"; do
      echo "Testing $METHOD with MATRIX_SIZE=$SIZE"
      ./main $METHOD $SIZE 0
      echo "---"
    done
  elif [ "$METHOD" == "shared_memory_access" ]; then
    for THREADS in "${THREAD_COUNTS[@]}"; do
      for ITERATIONS in "${ITERATION_COUNTS[@]}"; do
        echo "Testing $METHOD with THREADS=$THREADS, ITERATIONS=$ITERATIONS"
        ./main $METHOD $THREADS $ITERATIONS
        echo "---"
      done
    done
  elif [ "$METHOD" == "cache_miss_test" ]; then
    for ARRAY_SIZE in "${ARRAY_SIZES[@]}"; do
      echo "Testing $METHOD with ARRAY_SIZE=$ARRAY_SIZE"
      ./main $METHOD $ARRAY_SIZE 0
      echo "---"
    done
  elif [ "$METHOD" == "cache_latency_test" ]; then
    for ARRAY_SIZE in "${ARRAY_SIZES[@]}"; do
      echo "Testing $METHOD with ARRAY_SIZE=$ARRAY_SIZE"
      ./main $METHOD $ARRAY_SIZE 0
      echo "---"
    done
  fi
done

echo "Testing has been finished."
echo "---"
