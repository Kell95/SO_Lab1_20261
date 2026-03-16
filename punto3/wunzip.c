#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "wunzip: file1 [file2 ...]\n");
        exit(1);
    }

    int i;
    for (i = 1; i < argc; i++) {

        FILE *fp = fopen(argv[i], "r");
        if (!fp) {
            fprintf(stderr, "wunzip: cannot open file %s\n", argv[i]);
            exit(1);
        }

        int count;
        unsigned char c;

        while (fread(&count, sizeof(int), 1, fp) == 1) {

            if (fread(&c, 1, 1, fp) != 1)
                break;

            int j;
            for (j = 0; j < count; j++) {
                fputc(c, stdout);
            }
        }

        fclose(fp);
    }

    return 0;
}

