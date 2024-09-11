#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombre[30];
    char apellido[30];
    int edad;
    char dni[8];
} Persona;

void cargar_datos(Persona * P, int cant);
void imprimir_datos(Persona * P, int cant);

int main()
{
    int i, numero = 0;

    Persona * P = NULL;

    printf("Ingrese el numero de personas a ingresar: ");
    scanf("%d", &numero);

    P = (Persona *) malloc(numero * sizeof(Persona));
    if (P == NULL){
        printf("Error en la asignacion de memoria");
    }
    else
    {
        cargar_datos(P, numero);

        imprimir_datos(P, numero);
    }

    free(P);
    return 0;
}

void cargar_datos(Persona * P, int cant)
{
    int i;
    for(i=0; i<cant; i++){
            printf("\nIngrese el nombre de la persona: ");
            fflush(stdin);
            gets((P + i)->nombre);

            printf("\nIngrese el apellido de la persona: ");
            fflush(stdin);
            gets((P + i)->apellido);

            printf("\nIngrese la edad de la persona: ");
            scanf("%d", &(P + i)->edad);

            printf("\nIngrese el dni de la persona: ");
            fflush(stdin);
            gets((P + i)->dni);

            printf("\n\n");
        }
}

void imprimir_datos(Persona * P, int cant){
    int i;
    for(i=0; i<cant; i++){
            printf("\nPersona %d\nNombre: %s\nApellido: %s\nEdad: %d\nDNI: %s\n\n", i + 1, (P + i)->nombre,(P + i)->apellido,(P + i)->edad,(P + i)->dni);
            printf("\n\n");
        }
}
