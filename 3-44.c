#include <stdio.h>
#include <limits.h>

#include "show_bytes.h"

struct P1 {
    short i;
    int c;
    int *j;
    short *d;
};

struct P2 {
    int i[2];
    char c[8];
    short s[4];
    long *j;
};

int main(int argc, char **argv) {

    struct P1 s = {
        -1,
        -1,
        (int *)ULONG_MAX,
        (short *)ULONG_MAX,
    };

    struct P2 s2 = {
        {-1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1},
        (long *) ULONG_MAX,
    };

    show_bytes((byte_pointer) &s, sizeof(struct P1));
    show_bytes((byte_pointer) &s2, sizeof(struct P2));
}
