#include <stdio.h>
#include <stdlib.h>
#define LONG 20

void llenarVector(int vector[]);
void imprimirVector(int vector[]);
void burbujaMenor(int vector[]);
void burbujaMayor(int vector[]);
void intercambioMenor(int vector[]);
void intercambioMayor(int vector[]);
void insercionMenor(int vector[]);
void insercionMayor(int vector[]);
void shellMenor(int vector[]);
void shellMayor(int vector[]);
void secuencial(int vector[], int buscado, int resultado[]);
void binarioMenor(int vector[], int buscado, int resultado[]);
void binarioMayor(int vector[], int buscado, int resultado[]);

int main()
{
    int vector[LONG], opcion = 0, ordenado = 1, buscar = 0, mayor = 0, valor = 0, resultado[2];
    srand(time(NULL));

    llenarVector(vector);
    imprimirVector(vector);

    printf("Como desea ordenar el vector?\n1)Burbuja menor a mayor\n2)Burbuja mayor a menor\n3)Intercambio menor a mayor\n4)Intercambio mayor a menor\n5)Insercion menor a mayor\n6)Insercion mayor a menor\n7)Shell menor a mayor\n8)Shell mayor a menor\nIngrese una opcion: ");
    scanf("%d", &opcion);

    switch(opcion){
    case 1:
        burbujaMenor(vector);
        break;
    case 2:
        burbujaMayor(vector);
        mayor = 1;
        break;
    case 3:
        intercambioMenor(vector);
        break;
    case 4:
        intercambioMayor(vector);
        mayor = 1;
        break;
    case 5:
        insercionMenor(vector);
        break;
    case 6:
        insercionMayor(vector);
        mayor = 1;
        break;
    case 7:
        shellMenor(vector);
        break;
    case 8:
        shellMayor(vector);
        mayor = 1;
        break;
    default:
        printf("\n\nOPCION INCORRECTA\n\n");
        ordenado = 0;
        break;
    }

    if(!ordenado){
        return 0;
    }

    printf("\n");
    imprimirVector(vector);

    printf("Desea buscar un valor?\n1)Si\n2)No\nIngrese una opcion: ");
    scanf("%d", &buscar);

    while(buscar != 1 && buscar != 2){
        printf("Ingrese una opcion correcta: ");
        scanf("%d", &buscar);
    }

    if(buscar == 2){
        return 0;
    }

    printf("\nIngrese el valor que desea buscar: ");
    scanf("%d", &valor);

    opcion = 0;
    printf("\nComo desea buscar el valor?\n1)Metodo secuencial\n2)Metodo binario\nIngrese una opcion: ");
    scanf("%d", &opcion);

    resultado[0] = -1;

    switch(opcion){
    case 1:
        secuencial(vector, valor, resultado);
        break;
    case 2:
        if(mayor){
            binarioMayor(vector, valor, resultado);
        }
        else{
            binarioMenor(vector, valor, resultado);
        }
        break;
    default:
        printf("\n\nOPCION INCORRECTA\n\n");
        ordenado = 0;
        return 0;
        break;
    }

    if(resultado[0] >= 0){
         printf("\n\nVALOR ENCONTRADO\nPosicion: %d\nIteraciones necesarias: %d\n\n", resultado[0], resultado[1]);
    }
    else{
         printf("\n\nVALOR NO ENCONTRADO\n\n");
    }



}

void llenarVector(int vector[]){
    int i;
    for(i = 0; i < LONG; i++){
        vector[i] = rand() % 21000;
        printf("%d ", vector[i]);
    }
    printf("\n\n");
}

void imprimirVector(int vector[]){
    int i = 0;
    for(i; i < LONG; i++){
        printf("%d ", vector[i]);
    }
    printf("\n\n\n\n");
}

