#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int i, j, alocados = 0, repetido = 0;
    int * puntero = NULL, *vectorParcial = NULL, * vectorFinal = NULL;

    puntero = malloc(5);
    vectorParcial = malloc(5);

    for(i = 0; i < 5; i++){
        puntero[i] = rand() % 6;
        printf("%d ", puntero[i]);
        for(j = 0; j < i; j++){
            if(puntero[i] == puntero[j]){
                repetido = 1;
                break;
            }
        }
        if(!repetido){
            vectorParcial[alocados] = puntero[i];
            alocados ++;
        }
        repetido = 0;
    }

    vectorFinal = realloc(vectorParcial, alocados);
    printf("\n\n");

    for(i = 0; i < alocados; i++){
        printf("%d ", vectorFinal[i]);
    }

    printf("\n");

    return 0;
}
