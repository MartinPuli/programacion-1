#include <stdio.h>
#include <stdlib.h>

int main()
{
    srand(time(NULL));
    int i;
    int * puntero = NULL, * vectorCant = NULL;

    puntero=malloc(500*sizeof(int));
    vectorCant=calloc(sizeof(int), 11);

    for(i = 0; i < 500; i++){
        puntero[i] = rand() % 11;
        vectorCant[puntero[i]] ++;
    }

    for(i = 0; i < 11; i++){
        printf("Veces %d: %d\n", i, vectorCant[i]);
    }

    return 0;
}
