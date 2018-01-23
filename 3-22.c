#include <stdio.h>

int fact_do(int n) {
    int result = 1;
    do {
        result *= n;
        n -= 1;
    } while (n > 1);

    return result;
}

int main(int argc, char **argv) {
    int res = fact_do(14);
    printf("result: %d\n", res);
}
