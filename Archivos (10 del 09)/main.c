#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *archivo1 = NULL;
    char * nombrearchivo = "programacion1.txt";
    char texto[50];

    archivo1 = fopen(nombrearchivo, "r");

    if (archivo1 == NULL){
        printf("ERROR AL ABRIR EL ARCHIVO");
        return -1;
    }
    /*

    printf("Ingrese una cadena de texto: ");
    fflush(stdin);
    gets(texto);

    fprintf(archivo1, "%s\n", texto);
    fclose(archivo1);

    printf("\n\nFin del programa. Ver el archivo\n\n");
    return 0;
    */

    printf("El contenido del archivo...");

    fscanf(archivo1, " %[^\n]", &texto);

    printf("%s\n", texto);

    fclose(archivo1);
    return 0;
}
