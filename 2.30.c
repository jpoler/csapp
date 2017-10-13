#include <stdio.h>
#include <limits.h>

int tadd_ok(int x, int y) {
    if (x < 0 && y < 0 && (x+y) >= 0) {
        return 0;
    } else if (x > 0 && y > 0 && (x+y) < 0) {
        return 0;
    } else {
        return 1;
    }
}

int main(int argc, char** argv) {
    int x = INT_MAX, y = INT_MAX;
    printf("x: %x, y: %x, ok: %d", x, y, tadd_ok(x, y));
}
