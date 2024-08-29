#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void llenar_vector (int * p);
void determinar_mayor(int * p);

int main()
{
    int vector[10], * p;
    srand(time(NULL));

    p = &vector[0];
    llenar_vector(p);
    determinar_mayor(p);

    return 0;
}

void llenar_vector (int * p)
{
    int i = 0;
    printf("GRAFICO (posicion: numero - pos. de memoria)\n");

    for(i; i < 10; i++)
    {
        *(p + i) = rand() % 101;
        printf("%d: %d - %p\n", i, *(p + i), p + i);
    }
}

void determinar_mayor(int * p)
{
    int mayor = -1, posicion, i = 0;

    for(i; i < 10; i++)
    {
        if(*(p + i) > mayor)
        {
            mayor = *(p + i);
            posicion = i;
        }
    }

    printf("\n\nMayor: %d\nPosicion: %d\nPosicion de memoria: %p\n", mayor, posicion, p + posicion);
}


