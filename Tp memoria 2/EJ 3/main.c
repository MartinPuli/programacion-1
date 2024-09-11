#include <stdio.h>
#include <stdlib.h>
#define NUMERO 15

int main()
{
    int *vectorParcial = NULL, *vector = NULL, i;

    vectorParcial = calloc(NUMERO - 5, sizeof(int));

    for(i = 0; i < NUMERO - 5; i++){
        printf("%d ", vectorParcial[i]);
    }

    printf("\n\n");

    for(i = 0; i < NUMERO - 5; i++){
        printf("Ingrese la posicion %d: ", i + 1);
        scanf("%d", &vectorParcial[i]);
    }


    printf("\n\n");

    for(i = 0; i < NUMERO - 5; i++){
        printf("%d ", vectorParcial[i]);
    }

    vector = realloc(vectorParcial, 15 * sizeof(int));

    printf("\n\n");

    for(i = NUMERO - 5; i < NUMERO; i++){
        printf("Ingrese la posicion %d: ", i + 1);
        scanf("%d", &vector[i]);
    }

    printf("\n\n");

    for(i = 0; i < NUMERO; i++){
        printf("%d ", vector[i]);
    }

    free(vector);
    printf("\n\n");
    return 0;
}


