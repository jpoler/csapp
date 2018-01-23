#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include <math.h>

#include "show_bytes.h"

#define NOT_CONVERTABLE 0x80000000

typedef unsigned float_bits;

int float_f2i(float_bits f) {
    int sign = f >> 31;
    int exp = (f >> 23) & 0xFF;
    int frac = f & 0x7FFFFF;
    int bias = 127;

    if (exp - bias < 0) {
        return 0;
    } else if (exp - bias > 30) {
        return NOT_CONVERTABLE;
    }

    frac |= (1 << 23);

    int shift = exp - bias - 23;
    if (shift > 0) {
        frac <<= shift;
    } else {
        frac >>= -shift;
    }

    if (sign) {
        frac = -frac;
    }

    return frac;
}

// I think the problem is coming from the assumption that we are doing
// everything with unsigned, but if you shift any 1.0000 << 31, it's negative

int main(int argc, char **argv) {
    /* int test = 0x80000100; */
    /* float test_float = (float) test; */
    /* int back = (int) test_float; */
    /* printf("test: %d, float %.64f, back: %d\n", test, test_float, back); */
    unsigned i;
    float_bits fb;
    float f;
    int target, res;

    printf("INT_MIN: %d\n", INT_MIN);
    for (i = 1325400065; i < UINT_MAX; i++) {
        fb = (float_bits) i;
        f = float_bits_to_float(fb);
        target = (int) f;
        res = float_f2i(fb);
        if (res != target) {
            printf("invalid result! (i = %d) (f = %.64f)\n", i, f);
            show_bytes((byte_pointer) &i, sizeof(unsigned));
            show_bytes((byte_pointer) &res, sizeof(int));
            show_bytes((byte_pointer) &target, sizeof(int));
            show_bytes((byte_pointer) &fb, sizeof(float_bits));
            exit(1);
        }
    }
}
