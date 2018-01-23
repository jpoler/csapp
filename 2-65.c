#include <stdio.h>
#include <limits.h>

#include "show_bytes.h"

int odd_ones(unsigned x) {
    x ^= x >> 16;
    show_bytes((byte_pointer) &x, sizeof(x));
    x ^= x >> 8;
    show_bytes((byte_pointer) &x, sizeof(x));
    x ^= x >> 4;
    show_bytes((byte_pointer) &x, sizeof(x));
    x ^= x >> 2;
    show_bytes((byte_pointer) &x, sizeof(x));
    x ^= x >> 1;
    show_bytes((byte_pointer) &x, sizeof(x));

    return x & 1U;
}


int main(int argc, char **argv) {
    int res = odd_ones(0xFF17F1FF);
    printf("result: %d\n", res);
}
