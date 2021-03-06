#include <stdio.h>
#include <limits.h>

#include "show_bytes.h"

int leftmost_one(unsigned x) {

    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return x - (x >> 1);
}


int main(int argc, char **argv) {
    int res = leftmost_one(0x7F17F1FF);
    show_int(res);
    /* printf("result: %d\n", res); */
}
