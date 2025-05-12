
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE (64 * 1024)  // 64KB
#define ACCESS_COUNT 100000

int main() {
    int *array = malloc(ARRAY_SIZE);
    volatile int sum = 0;
    clock_t start, end;

    printf("Lines	Time (ms)\n");
    for (int lines = 1; lines <= 16; lines++) {
        start = clock();
        for (int rep = 0; rep < ACCESS_COUNT; rep++) {
            for (int i = 0; i < lines; i++) {
                sum += array[i * 4096]; // 4KB spacing
            }
        }
        end = clock();
        double time_ms = 1000.0 * (end - start) / CLOCKS_PER_SEC;
        printf("%d\t%.3f\n", lines, time_ms);
    }

    free(array);
    return sum;
}