void burbujaMenor(int vector[]){

    int i, j, interruptor = 1, aux;

    aux = vector[0];
    for(i = 0; i < LONG - 1 && interruptor; i++){
        interruptor = 0;
        for(j = 0; j < LONG - 1 - i; j++){

            if(vector[j] > vector[j + 1]){
                interruptor = 1;
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
        j = 0;
    }
}

void burbujaMayor(int vector[]){
    int i, j, interruptor = 1, aux;

    aux = vector[0];
    for(i = 0; i < LONG - 1 && interruptor; i++){
        interruptor = 0;
        for(j = 0; j < LONG - 1 - i; j++){

            if(vector[j] < vector[j + 1]){
                interruptor = 1;
                aux = vector[j];
                vector[j] = vector[j + 1];
                vector[j + 1] = aux;
            }
        }
        j = 0;
    }
}

void intercambioMenor(int vector[]){
    int i, j, aux;

    for(i = 0; i < LONG - 1; i++){
        for(j = i + 1; j < LONG; j++){
            if(vector[i] > vector[j]){
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
        j = 0;
    }
}

void intercambioMayor(int vector[]){
    int i, j, aux;

    for(i = 0; i < LONG - 1; i++){
        for(j = i + 1; j < LONG; j++){
            if(vector[i] < vector[j]){
                aux = vector[i];
                vector[i] = vector[j];
                vector[j] = aux;
            }
        }
        j = 0;
    }
}

void insercionMenor(int vector[]){
    int i = 0, j = 0, aux = 0;

    for(i = 1; i < LONG; i++){
        for(j = i; j > 0; j--){
            if(vector[j] < vector[j - 1]){
                aux = vector[j];
                vector[j] = vector[j - 1];
                vector[j - 1] = aux;
            } else{
                break;
            }
        }
        j = 0;
    }
}

void insercionMayor(int vector[]){
    int i = 0, j = 0, aux = 0;

    for(i = 1; i < LONG; i++){
        for(j = i; j > 0; j--){
            if(vector[j] > vector[j - 1]){
                aux = vector[j];
                vector[j] = vector[j - 1];
                vector[j - 1] = aux;
            } else{
                break;
            }
        }
        j = 0;
    }
}

void shellMenor(int vector[]){
    int i, j, k, bajo, alto, buscado, centro, valor, intervalo;
    bajo = 0;
    alto =  LONG - 1;

    intervalo = LONG / 2;
    while(intervalo > 0){
        for(i = intervalo; i < LONG; i++){
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

void shellMayor(int vector[]){
    int i, j, k, bajo, alto, buscado, centro, valor, intervalo;
    bajo = 0;
    alto =  LONG - 1;

    intervalo = LONG / 2;
    while(intervalo > 0){
        for(i = intervalo; i < LONG; i++){
            j = i - intervalo;
            while(j >= 0){
                k = j + intervalo;
                if(vector[j] >= vector[k]){
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

void secuencial(int vector[], int buscado, int resultado[]){
    int i = 0, iteraciones = 0;

    for(i = 0; i < LONG; i++){
        iteraciones ++;
        if(vector[i] == buscado){
            resultado[0] = i;
            break;
        }
    }

    resultado[1] = iteraciones;
}

void binarioMenor(int vector[], int buscado, int resultado[]){

    int bajo, alto, centro = 0, valor = 0, iteraciones = 0;

    bajo = 0;
    alto = LONG - 1;

    while(bajo <= alto){
        iteraciones ++;
        centro = (alto + bajo)/2;
        valor = vector[centro];
        if(valor == buscado){
            resultado[0] = centro;
            bajo = LONG;
        }
        else if(valor > buscado){
            alto = centro - 1;
        }
        else{
            bajo = centro + 1;
        }
    }

    resultado[1] = iteraciones;
}

void binarioMayor(int vector[], int buscado, int resultado[]){

    int bajo, alto, valor = 0, centro = 0, iteraciones = 0;

    bajo = 0;
    alto = LONG - 1;

    while(bajo <= alto){
        iteraciones ++;
        centro = (alto + bajo)/2;
        valor = vector[centro];
        if(valor == buscado){
            resultado[0] = centro;
            bajo = LONG;
        }
        else if(valor < buscado){
            alto = centro - 1;
        }
        else{
            bajo = centro + 1;
        }
    }

    resultado[1] = iteraciones;
}

