#include <stdio.h>
#include <stdlib.h>

void shellMenor(int vector[], int longitud);

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
    shellMenor(vectorFinal, alocados);

    printf("\n\n");
    for(i = 0; i < alocados; i++){
        printf("%d ", vectorFinal[i]);
    }

    printf("\n");


    return 0;
}

void shellMenor(int vector[], int longitud){
    int i, j, k, bajo, alto, buscado, centro, valor, intervalo;
    bajo = 0;
    alto =  longitud - 1;

    intervalo = longitud / 2;
    while(intervalo > 0){
        for(i = intervalo; i < longitud; i++){
            j = i - intervalo;
            while(j >= 0){
                k = j + intervalo;
                if(vector[j] <= vector[k]){
                    j = -1;
                }
                else{
                    int temp;
                    temp = vector[j];
                    vector[j] = vector[k];
                    vector[k] = temp;
                    j -= intervalo;
                }
            }

        }
        intervalo = intervalo / 2;
    }
}
