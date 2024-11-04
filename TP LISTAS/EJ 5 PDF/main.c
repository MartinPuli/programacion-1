#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct Elemento
{
    Item dato;
    struct Elemento* siguiente;
} Nodo;

void ingresarNodo(Nodo** cabeza);
void inserUltimo(Nodo** cabeza, Nodo * item);
void imprimirNodos(Nodo **cabeza);
void eliminarNodo(Nodo ** cabeza);
void exportarNodos(Nodo ** cabeza, FILE * log);

int main()
{
    Nodo *cabeza;
    int opcion, i;

    cabeza = NULL;
    FILE * log = NULL;

    for(i = 0; i < 100; i++){
        ingresarNodo(&cabeza);
    }

    do{
        printf("1) Ingresar nodo\n2) Visualizar nodos\n3) Eliminar nodo\n4) Exportar lista\n5) Salir\nIngrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
        case 1:
            ingresarNodo(&cabeza);
            printf("\n\n");
            break;
        case 2:
            imprimirNodos(&cabeza);
            break;
        case 3:
            eliminarNodo(&cabeza);
            break;
        case 4:
            exportarNodos(&cabeza, log);
            break;
        case 5:
            printf("\nFIN\n\n");
            break;
        default:
            printf("\n\nOpcion incorrecta\n\n");
            break;
        }

    } while(opcion != 5);

    return 0;
}

void ingresarNodo(Nodo** cabeza){
    Nodo * a;
    a = (Nodo *) malloc(sizeof(Nodo));

    if(a == NULL){
        printf("\n\nERROR AL ASIGNAR MEMORIA DINAMICA");
        return -1;
    }

    a->dato = rand() % 1001;

    a->siguiente = NULL;

    inserUltimo(cabeza, a);
}

void inserUltimo(Nodo** cabeza, Nodo * item)
{
    if (*cabeza == NULL) {
        *cabeza = item;
    } else {
        Nodo* a = *cabeza;
        while (a->siguiente != NULL) {
            a = a->siguiente;
        }
        a->siguiente = item;
    }
}

void imprimirNodos(Nodo **cabeza){
    Nodo * a = *cabeza;

    printf("\n");

    while(a != NULL){
        printf("%d-", a->dato);
        a = a->siguiente;
    }

    printf("\n\n");

}

void eliminarNodo(Nodo ** cabeza){
    int valor, encontrado = 0;

    printf("\nIngrese el valor que desea eliminar: ");
    scanf("%d", &valor);


    Nodo * actual = *cabeza;
    Nodo * anterior = NULL;

    while(actual != NULL){
        if(actual->dato == valor){
            encontrado ++;
            anterior->siguiente = actual->siguiente;
            free(actual);
            actual = anterior ->siguiente;

        } else{
            anterior = actual;
            actual = actual->siguiente;
        }
    }

    if(encontrado){
        printf("\n\nVALOR ELIMINADO %d VEZ/VECES\n\n", encontrado);
    } else{
        printf("\n\nVALOR NO ENCONTRADO\n\n");
    }

}

void exportarNodos(Nodo ** cabeza, FILE * log){
    log  = fopen("log.txt", "w");
    Nodo * a = *cabeza;

    if(log == NULL){
        printf("ERROR AL CREAR ARCHIVO log.txt");
        return -1;
    }

    while(a != NULL){
        fprintf(log, "%d-", a->dato);
        a = a->siguiente;
    }

    printf("\nLISTA EXPORTADA\n\n");

    fclose(log);
}
