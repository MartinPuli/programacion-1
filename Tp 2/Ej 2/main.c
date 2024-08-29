#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define CANT 100

struct Razon_Social{
    char nombre[50];
    char tipo_empresa[10];
    int cant_empleados;
    char estado[12];
};

typedef struct{
    struct Razon_Social razon;
    char cuit[11];
    char nro_factura[5];
    float importe;
    float IVA;
    float IIBB;
} factura;


int ingreso_factura(factura * p, int cant);
void visualizar_impuestos(factura * p, int cant);
void visualizar_facturas(factura * p, int cant);
int comprobarNumero(char cadena[5]);
void salir();

int main()
{
    int opcion, cant_facturas;

    factura facturas[CANT], * p;

    p = &facturas[0];

    printf("BIENVENIDO AL SISTEMA DE GESTION DE FACTURAS\n\n");
    system("pause");
    system("cls");

    do
    {
        printf("1)Ingresar factura\n2)Visualizar impuestos\n3)Visualizar facturas\n4)Salir\nIngrese una opcion: ");
        scanf("%d", &opcion);
        printf("\n\n");
        system("pause");
        system("cls");

        switch(opcion)
        {
        case 1:
            if(cant_facturas != CANT)
            {
                cant_facturas = ingreso_factura(p, cant_facturas);
            }
            else
            {
                printf("MAXIMO DE FACTURAS ALCANZADO\n\n");
            }
            break;

        case 2:
            visualizar_impuestos(p, cant_facturas);
            break;

        case 3:
            visualizar_facturas(p, cant_facturas);
            break;
        case 4:
            salir();
            break;
        default:
            printf("Opcion incorrecta\n\n");
            break;

        }

        system("pause");
        system("cls");

    } while(opcion != 4);


    return 0;
}

int ingreso_factura(factura * p, int cant)
{
    fflush(stdin);
    printf("Ingrese el nombre de la empresa: ");
    gets((p + cant)->razon.nombre);
    fflush(stdin);
    printf("Ingrese el tipo de la empresa (SRL|SA|SAICI): ");
    gets((p + cant)->razon.nombre);
    fflush(stdin);

    while(strcmp((p + cant)->razon.nombre, "SRL") !=0 && strcmp((p + cant)->razon.nombre, "SA") !=0 && strcmp((p + cant)->razon.nombre, "SAICI") !=0)
    {
        printf("Ingrese un tipo valido (SRL|SA|SAICI): ");
        gets((p + cant)->razon.nombre);
        fflush(stdin);
    }

    printf("Ingrese la cantidad de empleados de la empresa: ");
    scanf("%d", &(p + cant)->razon.cant_empleados);
    fflush(stdin);
    printf("Ingrese el estado de la empresa (activo|inactivo): ");
    gets((p + cant)->razon.estado);
    fflush(stdin);

    while(stricmp((p + cant)->razon.estado, "inactivo") !=0 && stricmp((p + cant)->razon.estado, "activo") !=0)
    {
        fflush(stdin);
        printf("Ingrese un estado valido (inactivo|activo): ");
        gets((p + cant)->razon.estado);
        fflush(stdin);
    }

    fflush(stdin);
    printf("Ingrese el cuit de la empresa: ");
    gets((p + cant)->cuit);
    fflush(stdin);
    printf("Ingrese el numero de factura de 5 digitos: ");
    gets((p + cant)->nro_factura);
    fflush(stdin);

    while(strlen((p + cant)->nro_factura) != 5 || !comprobarNumero((p + cant)->nro_factura))
    {

        printf("Ingrese un nro de factura valido: ");
        gets((p + cant)->nro_factura);
        fflush(stdin);
    }

    printf("Ingrese el importe de la factura: ");
    scanf("%f", &(p + cant)->importe);

    (p + cant)->IVA = (p + cant)->importe * 0.21;
    (p + cant)->IIBB = (p + cant)->importe * 0.035;

    return cant + 1;
}

void visualizar_impuestos(factura * p, int cant)
{
    int i = 0;
    float total_IVA = 0, total_IIBB = 0;

    if(cant)
    {
        for(i; i < cant; i++)
        {
            printf("Factura: %s\nIVA: %.2f\nIIBB: %.2f\n\n", (p + i)->nro_factura, (p + i)->IVA, (p + i)->IIBB);
            total_IVA += (p + i)->IVA;
            total_IIBB += (p + i)->IIBB;
        }

        printf("Total IVA: $%.2f\nTotal IIBB: $%.2f\n\n", total_IVA, total_IIBB);
    }
    else
    {
        printf("NO HAY FACTURAS INGRESADAS\n\n");
    }
}

void visualizar_facturas(factura * p, int cant)
{
    int i = 0;
    float total_importe = 0, total_IVA = 0, total_IIBB = 0;

    if(cant)
    {
        for(i; i < cant; i++)
        {
            total_importe += (p + i)->importe;
            total_IVA += (p + i)->IVA;
            total_IIBB += (p + i)->IIBB;
        }

        printf("Total Importe: $%.2f\nTotal IVA: $%.2f\nTotal IIBB: $%.2f\n\nBeneficio Neto: $%.2f\n\n", total_importe, total_IVA, total_IIBB, total_importe - total_IVA - total_IIBB);
    }
    else
    {
        printf("NO HAY FACTURAS INGRESADAS\n\n");
    }
}

int comprobarNumero(char cadena[5]){
    int i = 0, numero = 1;

    for(i; i < 5; i++)
    {
        if(isdigit(cadena[i]) == 0)
        {
            numero = 0;
        }
    }

    return numero;
}

void salir()
{
    printf("**FIN DE PROGRAMA**\n\n");

}
