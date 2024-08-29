#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define CANT 30

struct info{
    char nombre[30];
    char apellido[30];
    char dni[30]
};

struct direccion{
    char calle[30];
    int altura;
    int cp;
};

typedef struct{
    struct info remitente;
    struct info destinatario;
    struct direccion direc;
    char telefono[30];
    int marca;
    int tipo;
} paquete;


int Agregar_Paquete(paquete * p, int cant);
void Reporte_x_cp(paquete * p, int cant);
void Actualizar_Estado_Entrega(paquete * p, int cant);
void Listar_Paquetes_Pendientes(paquete * p, int cant);
void salir();

int main()
{
    int opcion, cant_paquetes;

    paquete paquetes[CANT], * p;

    p = &paquetes[0];

    printf("BIENVENIDO AL SISTEMA DE GESTION DE PAQUETES\n\n");
    system("pause");
    system("cls");

    do
    {
        printf("1)Ingresar paquete\n2)Reporte de paquetes por cp\n3)Actualizar estado de entrega\n4)Listar paquetes pendientes\n5)Salir\nIngrese una opcion: ");
        scanf("%d", &opcion);
        printf("\n\n");
        system("pause");
        system("cls");

        switch(opcion)
        {
        case 1:
            cant_paquetes = Agregar_Paquete(p, cant_paquetes);
            break;

        case 2:
            Reporte_x_cp(p, cant_paquetes);
            break;

        case 3:
            Actualizar_Estado_Entrega(p, cant_paquetes);
            break;
        case 4:
            Listar_Paquetes_Pendientes(p, cant_paquetes);
            break;
        case 5:
            salir();
            break;
        default:
            printf("Opcion incorrecta\n\n");
            break;

        }

        system("pause");
        system("cls");

    } while(opcion != 5);


    return 0;
}

int Agregar_Paquete(paquete * p, int cant)
{
    int seguir;

    do
    {
        if(cant!= CANT)
        {
            fflush(stdin);
            printf("Ingrese el nombre del remitente: ");
            gets((p + cant)->remitente.nombre);
            fflush(stdin);
            printf("Ingrese el apellido del remitente: ");
            gets((p + cant)->remitente.apellido);
            fflush(stdin);
            printf("Ingrese el dni del remitente: ");
            gets((p + cant)->remitente.dni);
            fflush(stdin);
            printf("Ingrese el nombre del destinatario: ");
            gets((p + cant)->destinatario.nombre);
            fflush(stdin);
            printf("Ingrese el apellido del destinatario: ");
            gets((p + cant)->destinatario.apellido);
            fflush(stdin);
            printf("Ingrese el dni del destinatario: ");
            gets((p + cant)->destinatario.dni);
            fflush(stdin);
            printf("Ingrese la calle del domicilio de destino: ");
            gets((p + cant)->direc.calle);
            fflush(stdin);
            printf("Ingrese la altura del domicilio de destino: ");
            scanf("%d", &(p + cant)->direc.altura);
            printf("Ingrese el cp del domicilio de destino: ");
            scanf("%d", &(p + cant)->direc.cp);

            while((p + cant)->direc.cp / 1000.00 > 10 || (p + cant)->direc.cp / 1000.00 < 1)
            {
                printf("El cp del domicilio de destino debe tener 4 digitos: ");
                scanf("%d", &(p + cant)->direc.cp);
            }

            fflush(stdin);
            printf("Ingrese el telefono de contacto: ");
            gets((p + cant)->telefono);
            fflush(stdin);
            printf("Ingrese la marca de entrega (0: entregado | 1: no): ");
            scanf("%d", &(p + cant)->marca);

            while((p + cant)->marca != 0 && (p + cant)->marca != 1)
            {
                printf("Por favor ingrese una opcion correcta: ");
                scanf("%d", &(p + cant)->marca);
            }

            printf("Ingrese el tipo de entrega (0: 24hs | 1: 48hs | 2: normal): ");
            scanf("%d", &(p + cant)->tipo);

            while((p + cant)->tipo != 0 && (p + cant)->tipo != 1 && (p + cant)->tipo != 2)
            {
                printf("Por favor ingrese una opcion correcta: ");
                scanf("%d", &(p + cant)->tipo);
            }

            printf("\n\nDesea ingresar otro paquete?\n0)Si\n1)No\nIngresar una opcion: ");
            scanf("%d", &seguir);

            while(seguir != 0 && seguir != 1)
            {
                printf("Por favor ingrese una opcion correcta: ");
                scanf("%d", &seguir);
            }

            printf("\n");

            if(!seguir)
            {
                system("pause");
                system("cls");
            }

            cant ++;
        }
        else
        {
            printf("MAXIMO DE PAQUETES ALCANZADO\n\n");
            seguir = 1;;
        }
    } while(seguir == 0);

    return cant;
}

