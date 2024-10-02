#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char marca [50];
    char modelo [50];
    char dominio [7];
    float precio;
} autos;

int aniadirAutos(autos* punt, FILE * fa);
int leerAutos(autos* punt, FILE * fa);
int buscarAuto(autos* punt, FILE * fa);
int vaciarAuto(FILE * fa);

int main()
{
    FILE * fa = NULL;
    int opcion;
    autos * punt = NULL;
    punt = (autos *) malloc(sizeof(autos));


    printf("Bienvenido al sistema de autos\n\n");
    system("pause");

    while (opcion != 5)
    {
        system("cls");
        printf("1) Añadir nuevos autos al final\n2) Listar todos los registros\n3) Buscar x marco o modelo\n4) Vaciar archivo\n5) Salir\nIngrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion){
        case 1:
            aniadirAutos(punt, fa);
            break;
        case 2:
            leerAutos(punt, fa);
            break;
        case 3:
            buscarAuto(punt, fa);
            break;
        case 4:
            vaciarAuto(fa);
            break;
        case 5:
            printf("\nFIN\n");
            break;
        default:
            printf("\n\nOPCION INCORRECTA\n\n");
            system("pause");
            break;

        }
    }
}

int aniadirAutos(autos* punt, FILE * fa)
{
    int continuar = 0;

    do
    {
        system("cls");

        fa = fopen("autos.bin", "ab");

        if(fa == NULL)
        {
            printf("Error al abrir archivo");
            return -1;
        }


        printf("Ingrese el dominio: ");
        fflush(stdin);
        gets(punt->dominio);

        printf("Ingrese la marca: ");
        fflush(stdin);
        gets(punt->marca);

        printf("Ingrese el modelo: ");
        fflush(stdin);
        gets(punt->modelo);

        printf("Ingrese el precio: ");
        fflush(stdin);
        scanf("%f", &punt->precio);

        fwrite(punt, sizeof(autos), 1, fa);
        fputc('\n', fa);

        fclose(fa);

        printf("\n\nAuto aniadido\n\n");

        printf("Desea agregar otro auto (1: si | 0: no): ");
        fflush(stdin);
        scanf("%d", &continuar);

        while(continuar != 1 && continuar != 0)
        {
            printf("Opcion incorrecta (1: si | 0: no): ");
            scanf("%d", &continuar);
        }



        system("pause");

    } while(continuar != 0);

    return 0;
}

int leerAutos(autos* punt, FILE * fa)
{
    int cant_registros, i = 0;

    system("cls");

    fa = fopen("autos.bin", "rb");

    if(fa == NULL)
    {
        printf("Error al abrir archivo");
        return -1;
    }

    fseek(fa, 0, SEEK_END);
    cant_registros = ftell(fa) / (sizeof(autos) + 1);
    printf("Cantidad de autos: %d", cant_registros);

    rewind(fa);

    fread(punt, sizeof(autos), 1, fa);

    while(!feof(fa))
    {
        i = i + 1;
        printf("\n\nAuto %d\nDominio: %s\nMarca: %s\nModelo: %s\nPrecio: $%.2f", i, punt->dominio, punt->marca, punt->modelo, punt->precio);
        fgetc(fa);
        fread(punt, sizeof(autos), 1, fa);

    }

    fclose(fa);
    printf("\n\n");
    system("pause");
}

int buscarAuto(autos* punt, FILE * fa)
{
    int i = 0, opcion;
    char buscado [50];

    system("cls");

    fa = fopen("autos.bin", "rb");

    if(fa == NULL)
    {
        printf("Error al abrir archivo");
        return -1;
    }

    printf("Desea buscar por marca o modelo (1 o 2): ");
    scanf("%d", &opcion);

    while(opcion != 1 && opcion !=2)
    {
        printf("Opcion incorrecta (1 o 2): ");
        scanf("%d", &opcion);
    }

    printf("Ingrese el valor buscado: ");
    fflush(stdin);
    gets(buscado);
    fflush(stdin);

    fread(punt, sizeof(autos), 1, fa);

    while(!feof(fa))
    {
        i = i + 1;

        if((opcion == 1 && strstr(buscado, punt->marca) == 0) || (opcion == 2 && strstr(buscado, punt->dominio) == 0))
        {
            printf("\n\nAuto %d\nDominio: %s\nMarca: %s\nModelo: %s\nPrecio: $%.2f", i, punt->dominio, punt->marca, punt->modelo, punt->precio);
        }

        fgetc(fa);
        fread(punt, sizeof(autos), 1, fa);
    }

    fclose(fa);
    printf("\n\n");
    system("pause");
}

int vaciarAuto(FILE * fa)
{
    fa = fopen("autos.bin", "wb");
    fclose(fa);
}
