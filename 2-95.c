#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include <math.h>

#include "show_bytes.h"

typedef unsigned float_bits;

float_bits float_half(float_bits f) {
    int sign = f >> 31;
    int exp = (f >> 23) & 0xFF;
    int frac = f & 0x7FFFFF;
    int up, down;

    if (!(exp ^ 0xFF)) {
        // INF or NaN
        if (frac) {
            frac |= (1 << 22);
        }
    } else if (!exp && !frac) {
        // 0
        return f;
    } else if (exp != 1 && exp != 0) {
        exp -= 1;
    } else if (exp == 1 && frac == 0x7FFFFF) {
        exp = 1;
        frac = 0;
    } else {
        if (~frac & 1) {
            frac >>= 1;
        } else {
            up = (frac + 1) >> 1;
            down = (frac - 1) >> 1;
            frac = (~up & 1) ? up : down;
        }
        if (exp == 1) {
            frac |= (1 << 22);
        }
        exp = 0;
    }

    return (sign << 31) | (exp << 23) | frac;
}


int main(int argc, char **argv) {
    /* float x = NAN; */
    /* show_bytes((byte_pointer) &x, sizeof(x)); */
    unsigned i;
    float_bits res, target;
    float f;
    for (i = 0; i < UINT_MAX; i++) {
        res = float_half((float_bits) i);
        f = float_bits_to_float((float_bits) i);
        f = f/(float)2;
        target = float_to_float_bits(f);
        if (target != res) {
            printf("invalid result! (i = %u)\n", i);
            show_bytes((byte_pointer) &i, sizeof(unsigned));
            show_bytes((byte_pointer) &res, sizeof(float_bits));
            show_bytes((byte_pointer) &target, sizeof(float_bits));
            exit(1);
        }
    }
}
