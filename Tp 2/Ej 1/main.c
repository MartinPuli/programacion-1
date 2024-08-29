#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define CANT 5

struct Datos_Auto{
    char marca[30];
    char modelo[30];
    int cant_puertas;
};

struct direccion{
    char calle[30];
    int numero_calle;
    char localidad[30];
};

typedef struct{
    int anio;
    struct Datos_Auto Datos_Auto;
    float precio;
    int stock;
} Dato_Auto;

typedef struct{
    char nombre[30];
    char apellido[30];
    struct direccion direccion_cliente;
    int cant_de_autos;
    float presupuesto_anual;
} Dato_Cliente;


int Cargar_Autos(Dato_Auto * p, int cant);
int Cargar_Clientes(Dato_Cliente * p, int cant);
void Visualizar_Autos_Stock(Dato_Auto * p, int cant);
void Visualizar_Clientes(Dato_Cliente * p, int cant);
void Reporte_Esp_Clientes(Dato_Cliente * p, int cant);
void salir();

int main()
{
    int opcion, cant_autos = 0, cant_clientes = 0;

    Dato_Auto autos[CANT], *p_auto;
    Dato_Cliente clientes[CANT], *p_cliente;

    p_auto = &autos[0];
    p_cliente = &clientes[0];

    printf("BIENVENIDO AL SISTEMA DE GESTION DE AUTOS Y CLIENTES\n\n");
    system("pause");
    system("cls");

    do
    {
        printf("1)Ingresar auto\n2)Ingresar cliente\n3)Mostrar autos en stock\n4)Mostrar clientes\n5)Reporte especial\n6)Salir\nIngrese una opcion: ");
        scanf("%d", &opcion);
        printf("\n\n");
        system("pause");
        system("cls");

        switch(opcion)
        {
        case 1:
            if(cant_autos != 5)
            {
                cant_autos = Cargar_Autos(p_auto, cant_autos);
            }
            else
            {
                printf("MAXIMO DE AUTOS ALCANZADO\n\n");
            }
            break;

        case 2:
            if(cant_clientes != 5)
            {
                cant_clientes = Cargar_Clientes(p_cliente, cant_clientes);
            }
            else
            {
                printf("MAXIMO DE CLIENTES ALCANZADO\n\n");
            }
            break;

        case 3:
            Visualizar_Autos_Stock(p_auto, cant_autos);
            break;
        case 4:
            Visualizar_Clientes(p_cliente, cant_clientes);
            break;
        case 5:
            Reporte_Esp_Clientes(p_cliente, cant_clientes);
            break;
        case 6:
            salir();
            break;
        default:
            printf("Opcion incorrecta\n\n");
            break;

        }

        system("pause");
        system("cls");

    } while(opcion != 6);


    return 0;
}

int Cargar_Autos(Dato_Auto * p, int cant)
{
    fflush(stdin);
    printf("Ingrese el anio del auto: ");
    scanf("%d", &(p + cant)->anio);
    fflush(stdin);
    printf("Ingrese la marca del auto: ");
    gets((p + cant)->Datos_Auto.marca);
    fflush(stdin);
    printf("Ingrese el modelo del auto: ");
    gets((p + cant)->Datos_Auto.modelo);
    fflush(stdin);
    printf("Ingrese la cantidad de puertas del auto: ");
    scanf("%d", &(p + cant)->Datos_Auto.cant_puertas);
    printf("Ingrese el precio del auto: ");
    scanf("%f", &(p + cant)->precio);
    printf("Ingrese el stock del auto: ");
    scanf("%d", &(p + cant)->stock);

    return cant + 1;
}

int Cargar_Clientes(Dato_Cliente * p, int cant)
{
    fflush(stdin);
    printf("Ingrese el nombre: ");
    gets((p + cant)->nombre);
    fflush(stdin);
    printf("Ingrese el apellido: ");
    gets((p + cant)->apellido);
    fflush(stdin);
    printf("Ingrese la calle donde vive: ");
    gets((p + cant)->direccion_cliente.calle);
    fflush(stdin);
    printf("Ingrese el numero de calle donde vive: ");
    scanf("%d", &(p + cant)->direccion_cliente.numero_calle);
    fflush(stdin);
    printf("Ingrese la localidad donde vive: ");
    gets((p + cant)->direccion_cliente.localidad);
    fflush(stdin);
    printf("Ingrese la cantidad de autos que posee el cliente: ");
    scanf("%d", &(p + cant)->cant_de_autos);
    printf("Ingrese el presupuesto anual que posee el cliente: ");
    scanf("%f", &(p + cant)->presupuesto_anual);

    return cant + 1;
}

void Visualizar_Autos_Stock(Dato_Auto * p, int cant)
{
    int i = 0;

    if(cant)
    {
        for(i; i < cant; i++)
        {
            if((p + i)->stock > 0)
            {
            printf("auto: %d\nMarca: %s\nModelo: %s\nAnio:%d\nCantidad de puertas: %d\nPrecio: $%.2f\nStock: %d\n\n", i + 1, (p + i)->Datos_Auto.marca, (p + i)->Datos_Auto.modelo, (p + i)->anio, (p + i)->Datos_Auto.cant_puertas, (p + i)->precio, (p + i)->stock);
            }
        }
    }
    else
    {
        printf("NO HAY AUTOS PARA IMPRIMIR\n\n");
    }
}

void Visualizar_Clientes(Dato_Cliente * p, int cant)
{
    int i = 0;

    if(cant)
    {
        for(i; i < cant; i++)
        {
            printf("Cliente %d\nNombre: %s %s\nDireccion: %s %d, %s\nCantidad de autos: %d\nPresupuesto anual: $%.2f\n\n", i + 1, (p + i)->nombre, (p + i)->apellido, (p + i)->direccion_cliente.calle, (p + i)->direccion_cliente.numero_calle, (p + i)->direccion_cliente.localidad, (p + i)->cant_de_autos, (p + i)->presupuesto_anual);
        }
    }
    else
    {
        printf("NO HAY CLIENTES PARA IMPRIMIR\n\n");
    }

}

void Reporte_Esp_Clientes(Dato_Cliente * p, int cant)
{
    int i = 0, cant_esp = 0;

    if(cant)
    {
        for(i; i < cant; i++)
        {
            if((p + i)->cant_de_autos > 2 && (p + i)->presupuesto_anual >= 2000000)
            {
                printf("Cliente %d\nNombre: %s %s\nCantidad de autos: %d\nPresupuesto anual: $%.2f\n\n", i + 1, (p + i)->nombre, (p + i)->apellido, (p + i)->cant_de_autos, (p + i)->presupuesto_anual);
                cant_esp ++;
            }
        }

        if(!cant_esp)
        {
            printf("NO HAY CLIENTES PARA IMPRIMIR\n\n");
        }
    }
    else
    {
        printf("NO HAY CLIENTES PARA IMPRIMIR\n\n");
    }
}

void salir()
{
    printf("**FIN DE PROGRAMA**\n\n");

}
