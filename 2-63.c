#include <stdio.h>
#include <limits.h>

#include "show_bytes.h"

unsigned srl(unsigned x, int k) {
    unsigned xsra = (int) x >> k;
    unsigned w = sizeof(int) * 8;
    int mask = (1 << k) - 1;
    mask <<= w - k;
    return xsra & ~mask;
}

int sra(int x, int k) {
    int xsrl = (unsigned) x >> k;
    unsigned w = sizeof(int) * 8;
    int mask = (1 << k) - 1;
    int top_bit = xsrl & (1 << (w - k - 1));
    mask *= (top_bit << 1);
    return xsrl | mask;
}

int main(int argc, char **argv) {
    unsigned srl_res = srl(0xFFFFFFFF, 2);
    show_bytes((byte_pointer) &srl_res, sizeof(srl_res));


    unsigned sra_res = sra(0x80000000, 0);
    show_bytes((byte_pointer) &sra_res, sizeof(sra_res));
}
