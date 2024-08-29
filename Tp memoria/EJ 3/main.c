#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i;
    char cadenaPila[50];
    char * cadenaDin = NULL;

    fflush(stdin);
    printf("Ingrese la cadena: ");
    gets(cadenaPila);
    fflush(stdin);

    printf("\n\nMemoria de pila: %s", cadenaPila);

    cadenaDin = malloc(strlen(cadenaPila));

    strcpy(cadenaDin, cadenaPila);

    printf("\n\nMemoria de dinamica: %s\n", cadenaDin);

    free(cadenaDin);
}
