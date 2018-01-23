
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include <math.h>

#include "show_bytes.h"

typedef unsigned float_bits;

float_bits float_negate(float_bits f) {
    unsigned sign = f >> 31;
    unsigned exp = f >> 23 & 0xFF;
    unsigned frac = f & 0x7FFFFF;

    if ((! exp ^ 0xFF) && frac) {
        return f;
    }

    return ((~sign & 0x1) << 31) | (exp << 23) | frac;
}

int main(int argc, char **argv) {
    unsigned i;
    float_bits res, target;
    float f;
    for (i = 2139165121; i <= UINT_MAX; i++) {
        res = float_negate((float_bits) i);
        f = float_bits_to_float((float_bits) i);
        /* printf("f before negation: %.64f\n", f); */
        /* show_bytes((byte_pointer) &f, sizeof(float)); */
        f = -f;
        target = float_to_float_bits(f);
        // c allows nan to be negated, so this will never pass for everything
        // based on the spec in the book.
        if (target != res) {
            printf("invalid result! (i = %d)\n", i);
            show_bytes((byte_pointer) &i, sizeof(unsigned));
            show_bytes((byte_pointer) &res, sizeof(float_bits));
            show_bytes((byte_pointer) &target, sizeof(float_bits));
            /* exit(1); */
        }
    }
}
