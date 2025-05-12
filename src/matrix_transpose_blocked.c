
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 512
#define BLOCK_SIZE 32
int A[N][N];
int B[N][N];

void transpose_blocked(int src[N][N], int dst[N][N]) {
    for (int i = 0; i < N; i += BLOCK_SIZE) {
        for (int j = 0; j < N; j += BLOCK_SIZE) {
            for (int ii = i; ii < i + BLOCK_SIZE && ii < N; ++ii) {
                for (int jj = j; jj < j + BLOCK_SIZE && jj < N; ++jj) {
                    dst[jj][ii] = src[ii][jj];
                }
            }
        }
    }
}

int main() {
    srand(time(NULL));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            A[i][j] = rand() % 100;

    clock_t start = clock();
    transpose_blocked(A, B);
    clock_t end = clock();

    double time_ms = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    printf("Blocked transpose of %dx%d matrix took %.3f ms\n", N, N, time_ms);

    return 0;
}
