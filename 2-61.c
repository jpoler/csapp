#include <stdio.h>
#include <limits.h>

#include "show_bytes.h"

int any_1(int x) {
    if (x) {
        return 1;
    }
    return 0;
}

int any_0(int x) {
    if (~x) {
        return 1;
    }
    return 0;
}

int lsb_any_1(int x) {
    return any_1(x & 0xFF);
}

int msb_any_0(int x) {
    unsigned shift_amount = (sizeof(int) - 1) << 3;
    show_bytes((byte_pointer) &shift_amount, sizeof(shift_amount));
    int res = x >> (int)shift_amount;
    if (~res) {
        return 1;
    }
    return 0;
}

int main(int argc, char **argv) {
    printf("any res: %d\n", any_1(0xDEADBEEF));
    printf("any res: %d\n", any_1(0x0));
    printf("any_0 res: %d\n", any_0(-2));
    printf("any_0 res: %d\n", any_0(-1));
    printf("lsb_any_1: %d\n", lsb_any_1(0x0));
    printf("lsb_any_1: %d\n", lsb_any_1(0x80));
    printf("msb_any_0: %d\n", msb_any_0(0xFFFFFFFF));
    printf("msb_any_0: %d\n", msb_any_0(0xBFFFFFFF));
}
