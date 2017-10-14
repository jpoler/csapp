#include <stdio.h>
#include <limits.h>

#include "show_bytes.h"

long take_least_significant_byte(long x, long y) {
    printf("x: %ld\n", (x & 0xFF));
    return (x & 0xFF) | (long)(((unsigned long) y >> 8) << 8);
}

int main(int argc, char **argv) {
    long first = -1;
    long second = 0xDEADBEEFDEADBEEF;
    show_long(first);
    show_long(second);
    long res = take_least_significant_byte(first, second);
    show_long(res);
}
