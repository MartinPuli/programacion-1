#include <stdio.h>
#include <stdlib.h>

int main()
{
   int vector[15], i = 0;
   srand(time(NULL));

   int * puntero = NULL;

   puntero = &vector[0];

   for(i; i < 15; i++)
   {
       vector[i] = rand() % 101;
       printf("Posicion %d: Direccion de memoria: %p - Valor: %d\n", i + 1, puntero, *puntero);
       puntero ++;
   }

   printf("\n");
}
