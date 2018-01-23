#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include <math.h>

#include "show_bytes.h"

typedef unsigned float_bits;

float_bits float_twice(float_bits f) {
    int sign = f >> 31;
    int exp = (f >> 23) & 0xFF;
    int frac = f & 0x7FFFFF;

    if (!(exp ^ 0xFF) && !frac) {
        // INF
        return f;
    } else if (!(exp ^ 0xFF) && frac) {
        // NaN
        // This one is weird because the book says just return f, but c does
        // best effort to increase the number, choosing the highest frac bit
        // that isn't on.
        if (!(frac & (1 << 22))) {
            frac = frac | (1 << 22);
        }
    } else if (!exp && !frac) {
        // 0
        return f;
    } else if (!exp && frac && !(frac & (1 << 22))) {
        // denormalized, shift frac because it has room to shift.
        frac <<= 1;
    } else if (!exp && frac && (frac & (1 << 22))) {
        // denormalized, top bit in frac is on so shift AND add to exp.
        frac <<= 1;
        exp += 1;
    } else if (exp + 1 == 0xFF) {
        // "overflow" to inf.
        frac = 0;
        exp += 1;
    /* } else if (exp + 1 == 0xFF) { */
    /*     // would overflow, so instead shift frac because there is room. */
    /*     frac <<= 1; */
    } else {
        exp += 1;
    }

    return (sign << 31) | (exp << 23) | frac;
}


int main(int argc, char **argv) {
    unsigned i;
    float_bits res, target;
    float f;
    for (i = 0; i < UINT_MAX; i++) {
        res = float_twice((float_bits) i);
        f = float_bits_to_float((float_bits) i);
        f = 2*f;
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
