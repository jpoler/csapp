#include <stdio.h>
#include <limits.h>

#include "show_bytes.h"

int fits_bits(int x, int n) {
    return (x >> n) == 0;
}

int main(int argc, char **argv) {
    printf("it fits: %d\n", fits_bits(20, 5));
}
