#include <stdio.h>
#include <stdlib.h>
#define NUMERO 15

int main()
{
    int *vector = NULL, i;

    vector = calloc(NUMERO, sizeof(int));

    for(i = 0; i < NUMERO; i++){
        printf("%d ", vector[i]);
    }

    printf("\n\n");

    for(i = 0; i < NUMERO - 5; i++){
        printf("Ingrese la posicion %d: ", i + 1);
        scanf("%d", &vector[i]);
    }

    printf("\n\n");

    for(i = 0; i < NUMERO - 5; i++){
        printf("%d ", vector[i]);
    }

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


