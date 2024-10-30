#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct Elemento
{
    Item dato;
    struct Elemento* siguiente;
} Nodo;

void inserUltimo(Nodo** cabeza, Item elemento);
Nodo * crearNodo(Item x);
void imprimirLista(Nodo **cabeza);
void devolverMaximo(Nodo** cabeza);
void devolverPromedio(Nodo** cabeza);
void eliminarEntero(Nodo ** cabeza);

int main()
{
    Item d;
    Nodo *cabeza;
    int opcion, i;

    cabeza = NULL;

    do{
        printf("1) Ingresar valor\n2) Visualizar\n3) Ver mayor\n4) Ver promedio\n5) Eliminar entero\n6) Salir\nIngresa una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
        case 1:
            printf("\n\nIngresar valor: ");
            scanf("%d", &d);
            inserUltimo(&cabeza, d);
            break;
        case 2:
            imprimirLista(&cabeza);
            break;
        case 3:
            devolverMaximo(&cabeza);
            break;
        case 4:
            devolverPromedio(&cabeza);
            break;
        case 5:
            eliminarEntero(&cabeza);
            break;
        case 6:
            printf("\n\nFIN\n");
            break;
        default:
            printf("\n\nOpcion incorrecta\n\n");
            break;
        }

    } while(opcion != 6);

    return 0;
}

void inserUltimo(Nodo** cabeza, Item elemento)
{
    Nodo * a = *cabeza;

    while(a != NULL){
        a = a->siguiente;
    }

    a->siguiente = crearNodo(elemento);

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

void imprimirLista(Nodo **cabeza){
    Nodo * a = *cabeza;

    printf("\n\n");

    while(a != NULL){
        printf("%d-",a->dato);
        a = a->siguiente;
    }

    printf("\n\n");

}

void devolverMaximo(Nodo** cabeza)
{
    Nodo * a = *cabeza;

    if(a != NULL){
        Item max = a->dato;

        while(a != NULL){
            if(a->dato > max){
                max = a->dato;
            }
            a = a->siguiente;
        }

        printf("El entero mas grande ingresado es %d\n\n", max);
    }
    printf("\n\n");
}

void devolverPromedio(Nodo** cabeza){
    Nodo * a = *cabeza;

    if(a != NULL){
        int suma = 0;
        suma += a->dato;
        int len = 1.00;

        while(a != NULL){
            suma += a->dato;
            len += 1;
        }

        printf("El promedio de la lista es %f", suma / len);
    }

    printf("\n\n");
}

void eliminarEntero(Nodo ** cabeza)
{
    Nodo * a = *cabeza;
    Nodo * b = NULL;
    Item d;
    int cant = 0;

    printf("\n\nIngrese el entero que desea eliminar: ");
    scanf("%d", &d);

    while(a != NULL){
        if(a->dato == d){
            b->siguiente = a->siguiente;
            a = b;
        }
        b = a;
        a = a->siguiente;
    }
}

