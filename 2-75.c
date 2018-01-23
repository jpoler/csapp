#include <stdio.h>
#include <limits.h>

#include "show_bytes.h"

int signed_high_product(int x, int y);

/*
  This computation comes from looking at this part of equation 2.18:

  [x * y + (x_w-1 * y + y_w-1 * x)* 2^w + x_w-1*y_w-1*2^2w] mod 2^w

  where we ignore the mod 2^w part since we want the higher w bits, and we also
  ignore the x_w-1*y_w-1*2^2w term since our new 2w bit number is mod 2^2w.
 */
unsigned unsigned_high_product(unsigned x, unsigned y) {
    int res = signed_high_product(x, y);

    int sx = (int) x;
    int sy = (int) y;

    if (sx < 0) {
        res += y;
    }

    if (sy < 0) {
        res += x;
    }

    return res;
}

int main(int argc, char **argv) {
    int res = 3 * (1 << 16);
    show_int(res);
    /* printf("shift result: %d\n", ); */
}
