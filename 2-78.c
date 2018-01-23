#include <stdio.h>
#include <limits.h>

#include "show_bytes.h"

int signed_high_product(int x, int y);

int divide_power2(int x, int k) {
    int res = x >> k;
    x & (1 << (sizeof(x)*8 - 1)) && (res = (x + (1 << k) -1) >> k);
    return res;
}

int main(int argc, char **argv) {
    int res = divide_power2(-7, 1);
    show_int(res);
}
