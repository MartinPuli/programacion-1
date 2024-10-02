#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * fp = NULL;
    int len, testfile;

    fp = fopen("file.txt", "w+");

    fputs("Escribo una linea....", fp);

    fseek(fp, 50, SEEK_CUR);
    fputs("Escribo una deslozado 50 lugares", fp);
    fseek(fp, -70, SEEK_END);
    fputs("Escribo una deslozado -70 desde el final", fp);
    fseek(fp, 0, SEEK_END);
    len = ftell(fp);
    printf("len: %d", len);
    fclose(fp);
    testfile = remove("file.txt");

    if(testfile == -1)
    {
        printf("    El archivo no se elimino");
    }
    else{
        printf("    El archivo se elimino");
    }
    return 0;

    }
