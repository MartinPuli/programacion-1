#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    srand(time(NULL));
    int tamanio, * cantVocales, i;
    char * cadena = NULL;

    printf("Ingrese el tamanio de la cadena: ");
    scanf("%d", &tamanio);

    cadena = malloc(tamanio * sizeof(char));
    cantVocales = calloc(sizeof(int), 1);

    fflush(stdin);
    printf("\n\nIngrese la cadena: ");
    gets(cadena);
    fflush(stdin);


    for(i = 0; i < tamanio; i++){
        if(cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u' || cadena[i] == 'A' || cadena[i] == 'E' || cadena[i] == 'I' || cadena[i] == 'O' || cadena[i] == 'U'){
            *cantVocales += 1;
        }
    }

    printf("\n\nCadena: %s\nCant vocales: %d\n\n", cadena, *cantVocales);

    free(cadena);
    free(cantVocales);

    return 0;
}

