#include <stdio.h>
#include <time.h>

long long get_milliseconds() {
    struct timespec ts;
    // CLOCK_MONOTONIC is preferred for measuring intervals
    clock_gettime(CLOCK_MONOTONIC, &ts);
    
    // Convert seconds to ms and add nanoseconds converted to ms
    return (long long)ts.tv_sec * 1000 + (long long)ts.tv_nsec / 1000000;
}

int main() {
    printf("Current timestamp: %lld ms\n", get_milliseconds());
    return 0;
}