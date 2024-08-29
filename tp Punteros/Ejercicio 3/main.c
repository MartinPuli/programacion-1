#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void mostrarVector(int vector[]);
void mostrarDirec(int vector[]);
void mostrarDatos(int vector[]);
void mostrarMedio(int vector[]);


int main()
{
    int vector[30], i = 0, opcion;
    srand(time(NULL));

    for(i; i < 30; i++)
    {
        vector[i] = rand() % 501;
        printf("%p\n", &vector[i]);
    }

    printf("\n");

    do
    {
        printf("Ingrese una opcion:\n1) Mostrar vector\n2) Mostrar direccion primera y ultima posicion\n3) Mostrar datos primera y ultima posicion\n4) Mostrar datos y direccion posicion media\n5) Salir\nIngrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            mostrarVector(vector);
            break;
        case 2:
            mostrarDirec(vector);
            break;
        case 3:
            mostrarDatos(vector);
            break;
        case 4:
            mostrarMedio(vector);
            break;
        case 5:

            break;
        default:
            printf("\nOpcion incorrecta\n\n");
            break;
        }
    } while(opcion != 5);
}

void mostrarVector(int vector[])
{
    int i = 0;

    printf("\n[");
    for(i; i < 30; i ++)
    {
        if(i == 29)
        {
            printf("%d", vector[i]);
        }
        else
        {
            printf("%d, ", vector[i]);
        }
    }
    printf("]\n\n");
}

void mostrarDirec(int vector[])
{
    int * puntero1 = &vector[0];
    int * puntero2 = &vector[29];
    printf("\nDireccion primer posicion: %p\nDireccion ultima posicion: %p\n", puntero1, puntero2);
    printf("Direccion punteros: %p y %p\n\n", &puntero1, &puntero2);
}

void mostrarDatos(int vector[])
{
    int * puntero1 = &vector[0];
    int * puntero2 = &vector[29];
    printf("\nDato primer posicion: %d\nDato ultima posicion: %d\n", *puntero1, *puntero2);
    printf("Direccion punteros: %p y %p\n\n", &puntero1, &puntero2);
}

void mostrarMedio(int vector[])
{
    int * puntero = &vector[15];
    printf("\nDireccion posicion central: %p\nDato posicion central: %d\n", puntero, *puntero);
    printf("Direccion punteros: %p\n\n", &puntero);
}

