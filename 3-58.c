#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ITERATIONS 1000

long decode3(long x, long y, long z);

long decode2(long x, long y, long z) {
    long sub = y - z;
    long mul = x*sub;
    long mask = sub & 1L;
    return mul & mask;
}

int main(int arg, char **argv) {
    long  i, x, y, z, res;

    double start_time, end_time, total = 0;

    srand(time(NULL));

    for (i = 0; i < ITERATIONS; i++) {
        x = rand(); y = rand(); z = rand();
        start_time = (double) clock();
        res = decode2(x, y, z);
        end_time = (double) clock();

        total += end_time - start_time;
    }

    printf("total time: %lf, average time: %lf\nCLOCKS_PER_SECOND: %d\n", total, total/ITERATIONS, CLOCKS_PER_SEC);

    total = 0;

    for (i = 0; i < ITERATIONS; i++) {
        x = rand(); y = rand(); z = rand();
        start_time = (double) clock();
        res = decode3(x, y, z);
        end_time = (double) clock();

        total += end_time - start_time;
    }

    printf("total time: %lf, average time: %lf\nCLOCKS_PER_SECOND: %d\n", total, total/ITERATIONS, CLOCKS_PER_SEC);
}
