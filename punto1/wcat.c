#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    int i;
    FILE *fp;
    char buffer[1024];

    /* Si no se especifican archivos */
    if (argc == 1) {
        exit(0);
    }

    /* Recorrer todos los archivos ingresados */
    for (i = 1; i < argc; i++) {

        fp = fopen(argv[i], "r");

        /* Verificar si el archivo se abrió correctamente */
        if (fp == NULL) {
            printf("wcat: cannot open file\n");
            exit(1);
        }

        /* Leer el archivo línea por línea */
        while (fgets(buffer, sizeof(buffer), fp) != NULL) {
            printf("%s", buffer);
        }

        /* Cerrar el archivo */
        fclose(fp);
        printf("\n");
    }

    /* Finalizar correctamente */
    return 0;
}
