#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nombre_presi[50];
    char nombre_vice[50];
    int cant_votos;
} Candidato;

typedef struct Elemento
{
    Candidato dato;
    struct Elemento* siguiente;
} Nodo;

Nodo * ingresarNodo(Nodo** cabeza);
void inserUltimo(Nodo** cabeza, Nodo * item);
void imprimirCand(Nodo **cabeza);
void votar(Nodo ** cabeza);
void cerrarVotacion(Nodo ** cabeza, FILE * resultados);

int main()
{
    Nodo *cabeza;
    int opcion;

    cabeza = NULL;
    FILE * resultados = NULL;

    do{
        printf("1) Ingresar Candidato\n2) Visualizar Candidatos\n3) Votar\n4) Cerrar votacion\nIngrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
        case 1:
            ingresarNodo(&cabeza);
            break;
        case 2:
            imprimirCand(&cabeza);
            break;
        case 3:
            votar(&cabeza);
            break;
        case 4:
            cerrarVotacion(&cabeza, resultados);
            break;
        default:
            printf("\n\nOpcion incorrecta\n\n");
            break;
        }

    } while(opcion != 4);

    return 0;
}

Nodo * ingresarNodo(Nodo** cabeza){
    Nodo * a;
    a = (Nodo *) malloc(sizeof(Nodo));

    if(a == NULL){
        printf("\n\nERROR AL ASIGNAR MEMORIA DINAMICA");
        return -1;
    }

    printf("\n\nIngrese el nombre del presidente de la lista: ");
    fflush(stdin);
    gets(a->dato.nombre_presi);
    fflush(stdin);

    printf("Ingrese el nombre del vice-presidente de la lista: ");
    gets(a->dato.nombre_vice);
    fflush(stdin);

    a->dato.cant_votos = 0;

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

void imprimirCand(Nodo **cabeza){
    Nodo * a = *cabeza;
    int cant_listas = 0;

    while(a != NULL){
        cant_listas ++;
        printf("\n\nLista %d\nNombre del Presidente: %s\nNombre del Vice-Presidente: %s\nVotos: %d", cant_listas, a->dato.nombre_presi, a->dato.nombre_vice, a->dato.cant_votos);
        a = a->siguiente;
    }

    printf("\n\n");

}

void votar(Nodo ** cabeza){
    int lista;
    int encontrado = 0, cant_listas = 0;
    Nodo * a;
    a = *cabeza;

    imprimirCand(cabeza);

    printf("\n\nIngrese el numero de lista que desea votar: ");
    scanf("%d", &lista);

    while(a != NULL){
        cant_listas ++;
        if(lista == cant_listas){
            a->dato.cant_votos ++;
            encontrado = 1;
            break;
        }
        a = a->siguiente;
    }

    if(encontrado){
        printf("\nVOTO REALIZADO\n\n");
    } else{
        printf("\nLISTA NO ENCONTRADA\n\n");
    }
}

cerrarVotacion(Nodo ** cabeza, FILE * resultados){
    int mayor = -1;
    int pos = -1;
    int lista = 0;
    Nodo * a = *cabeza;

    resultados = fopen("resultados.txt", "w");

    if(resultados == NULL){
        printf("ERROR AL ABRIR ARCHIVO RESULTADOS");
        return -1;
    }

    while(a != NULL){
        lista ++;
        fprintf(resultados, "Lista %d\nNombre del Presidente: %s\nNombre del Vice-Presidente: %s\nVotos: %d\n\n", lista, a->dato.nombre_presi, a->dato.nombre_vice, a->dato.cant_votos);

        if(a->dato.cant_votos > mayor){
            pos = lista;
            mayor = a->dato.cant_votos;
        }

        a = a->siguiente;
    }

    fclose(resultados);

    if(mayor > -1){
        printf("\nLa lista %d gano con %d voto/s\nFIN\n\n", pos, mayor);
    } else{
        printf("\nNo se ingresaron listas\nFIN\n\n");
    }
}
