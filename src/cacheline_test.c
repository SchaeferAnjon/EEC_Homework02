
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE (1024 * 1024)
int array[ARRAY_SIZE];

int main() {
    volatile int sum = 0;
    clock_t start, end;

    printf("Stride\tTime (ms)\n");
    for (int stride = 1; stride <= 1024; stride *= 2) {
        start = clock();
        for (int i = 0; i < ARRAY_SIZE; i += stride) {
            sum += array[i];
        }
        end = clock();
        double time_ms = 1000.0 * (end - start) / CLOCKS_PER_SEC;
        printf("%d\t%.3f\n", stride * sizeof(int), time_ms);
    }

    return sum;
}
