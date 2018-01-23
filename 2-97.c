#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include <math.h>

#include "show_bytes.h"

#define NOT_CONVERTABLE 0x80000000

#define BIT_IS_ON(x, i) (x & (1 << (i - 1)))

typedef unsigned float_bits;

int find_shiftedness(int i) {
    unsigned x = (unsigned) i;

    int res = 0;

    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    if (BIT_IS_ON(x, 16)) {res += 16; x >>= 16;}
    if (BIT_IS_ON(x, 8)) {res += 8; x >>= 8;}
    if (BIT_IS_ON(x, 4)) {res += 4; x >>= 4;}
    if (BIT_IS_ON(x, 2)) {res += 2; x >>= 2;}
    if (BIT_IS_ON(x, 1)) {res += 1; x >>= 1;}

    return res;
}


float_bits float_i2f(int i) {
    int sign, exp, frac, bias, shift, tail, midpoint;
    bias = 127;

    if (i == 0) {
        return 0x0;
    } else if (i == INT_MIN) {
        sign = -1;
        exp = 31;
        frac = 0;
    } else {
        sign = i < 0 ? 1 : 0;

        /* printf("sign: %d\n", sign); */
        i = abs(i);
        /* printf("i: "); */
        /* show_bytes((byte_pointer) &i, sizeof(i)); */
        exp = find_shiftedness(i) - 1;
        i &= ~(1 << exp);
        /* show_bytes((byte_pointer) &i, sizeof(i)); */
        /* printf("exp: %d\n", exp); */
        shift = exp - 23;

        if (shift > 0) {
            frac = i >> shift;
            tail = (int)(((unsigned) i) << (32 - shift) >> (32 - shift));
            midpoint = 1 << (shift - 1);
            if (tail > midpoint || (tail == midpoint && (frac & 1))) {
                frac++;
                if (frac > 0x7FFFFF) {
                    exp++;
                    frac = 0;
                }
            }
        } else {
            frac = i << -shift;
        }

    }


    return (((float_bits) sign) << 31) | (((float_bits) (exp + bias) << 23)) | (float_bits) frac;
}


// I think the problem is coming from the assumption that we are doing
// everything with unsigned, but if you shift any 1.0000 << 31, it's negative

int main(int argc, char **argv) {
    /* int test = 0x80000100; */
    /* float test_float = (float) test; */
    /* int back = (int) test_float; */
    /* printf("test: %d, float %.64f, back: %d\n", test, test_float, back); */
    int i;
    float f;
    float_bits res, target;

    for (i = 0; i < INT_MAX; i++) {
        f = (float) i;
        target = float_to_float_bits(f);
        res = float_i2f(i);
        if (res != target) {
            printf("invalid result! (i = %d) (f = %.64f)\n", i, f);
            show_bytes((byte_pointer) &i, sizeof(int));
            show_bytes((byte_pointer) &res, sizeof(float_bits));
            show_bytes((byte_pointer) &target, sizeof(float_bits));
            exit(1);
        }
    }
}
