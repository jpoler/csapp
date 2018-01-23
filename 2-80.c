#include <stdio.h>
#include <limits.h>

#include "show_bytes.h"

int threefourths(int x) {
    int saved = x & 3;
    int div = x >> 2;
    (x & (1 << (sizeof(int)* 8 - 1))) && (saved = -saved , div = (x + 3) >> 2);
    return ((div << 1) + div) + (((saved << 1) + saved) >> 2);
}


int main(int argc, char **argv) {
    int res = threefourths(-15);
    printf("result: %d\n", res);
    show_int(res);
}
