#include <stdio.h>
#include <stdlib.h>

int main()
{
    int * vector , * temporal, i;

    temporal = malloc(10 * sizeof(int));

    for(i = 0; i < 10; i++){
        printf("Ingrese el entero numero %d: ", i + 1);
        scanf("%d", &temporal[i]);
    }

    vector = realloc(temporal, 20 * sizeof(int));

    printf("\n");

    for(i = 0; i < 10; i++){
        vector[10 + i] = vector[9 - i] * 2;
        printf("%d ", vector[i]);
    }

    for(i = 10; i < 20; i++){
        printf("%d ", vector[i]);
    }

    printf("\n");

    free(temporal);

    return 0;
}

