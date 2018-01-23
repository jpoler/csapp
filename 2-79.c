#include <stdio.h>
#include <limits.h>

#include "show_bytes.h"

int mul3div4(int x) {
    return ((x << 1) + x) >> 2;
}

int main(int argc, char **argv) {
    int res = mul3div4(INT_MAX);
    show_int(res);

}
