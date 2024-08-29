#include <stdio.h>
#include <stdlib.h>

int main()
{
   float numero1, numero2;
   float * puntero1 = NULL;
   float * puntero2 = NULL;

   printf("Ingrese el primer numero: ");
   scanf("%f", &numero1);

   printf("Ingrese el segundo numero: ");
   scanf("%f", &numero2);

   puntero1 = &numero1;
   puntero2 = &numero2;

   printf("La suma de los numeros introducidos es: %f\n", *puntero1 + *puntero2);
}
