#include <stdio.h>
#include <limits.h>

#include "show_bytes.h"

int any_odd_one(unsigned x) {
    return (x & 0x55555555) != 0;
}

int main(int argc, char **argv) {
    int res = any_odd_one(0x8);
    printf("result: %d\n", res);
}
