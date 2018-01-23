#include <stdio.h>

typedef unsigned char *byte_pointer;
typedef unsigned float_bits;

void show_bytes(byte_pointer start, size_t len);
void show_short(short x);
void show_int(int x);
void show_long(long x);
void show_float(float x);
void show_double(double x);
void show_pointer(void *x);

float float_bits_to_float(float_bits u);
float_bits float_to_float_bits(float f);

