#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ARRAY_SIZE 1024 * 1024

int main() {
    char *array = (char *)malloc(ARRAY_SIZE);
    clock_t start, end;

    // Write access
    start = clock();
    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = i % 256;
    }
    end = clock();
    double write_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;

    // Read access
    volatile int sum = 0;
    start = clock();
    for (int i = 0; i < ARRAY_SIZE; i++) {
        sum += array[i];
    }
    end = clock();
    double read_time = 1000.0 * (end - start) / CLOCKS_PER_SEC;

    printf("Write Time: %.3f ms\n", write_time);
    printf("Read Time: %.3f ms\n", read_time);

    free(array);
    return sum;
}
