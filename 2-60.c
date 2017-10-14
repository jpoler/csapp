#include <stdio.h>
#include <limits.h>

#include "show_bytes.h"

unsigned replace_byte(unsigned x, int i, unsigned char b) {
    if (0 < i || i > sizeof(unsigned)) {
        return x;
    }
    x &= (0x00 << i);
    x |= ((unsigned) b << i);

    return x;
}

int main(int argc, char **argv) {
    unsigned x = 0x12AB5678;

    printf("result: %x\n", replace_byte(x, 2, 0xAB));
}
