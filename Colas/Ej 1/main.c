#include <stdio.h>
#include <stdlib.h>
#define MAXTAMQ 50

typedef int TipoDato;
typedef struct
{
    TipoDato listaCola [MAXTAMQ];
    int frente, final;
}Cola;

void crearCola(Cola* cola);

void insertar (Cola* cola, TipoDato elemento);
void imprimir (Cola* cola);
TipoDato quitar (Cola* cola);
TipoDato frente (Cola cola);
int colaVacia (Cola cola);
int colaLlena (Cola cola);


int main()
{
    int opcion, i;
    srand(time(NULL));
    Cola * cola;
    cola = malloc(sizeof(Cola));
    crearCola(cola);

    for(i = 0; i < 20; i++){
        insertar(cola, rand() % 101);
    }

    do
    {
        printf("1) Encolar elemnto\n2) Desencolar elemnto\n3) Visualizar cola\n4) Visualizar frente\n5) Salir\nIngrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
        case 1:
            insertar(cola, rand() % 101);
            imprimir(cola);
            break;
        case 2:
            quitar(cola);
            break;
        case 3:
            imprimir(cola);
            break;
        case 4:
            frente(*cola);
            break;
        case 5:
            printf("\n\nFIN\n\n");
            break;
        default:
            printf("\n\nOpcion incorrecta\n\n");
            break;

        }

    } while (opcion != 5);

    return 0;
}

void crearCola(Cola* cola)
{
    cola->frente = 0;
    cola->final = -1;
}

void imprimir (Cola* cola){
    int i;
    printf("\n\n");
    if(colaVacia(* cola)){
        printf("\n\nLa cola esta vacia\n\n");
    } else{
        for(i = cola->frente; i <= cola->final; i++){
            printf("%d-", cola->listaCola[i]);
        }
    }
    printf("\n\n");

}

void insertar(Cola* cola, TipoDato entrada)
{
    if (colaLlena(*cola))
     {
      puts("Cola Completa");
      exit(1);
     }

    cola->final++;
    cola->listaCola[cola->final] = entrada;
}

TipoDato quitar(Cola* cola)
{
    TipoDato tem;
    if (colaVacia (*cola))
    {
        puts("Se intenta sacar un elemento en cola vacia");
        exit(1);
    }

    tem=cola->listaCola[cola->frente];
    cola->frente++;

    printf("\n\nElemento quitado\n\n");

    return tem;
}

TipoDato frente (Cola cola)
{
    if(!colaVacia(cola)){
        printf("\n\n%d\n\n", cola.listaCola[cola.frente]);
        return cola.listaCola[cola.frente];
    } else{
        printf("\n\nLa cola esta vacia\n\n");
    }
}

int colaVacia(Cola cola)
{
    return cola.final < cola.frente;
}

int colaLlena (Cola cola)
{
    return cola.final == MAXTAMQ - 1;
}

