#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "wzip: file1 [file2 ...]\n");
        exit(1);
    }

    int i;
    int prev = EOF;
    int count = 0;

    for (i = 1; i < argc; i++) {

        FILE *fp = fopen(argv[i], "r");
        if (fp == NULL) {
            fprintf(stderr, "wzip: cannot open file\n");
            exit(1);
        }

        int c;

        while ((c = fgetc(fp)) != EOF) {

            if (prev == EOF) {
                prev = c;
                count = 1;
            }
            else if (c == prev) {
                count++;
            }
            else {
                fwrite(&count, sizeof(int), 1, stdout);
                fwrite(&prev, sizeof(char), 1, stdout);

                prev = c;
                count = 1;
            }
        }

        fclose(fp);
    }

    if (count > 0) {
        fwrite(&count, sizeof(int), 1, stdout);
        fwrite(&prev, sizeof(char), 1, stdout);
    }

    return 0;
}
