#include <stdio.h>
#include <limits.h>


int is_little_endian() {
    int n = 1;
    unsigned char *start = (unsigned char *)&n;
    return *start;
}

int main(int argc, char **argv) {
    printf("is little endian: %d\n", is_little_endian());
}
