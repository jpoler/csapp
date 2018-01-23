#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include <math.h>

#include "show_bytes.h"

typedef unsigned float_bits;

float_bits float_absval(float_bits f) {
    return f & 0x7FFFFFFF;
}

int main(int argc, char **argv) {
    unsigned i;
    float_bits res, target;
    float f;
    for (i = 0; i < UINT_MAX; i++) {
        res = float_absval((float_bits) i);
        f = float_bits_to_float((float_bits) i);
        /* printf("f before negation: %.64f\n", f); */
        /* show_bytes((byte_pointer) &f, sizeof(float)); */
        f = fabsf(f);
        target = float_to_float_bits(f);
        // c allows nan to be negated, so this will never pass for everything
        // based on the spec in the book.
        if (target != res) {
            printf("invalid result! (i = %u)\n", i);
            show_bytes((byte_pointer) &i, sizeof(unsigned));
            show_bytes((byte_pointer) &res, sizeof(float_bits));
            show_bytes((byte_pointer) &target, sizeof(float_bits));
            /* exit(1); */
        }
    }
}