void Reporte_x_cp(paquete * p, int cant)
{
    int buscado, encontrado, seguir, i;

    do
    {
        seguir = 1;
        encontrado = 0;
        printf("Ingrese un cp a buscar: ");
        scanf("%d", &buscado);
        printf("\n");

        for(i = 0; i < cant; i++)
        {
            if((p + i)->direc.cp == buscado)
            {
                encontrado += 1;
                printf("Remitente: %s\nDestinatario\nDomicilio: %s %d (%d)\nTipo de envio: ", (p + i)->remitente.apellido, (p + i)->destinatario.apellido, (p + i)->direc.calle, (p + i)->direc.altura, (p + i)->direc.cp);
                if((p + i)->tipo == 0)
                {
                    printf("24hs\n");
                }
                else if((p + i)->tipo == 1)
                {
                    printf("48hs\n");
                }
                else
                {
                    printf("normal\n");
                }
                printf("--------------------------------------\n\n");
            }
        }

        if(encontrado)
        {
            printf("Cantidad de paquetes en cp %d: %d\n\n", buscado, encontrado);
        }
        else
        {
            printf("NO SE HAN ENCONTRADO PAQUETES EN EL CP BUSCADO\n\nDesea buscar otro?\n0)Si\n1)No\nIngresar una opcion: ");
            scanf("%d", &seguir);

            while(seguir != 0 && seguir != 1)
            {
                printf("Por favor ingrese una opcion correcta: ");
                scanf("%d", &seguir);
            }

            printf("\n");

            if(!seguir)
            {
                system("pause");
                system("cls");
            }

        }


    } while(seguir == 0);
}

void Actualizar_Estado_Entrega(paquete * p, int cant)
{
    int altura_buscada, i, posicion = -1, actualizar;
    char calle_buscada[30];

    fflush(stdin);
    printf("Ingrese la calle buscada: ");
    gets(calle_buscada);
    fflush(stdin);
    printf("Ingrese la altura buscada: ");
    scanf("%d", &altura_buscada);

    for(i = 0; i < cant; i++)
    {
        if(stricmp((p + i)->direc.calle, calle_buscada) == 0 && (p + i)->direc.altura == altura_buscada)
        {
            posicion = i;
            printf("\nPaquete nro %d\nRemitente: %s\nDestinatario: %s\nDomicilio: %s %d (%d)\nEstado de entrega: ", i + 1, (p + i)->remitente.apellido, (p + i)->destinatario.apellido, (p + i)->direc.calle, (p + i)->direc.altura, (p + i)->direc.cp);
            if((p + i)->marca == 0)
            {
                printf("Entregado");
            }
            else
            {
                printf("No Entregado");
            }
        }
    }

    if(posicion == -1)
    {
        printf("\nDOMICILIO NO ENCONTRADO\n\n");
    }
    else{
        printf("\n\nDesea actualizar el estado de entrega?\n0)Si\n1)No\nIngrese una opcion: ");
        scanf("%d", &actualizar);

        while(actualizar != 0 && actualizar != 1)
        {
            printf("Ingrese una opcion correcta: ");
            scanf("%d", &actualizar);
        }

        printf("\n");

        if(!actualizar)
        {
            if((p + posicion)->marca)
            {
                (p + posicion)->marca = 0;
            }
            else
            {
                (p + posicion)->marca = 1;
            }

            printf("ESTADO DE ENTREGA ACTUALIZADO\n\n");
        }
    }
}

void Listar_Paquetes_Pendientes(paquete * p, int cant)
{
    int i, cant_0 = 0, cant_1 = 0, cant_2 = 0;

    for(i = 0; i < cant; i++)
    {
        if((p + i)->marca == 1)
        {
            printf("Paquete nro %d\nRemitente: %s\nDestinatario: %s\nDomicilio: %s %d (%d)\nTelefono: %s\n Tipo de envio: ", i + 1, (p + i)->remitente.apellido, (p + i)->destinatario.apellido, (p + i)->direc.calle, (p + i)->direc.altura, (p + i)->direc.cp, (p + i)->telefono);
            if((p + i)->tipo == 0)
            {
                printf("24hs");
                cant_0 ++;
            }
            else if((p + i)->tipo == 0)
            {
                printf("48hs");
                cant_1 ++;
            }
            else
            {
                printf("normal");
                cant_2 ++;
            }

            printf("\n--------------------------------------\n\n");
        }
    }

    if(cant_0 + cant_1 + cant_2)
    {
        printf("Total envios de 24hs: %d\nTotal envios de 48hs: %d\nTotal envios normales: %d\n\n", cant_0, cant_1, cant_2);
    }
    else{
        printf("NO HAY ENVIOS PENDIENTES\n\n");
    }

}

void salir()
{
    printf("**FIN DE PROGRAMA**\n\n");

}
