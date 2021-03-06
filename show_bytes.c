#include <stdio.h>
#include <limits.h>

#define _GNU_SOURCE 1
#include <math.h>

#include "show_bytes.h"

void show_bytes(byte_pointer start, size_t len) {
    unsigned i;
    for (i = 0; i < len; i++) {
        printf("%.2x ", *(start++));
    }
    printf("\n");
}

void show_short(short x) {
    show_bytes((byte_pointer) &x, sizeof(short));
}

void show_int(int x) {
    show_bytes((byte_pointer) &x, sizeof(int));
}

void show_long(long x) {
    show_bytes((byte_pointer) &x, sizeof(long));
}

void show_float(float x) {
    show_bytes((byte_pointer) &x, sizeof(float));
}

void show_double(double x) {
    show_bytes((byte_pointer) &x, sizeof(double));
}

void show_pointer(void *x) {
    show_bytes((byte_pointer) &x, sizeof(void *));
}

union f2u {
    float f;
    float_bits u;
};

float_bits float_to_float_bits(float f) {
    union f2u x;
    x.f = f;
    return x.u;
}

float float_bits_to_float(float_bits u) {
    union f2u x;
    x.u = u;
    return x.f;
}

/* int main(int argc, char** argv) { */
/*     int n = -1; */
/*     show_bytes((byte_pointer)&n, sizeof n); */
/*     show_int(1); */
/*     show_short(-1); */
/*     show_long(-1); */
/*     show_float(1e40); */
/*     show_double(1e300); */
/*     show_float(INFINITY); */
/*     show_float(NAN); */
/* } */

