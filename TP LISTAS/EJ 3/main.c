#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombre[50];
    char telefono[20];
    int edad;
} Contacto;

typedef struct Elemento
{
    Contacto dato;
    struct Elemento* siguiente;
} Nodo;

Nodo * ingresarNodo(Nodo** cabeza);
void inserUltimo(Nodo** cabeza, Nodo * item);
void imprimirContactos(Nodo **cabeza);
void eliminarContactos(Nodo ** cabeza);
void exportarContactos(Nodo ** cabeza, FILE * logs);

int main()
{
    Nodo *cabeza;
    int opcion, i;

    cabeza = NULL;
    FILE * logs = NULL;

    do{
        printf("1) Ingresar Contacto\n2) Visualizar Contactos\n3) Borrar Contacto\n4) Exportar contactos\n5) Salir\nIngrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
        case 1:
            ingresarNodo(&cabeza);
            break;
        case 2:
            imprimirContactos(&cabeza);
            break;
        case 3:
            eliminarContactos(&cabeza);
            break;
        case 4:
            exportarContactos(&cabeza, logs);
            break;
        case 5:
            printf("\n\nFIN\n");
            break;
        default:
            printf("\n\nOpcion incorrecta\n\n");
            break;
        }

    } while(opcion != 5);

    return 0;
}

Nodo * ingresarNodo(Nodo** cabeza){
    Nodo * a;
    a = (Nodo *) malloc(sizeof(Nodo));

    if(a == NULL){
        printf("\n\nERROR AL ASIGNAR MEMORIA DINAMICA");
        return -1;
    }

    printf("\n\nIngrese el nombre del contacto: ");
    fflush(stdin);
    gets(a->dato.nombre);
    fflush(stdin);

    printf("Ingrese el telefono del contacto: ");
    gets(a->dato.telefono);
    fflush(stdin);

    printf("Ingrese la edad del contacto: ");
    scanf("%d", &a->dato.edad);

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

    printf("\n\n");
}

void imprimirContactos(Nodo **cabeza){
    Nodo * a = *cabeza;
    int cant = 0;

    while(a != NULL){
        cant ++;
        printf("\n\nContacto %d\nNombre: %s\nTelefono: %s\nEdad: %d", cant, a->dato.nombre, a->dato.telefono, a->dato.edad);
        a = a->siguiente;
    }

    printf("\n\n");

}

void eliminarContactos(Nodo ** cabeza){
    char buscado[50];
    int encontrado = 0;

    printf("\n\nIngrese el nombre del contacto que desea eliminar: ");
    fflush(stdin);
    gets(buscado);
    fflush(stdin);

    Nodo * anterior, * actual;

    anterior = NULL;
    actual = *cabeza;

    while(actual != NULL && !encontrado){
        if(stricmp(actual->dato.nombre, buscado) == 0){
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

        printf("\n\nCONTACTO ELIMINADO\n\n");
    }
    else{
        printf("\n\nNO SE ENCONTRO EL CONTACTO A ELIMINAR\n\n");
    }
}

void exportarContactos(Nodo ** cabeza, FILE * logs){
    logs = fopen("contactos.txt", "w");

    if(logs == NULL){
        printf("ERROR AL ABRIR ARCHIVO LOGS");
    }else{

        Nodo * a;
        int cant = 0;
        a = *cabeza;

        while(a != NULL){
            cant++;
            fprintf(logs, "Contacto %d\nNombre: %s\nTelefono: %s\nEdad: %d\n\n", cant, a->dato.nombre, a->dato.telefono, a->dato.telefono);
            a = a->siguiente;
        }

        printf("\n\nContactos exportados a contactos.txt\n\n");

        fclose(logs);
    }


}
