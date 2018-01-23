#include <stdio.h>
#include <limits.h>

#include "show_bytes.h"

int int_size_is_32() {
    int set_msb = (((1 << 15) << 15) << 1);
    return set_msb && !(set_msb << 1);
}

int main(int argc, char **argv) {
    printf("result: %d\n", int_size_is_32());

}
