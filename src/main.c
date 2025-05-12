extern int associativity_test_main();
extern int matrix_transpose_main();
extern int cacheline_test_main();
extern int writeback_test_main();

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [test_name]\n", argv[0]);
        printf("Available tests: associativity, matrix, cacheline, writeback\n");
        return 1;
    }
    
    if (strcmp(argv[1], "associativity") == 0) {
        return associativity_test_main();
    } else if (strcmp(argv[1], "matrix") == 0) {
        return matrix_transpose_main();
    } else if (strcmp(argv[1], "cacheline") == 0) {
        return cacheline_test_main();
    } else if (strcmp(argv[1], "writeback") == 0) {
        return writeback_test_main();
    } else {
        printf("Unknown test: %s\n", argv[1]);
        return 1;
    }
}