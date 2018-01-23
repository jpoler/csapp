#include <stdio.h>
#include <limits.h>

#include "show_bytes.h"

int lower_one_mask(int n) {
    int mask = (1 << n) - 1;
    !mask && (mask = INT_MIN);
    return mask;
}

int main(int argc, char **argv) {
    printf("result: %d\n", lower_one_mask(3 ));
}
