#include <stdio.h>
#include <stdint.h>
#include <limits.h>

int tmult_ok(int x, int y) {
    int64_t pll = (int64_t) x * y;
    return pll == (int) pll;
}

int main(int argc, char** argv) {
    int x = INT_MAX, y = INT_MAX;
    printf("x: %x, y: %x, ok: %d\n", x, y , tmult_ok(x, y));
    printf("arith: %d \n", 0xFFFFFFFF >> 20);
}
