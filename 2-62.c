#include <stdio.h>
#include <limits.h>

#include "show_bytes.h"

int int_shifts_are_arithmetic() {
    int x = INT_MIN;
    x >>= 1;
    show_int(x);
    int res = x & ~(1 << (sizeof(int)*8 - 2));
    show_int(res);
    if (res) {
        return 1;
    }
    return 0;
}

int main(int argc, char **argv) {
    printf("arith: %d\n", int_shifts_are_arithmetic());
}
