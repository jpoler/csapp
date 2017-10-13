#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int div16(int x) {
    int bias = (x >> 31) & 0xf;
    return (x+bias) >> 4;
}

int main(int argc, char** argv) {
    int x = INT_MAX;
    printf("x: %08X, div16: %08X\n", x, div16(x));
}
