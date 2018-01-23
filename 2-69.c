#include <stdio.h>
#include <limits.h>

#include "show_bytes.h"

unsigned rotate_left(unsigned x, int n) {
    unsigned mask = (x << n) | (x >> (WORD_BIT - n));
    return mask;
}


int main(int argc, char **argv) {
    unsigned res = rotate_left(0x12345678, 0);
    show_bytes((byte_pointer) &res, sizeof(res));
    res = rotate_left(0x12345678, 4);
    show_bytes((byte_pointer) &res, sizeof(res));
}
