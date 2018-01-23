#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#define BUFSIZE 1000


int main(int argc, char **argv) {
    char buf[BUFSIZE];


    FILE *in = stdin, *out = stdout;

    for (;;) {
        while (fgets(buf, sizeof(buf), in) != NULL) {
            // There's actually no need to check that the string contains \n,
            // we'll just get it on the next read.

            if (fputs(buf, out) == EOF) {
                perror("fputs: ");
                break;
            }
        }

        if (ferror(stdin)) {
            perror("fgets: ");
            break;
        }

        if (feof(stdin))
            break;
    }

    if (fclose(out) == EOF) {
        perror("fclose: ");
        exit(1);
    }

    return 0;
}
