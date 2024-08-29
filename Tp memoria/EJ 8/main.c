#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    char cadenaPila1[30],cadenaPila2[30];
    char * temporal, * cadenaDin = NULL;

    fflush(stdin);
    printf("Ingrese la cadena 1: ");
    gets(cadenaPila1);
    fflush(stdin);
    printf("Ingrese la cadena 2: ");
    gets(cadenaPila2);
    fflush(stdin);

    printf("\n\nMemoria de pila cadena 1: %s", cadenaPila1);
    printf("\n\nMemoria de pila cadena 2: %s", cadenaPila2);

    temporal = malloc(strlen(cadenaPila1));

    strcpy(temporal, cadenaPila1);

    cadenaDin = realloc(temporal, (strlen(cadenaPila1) + 1 + strlen(cadenaPila2)) * sizeof(char));

    strcat(cadenaDin, cadenaPila2);

    printf("\n\nMemoria de dinamica (ambas unidas): %s\n", cadenaDin);

    free(cadenaDin);
}
