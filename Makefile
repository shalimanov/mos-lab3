CC = gcc
CFLAGS = -Wall -pthread
TARGET = main

SRC_DIR = src
OBJ_DIR = obj

SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/memory_test.c $(SRC_DIR)/matrix_multiplication.c $(SRC_DIR)/shared_memory_access.c $(SRC_DIR)/cache_miss_test.c $(SRC_DIR)/cache_latency_test.c $(SRC_DIR)/utils.c
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/memory_test.o $(OBJ_DIR)/matrix_multiplication.o $(OBJ_DIR)/shared_memory_access.o $(SRC_DIR)/cache_miss_test.o $(SRC_DIR)/cache_latency_test.o $(OBJ_DIR)/utils.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -f $(TARGET) $(OBJ_DIR)/*.o
	rm -rf $(OBJ_DIR)

.PHONY: all clean
