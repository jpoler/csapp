#include <stdio.h>
#include <limits.h>

int uadd_ok(unsigned x, unsigned y) {
    printf("x: %x, y: %x, x+y: %x\n", x, y, x+y);
    return (x+y) > x;
}

int main(int argc, char** argv) {
    printf("ok: %d\n", uadd_ok((UINT_MAX/2), (UINT_MAX/2)+1));
}
