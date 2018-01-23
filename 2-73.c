#include <stdio.h>
#include <limits.h>

#include "show_bytes.h"

int saturating_add(int x, int y) {

    int ret = x + y;
    printf("ret: %d\n", ret);
    (1 << (sizeof(int)*8 - 1)) & (ret & ((x & y) << 1)) && (ret = INT_MAX);
    (1 << (sizeof(int)*8 - 1)) & (~ret & (x & y)) && (ret = INT_MIN);
    return ret;
}

int main(int argc, char **argv) {
    printf("result: %d\n", saturating_add(INT_MIN + 2, INT_MIN + 1));
}
