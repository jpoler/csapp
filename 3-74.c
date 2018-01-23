#include <stdio.h>
#include <limits.h>
#include <math.h>

#include "show_bytes.h"

typedef enum {NEG, ZERO, POS, OTHER} range_t;

range_t find_range(float x);

union float_bits {
    float f;
    unsigned u;
};

int main(int argc, char **argv) {
    union float_bits fb;
    range_t range;
    fb.u = UINT_MAX;

    do {
        range = find_range(fb.f);
        if (isnan(fb.f) && range != OTHER) {
            printf("NAN: wanted OTHER, got %d\n", range);
            printf("float: %.100f, unsigned %u\n", fb.f, fb.u);
        } else if (fb.f > 0 && range != POS) {
            printf("wanted POS, got %d\n", range);
            printf("float: %.100f, unsigned %u\n", fb.f, fb.u);
        } else if (fb.f < 0 && range != NEG) {
            printf("wanted NEG, got %d\n", range);
            printf("float: %.100f, unsigned %u\n", fb.f, fb.u);
        } else if (fb.f == 0 && range != ZERO) {
            printf("wanted ZERO, got %d\n", range);
            printf("float: %.100f, unsigned %u\n", fb.f, fb.u);
        }
        fb.u = fb.u + 1;
    } while (fb.u < UINT_MAX);

}
