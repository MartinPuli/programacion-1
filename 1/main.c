#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct Elemento
{
    Item dato;
    struct Elemento* siguiente;
} Nodo;

void inserPrimero(Nodo** cabeza, Item elemento);
Nodo * crearNodo(Item x);
void contarEnteros(Nodo** cabeza);
void imprimirLista(Nodo** cabeza);

int main()
{
    Item d;
    Nodo *cabeza, *ptr;
    int opcion, i;

    cabeza = NULL;

    do{
        printf("1) Ingresar valor\n2) Visualizar\n3) Contar entero\nIngresa una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
        case 1:
            printf("\n\nIngresar valor: ");
            scanf("%d", &d);
            inserPrimero(&cabeza, d);
            break;
        case 2:
            imprimirLista(&cabeza);
            break;
        case 3:
            contarEnteros(&cabeza);
            break;
        case 4:
            printf("\n\nFIN\n");
            break;
        default:
            printf("\n\nOpcion incorrecta\n\n");
            break;
        }

    } while(opcion != 4);
}

void inserPrimero(Nodo** cabeza, Item elemento)
{
    Nodo * nuevo;
    nuevo = crearNodo(elemento);
    nuevo->siguiente = *cabeza;
    *cabeza = nuevo;

    printf("\n\n");
}

Nodo * crearNodo(Item x)
{
    Nodo * a;
    a = (Nodo*)malloc(sizeof(Nodo));
    a->dato = x;
    a->siguiente=NULL;
    return a;
}

void contarEnteros(Nodo** cabeza)
{
    Nodo * a = *cabeza;
    Item d;
    int cant = 0;

    printf("\n\nIngrese el entero que desea buscar: ");
    scanf("%d", &d);

    while(a != NULL){
        if(a->dato == d){
            cant ++;
        }
        a = a->siguiente;
    }

    printf("El entero aparece %d vez/veces\n\n", cant);

}

void imprimirLista(Nodo **cabeza){
    Nodo * a = *cabeza;

    printf("\n\n");

    while(a != NULL){
        printf("%d-",a->dato);
        a = a->siguiente;
    }

    printf("\n\n");

}
