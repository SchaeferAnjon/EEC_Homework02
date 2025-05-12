
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 512
int A[N][N];
int B[N][N];

void transpose(int src[N][N], int dst[N][N]) {
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dst[j][i] = src[i][j];
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            A[i][j] = rand() % 100;

    clock_t start = clock();
    transpose(A, B);
    clock_t end = clock();

    double time_ms = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    printf("Transpose of %dx%d matrix took %.3f ms\n", N, N, time_ms);

    return 0;
}
