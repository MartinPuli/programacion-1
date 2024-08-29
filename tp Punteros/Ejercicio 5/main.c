#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float func_promedio(float * num1, float * num2, float * num3);

int main()
{
    float A, B, C, promedio = 0;

    printf("Ingrese A: ");
    scanf("%f", &A);
    printf("Ingrese B: ");
    scanf("%f", &B);
    printf("Ingrese C: ");
    scanf("%f", &C);

    promedio = func_promedio(&A, &B, &C);

    printf("\nResultado desde main: %f\n", promedio);

    return 0;
}

float func_promedio(float * num1, float * num2, float * num3)
{
    float resultado = 0;

    resultado = (*num1) * (*num2) * (*num3) / 3.0;

    printf("\nResultado desde funcion: %f", resultado);

    return resultado;
}


