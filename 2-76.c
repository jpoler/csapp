#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#include "show_bytes.h"

int tmult_ok(size_t x, size_t y) {
    size_t p = x*y;
    return !x || (p/x) == y;
}

void *calloc(size_t nmemb, size_t size) {
    void *buf;
    size_t total_size;

    if (!tmult_ok(nmemb, size)) {
        return NULL;
    }

    total_size = nmemb * size;

    if (total_size == 0) {
        printf("total size is 0\n");
        return NULL;
    }

    if ((buf = malloc(total_size)) == NULL) {
        perror("malloc: ");
        return NULL;
    }

    if ((buf = memset(buf, 0, total_size)) == NULL) {
        perror("memset: ");
        return NULL;
    }

    return buf;
}

int main(int argc, char **argv) {
    printf("sizeof size_t: %lu\n", sizeof(size_t));

    printf("result: %d\n", tmult_ok(SIZE_T_MAX, SIZE_T_MAX));

    void *res = calloc(20, 10);
    if (res) {
        printf("my fondest memories: %p\n", res);
        show_bytes((byte_pointer) res, 20*10);
        free(res);
    }


    return 0;
}
