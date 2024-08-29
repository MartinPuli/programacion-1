#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int func_producto(int * num);

int main()
{
    int A, B, resultado;

    printf("Ingrese A: ");
    scanf("%d", &A);
    printf("Ingrese B: ");
    scanf("%d", &B);

    resultado = A + B;

    resultado = func_producto(&resultado);

    printf("\nResultado: %d\n", resultado);

    return 0;
}

int func_producto(int * num)
{
    return (*num) * (*num);
}


