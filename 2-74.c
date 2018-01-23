#include <stdio.h>
#include <limits.h>

#include "show_bytes.h"


int tsub_ok(int x, int y) {
    if (x < 0 && y > 0 && x - y > 0) {
        return 0;
    } else if (x > 0 && y < 0 && x - y < 0)
        return 0;
    else {
        return 1;
    }
}

int main(int argc, char **argv) {
    printf("result: %d\n", tsub_ok(INT_MAX  - 2, -3));
}
