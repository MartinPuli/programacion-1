#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int Id_pedido;
    long fecha;
    char producto[50];
    float precio;
} Item;

typedef struct Elemento
{
    Item dato;
    struct Elemento* siguiente;
} Nodo;

void inserUltimo(Nodo** cabeza, FILE * logs);
Nodo * crearNodo();
void imprimirLista(Nodo **cabeza);
void eliminarItem(Nodo ** cabeza);

int main()
{
    Nodo *cabeza;
    int opcion, i;

    cabeza = NULL;
    FILE * logs = NULL;

    srand(time(NULL));

    do{
        printf("1) Ingresar item\n2) Visualizar items\n3) Borrar un item\n4) Salir\nIngrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
        case 1:
            inserUltimo(&cabeza, logs);
            break;
        case 2:
            imprimirLista(&cabeza);
            break;
        case 3:
            eliminarItem(&cabeza);
            break;
        case 4:
            printf("\n\nFIN\n");
            break;
        default:
            printf("\n\nOpcion incorrecta\n\n");
            break;
        }

    } while(opcion != 4);

    return 0;
}

void inserUltimo(Nodo** cabeza, FILE * logs)
{
    Nodo* nuevo = crearNodo();

    logs = fopen("logsProds.txt", "a");

    if(logs == NULL)
    {
        printf("\n\nERROR AL ABRIR ARCHIVO LOGS\n");
        return -1;
    }

    if (*cabeza == NULL) {
        *cabeza = nuevo;
    } else {
        Nodo* a = *cabeza;
        while (a->siguiente != NULL) {
            a = a->siguiente;
        }
        a->siguiente = nuevo;
    }

    fprintf(logs, "Se agrego un producto\nProducto: %s\nId: %d\nFecha: %li\nPrecio: $%.2f\n\n",nuevo->dato.producto, nuevo->dato.Id_pedido, nuevo->dato.fecha, nuevo->dato.precio);

    fclose(logs);

    printf("\n\n");
}

Nodo * crearNodo(Item x)
{
    Nodo * a;
    a = (Nodo*)malloc(sizeof(Nodo));

    a->dato.Id_pedido = rand() % 10001;

    printf("\n\nIngrese la fecha del producto: ");
    scanf("%li", &a->dato.fecha);

    printf("Ingrese el nombre del producto: ");
    fflush(stdin);
    gets(a->dato.producto);
    fflush(stdin);

    printf("Ingrese el precio del producto: ");
    scanf("%f", &a->dato.precio);
    a->siguiente=NULL;

    return a;
}

void imprimirLista(Nodo **cabeza){
    Nodo * a = *cabeza;

    while(a != NULL){
        printf("\n\nProducto: %s\nId: %d\nFecha: %li\nPrecio: $%.2f",a->dato.producto, a->dato.Id_pedido, a->dato.fecha, a->dato.precio);
        a = a->siguiente;
    }

    printf("\n\n");

}

void eliminarItem(Nodo ** cabeza){
    char buscado[50];
    int encontrado = 0;

    printf("\n\nIngrese el producto que desea eliminar: ");
    fflush(stdin);
    gets(buscado);
    fflush(stdin);

    Nodo * anterior, * actual;

    anterior = NULL;
    actual = *cabeza;

    while(actual != NULL && !encontrado){
        if(stricmp(actual->dato.producto, buscado) == 0){
            encontrado = 1;
        }
        if(!encontrado){
            anterior = actual;
            actual = actual->siguiente;
        }
    }

    if(actual != NULL){
        if(actual == *cabeza){
            *cabeza = actual->siguiente;
        }
        else{
            anterior->siguiente = actual->siguiente;
        }
        free(actual);

        printf("\n\nITEM ELIMINADO\n\n");
    }
    else{
        printf("\n\nNO SE ENCONTRO EL ITEM A ELIMINAR\n\n");
    }
}
