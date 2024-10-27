#ifndef UTILS_H
#define UTILS_H

#include <time.h>

void log_info(const char* message);
void log_error(const char* message);
void start_timer(struct timespec* start);
double end_timer(struct timespec* start);
void log_execution_time(struct timespec* start);
int* create_large_array(int size);

#endif // UTILS_H
