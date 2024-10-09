#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    char vehiculo_tipo[6];
    char patente[9];
    int velocidad_registrada;
    char estado[7];
} vehiculo;

int Registrar(vehiculo * punt, FILE * fv, FILE * fm);
int Listar(vehiculo * punt, FILE * fv);
int Listar_Multados(vehiculo * punt, FILE * fv);
int Buscar_Vehiculo(vehiculo * punt, FILE * fv);
int Editar_Vehiculo(vehiculo * punt, FILE * fv);
void Escribir_hora(FILE * fm);
void Salir();

int main()
{
    int opcion = 0, retorno;
    srand(time(NULL));

    FILE * fv = NULL;
    FILE * fm = NULL;

    vehiculo * punt = NULL;
    punt = (vehiculo *) malloc(sizeof(vehiculo));

    printf("BIENVENIDO AL SISTEMA DE MULTAS\n");

    do{
        printf("\n");
        system("pause");
        system("cls");

        printf("1) Registrar auto\n2) Listar vehículos registrados\n3) Listar vehículos multados\n4) Buscar vehículos\n5) Editar vehículo\n6) Salir\nElija la opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                retorno = Registrar(punt, fv, fm);
                if (retorno == 0)
                {
                    printf("\n\nVEHICULO REGISTRADO\n");
                }

                break;
            case 2:
                Listar(punt, fv);
                break;
            case 3:
                Listar_Multados(punt, fv);
                break;
            case 4:
                Buscar_Vehiculo(punt, fv);
                break;
            case 5:
                Editar_Vehiculo(punt, fv);
                break;
            case 6:
                Salir();
                break;
            default:
                printf("\n\nOPCION INCORRECTA\n\n");
                break;
        }
    } while(opcion !=6);
    return 0;
}

int Registrar(vehiculo * punt, FILE * fv, FILE * fm)
{
    printf("\n");
    system("pause");
    system("cls");

    int retorno_vehi, retorno_multas, i;

    fv = fopen("autos.bin", "ab");

    if(fv == NULL)
    {
        printf("\n\nERROR AL ABRIR ARCHIVO VEHICULOS\n");
        return -1;
    }

    fm = fopen("multados.txt", "ab");

    if(fm == NULL)
    {
        printf("\n\nERROR AL ABRIR ARCHIVO MULTAS\n");
        return -1;
    }

    printf("\nIngrese el tipo de vehiculo (auto/moto/camion): ");
    fflush(stdin);
    gets(punt->vehiculo_tipo);
    for(i = 0; i < strlen(punt->vehiculo_tipo); i++){
        punt->vehiculo_tipo[i] = tolower(punt->vehiculo_tipo[i]);
    }

    while(stricmp(punt->vehiculo_tipo, "auto") != 0 && stricmp(punt->vehiculo_tipo, "moto") != 0 && stricmp(punt->vehiculo_tipo, "camion") != 0)
    {
        printf("Tipo incorrecto. Ingrese el tipo de vehiculo (auto/moto/camion): ");
        fflush(stdin);
        gets(punt->vehiculo_tipo);
        for(i = 0; i < strlen(punt->vehiculo_tipo); i++){
            punt->vehiculo_tipo[i] = tolower(punt->vehiculo_tipo[i]);
        }
    }

    printf("Ingrese la patente (XXXX123BB): ");
    fflush(stdin);
    gets(punt->patente);
    for(i = 0; i < strlen(punt->patente); i++){
        punt->patente[i] = toupper(punt->patente[i]);
    }

    while(!(isalpha(punt->patente[0]) && isalpha(punt->patente[1]) && isalpha(punt->patente[2]) && isalpha(punt->patente[3]) && isdigit(punt->patente[4]) && isdigit(punt->patente[5]) && isdigit(punt->patente[6]) && isalpha(punt->patente[7]) && isalpha(punt->patente[8])))
    {
        printf("Patente incorrecta. Ingrese la patente (XXXX123BB): ");
        fflush(stdin);
        gets(punt->patente);
        for(i = 0; i < strlen(punt->patente); i++){
            punt->patente[i] = toupper(punt->patente[i]);
        }
    }

    punt->velocidad_registrada = rand() % 241 + 10;

    if(punt->velocidad_registrada > 80)
    {
        strcpy(punt->estado, "multado");
    }
    else
    {
        strcpy(punt->estado, "normal");
    }

    fwrite(punt, sizeof(vehiculo), 1, fv);
    fputc('\n', fv);


    Escribir_hora(fm);
    fprintf(fm, "\nVehiculo Tipo: %s\nPatentes: %s\nVelocidad registrada %dkm\nEstado %s\n", punt->vehiculo_tipo, punt->patente, punt->velocidad_registrada, punt->estado);

    fclose(fv);
    fclose(fm);

    return 0;
}


void Escribir_hora(FILE * fm)
{
    time_t t;
    struct tm *timeinfo;
    time(&t);
    timeinfo = localtime(&t);
    fprintf(fm, "%02d:%02d:%02d Multado", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
}

int Listar(vehiculo * punt, FILE * fv)
{
    printf("\n");
    system("pause");
    system("cls");

    int cant_autos, i = 0;

    fv = fopen("autos.bin", "rb");

    if(fv == NULL)
    {
        printf("\n\nERROR AL ABRIR ARCHIVO VEHICULOS\n");
        return -1;
    }

    fseek(fv, 0, SEEK_END);
    cant_autos = ftell(fv) / (sizeof(vehiculo) + 1);

    rewind(fv);

    fread(punt, sizeof(vehiculo), 1, fv);

    while(!feof(fv))
    {
        i = i + 1;
        printf("Auto %d\nTipo: %s\nPatente: %s\nVelocidad registrada: %dkm/h\nestado: %s\n\n", i, punt->vehiculo_tipo, punt->patente, punt->velocidad_registrada, punt->estado);
        fgetc(fv);
        fread(punt, sizeof(vehiculo), 1, fv);
    }

    if(cant_autos)
    {
        printf("\nVehiculos registrados: %d\n", cant_autos);
    }
    else
    {
        printf("NO HAY AUTOS A LISTAR\n");
    }

    fclose(fv);

    return 0;
}

int Listar_Multados(vehiculo * punt, FILE * fv)
{
    printf("\n");
    system("pause");
    system("cls");

    int cant_multados = 0, i = 0;

    fv = fopen("autos.bin", "rb");

    if(fv == NULL)
    {
        printf("\n\nERROR AL ABRIR ARCHIVO VEHICULOS\n");
        return -1;
    }

    fread(punt, sizeof(vehiculo), 1, fv);

    printf("LISTA DE MULTADOS\n\n");

    while(!feof(fv))
    {
        i = i + 1;
        if(strcmp(punt->estado, "multado") == 0)
        {
            printf("Auto %d\nTipo: %s\nPatente: %s\nVelocidad registrada: %dkm/h\nestado: %s\n\n", i, punt->vehiculo_tipo, punt->patente, punt->velocidad_registrada, punt->estado);
            cant_multados ++;
        }
        fgetc(fv);
        fread(punt, sizeof(vehiculo), 1, fv);
    }

    if(cant_multados)
    {
        printf("\nSe cuenta con %d vehuculos multados sumando una recaudación de $%d\n", cant_multados, cant_multados * 50000);
    }
    else
    {
        printf("\nNO HAY VAHICULOS MULTADOS\n");
    }



    fclose(fv);

    return 0;
}

int Buscar_Vehiculo(vehiculo * punt, FILE * fv)
{
    printf("\n");
    system("pause");
    system("cls");

    int i = 0, multado = 0, cant_apariciones = 0;
    char patente_buscado[9];


    printf("Ingrese la patente a buscar: ");
    fflush(stdin);
    gets(patente_buscado);
    fflush(stdin);

    fv = fopen("autos.bin", "rb");

    if(fv == NULL)
    {
        printf("\n\nERROR AL ABRIR ARCHIVO VEHICULOS\n");
        return -1;
    }

    fread(punt, sizeof(vehiculo), 1, fv);

    while(!feof(fv))
    {
        if(stricmp(punt->patente, patente_buscado) == 0)
        {
            if(!cant_apariciones)
            {
                printf("\n\nPATENTE ENCONTRADA\nTipo: %s\nPatente: %s", punt->vehiculo_tipo, punt->patente, punt->velocidad_registrada, punt->estado);
            }

            cant_apariciones ++;

            if(strcmp(punt->estado, "multado") ==0){
                multado = 1;
                break;
            }
        }

        fgetc(fv);
        fread(punt, sizeof(vehiculo), 1, fv);
    }

    if(multado)
    {
        printf("\nEstado: multado\n");
    }
    else if(cant_apariciones)
    {
        printf("\nEstado: normal\n");
    }
    else if (!cant_apariciones) {
        printf("\n\nPATENTE NO ENCONTRADA\n");
    }

    fclose(fv);

    return 0;
}


int Editar_Vehiculo(vehiculo * punt, FILE * fv)
{
    printf("\n");
    system("pause");
    system("cls");

    char patente_buscado[9];
    int i = 0, editar = 0, cant_apariciones = 0;

    printf("Ingrese la patente a buscar: ");
    fflush(stdin);
    gets(patente_buscado);
    fflush(stdin);

    fv = fopen("autos.bin", "rb+");

    if(fv == NULL)
    {
        printf("\n\nERROR AL ABRIR ARCHIVO VEHICULOS\n");
        return -1;
    }

    fread(punt, sizeof(vehiculo), 1, fv);

    while(!feof(fv))
    {
        i = i + 1;
        if(stricmp(punt->patente, patente_buscado) == 0)
        {
            cant_apariciones ++;
            printf("\n\nAuto %d\nTipo: %s\nPatente: %s\nVelocidad registrada: %dkm/h\nestado: %s\n\n", i, punt->vehiculo_tipo, punt->patente, punt->velocidad_registrada, punt->estado);

            printf("Desea editar este registro? (1/0): ");
            scanf("%d", &editar);

            while (editar != 0 && editar != 1)
            {
                printf("Opcion invalida. Ingrese 1 o 0: ");
                scanf("%d", &editar);
            }

            if(editar)
            {
                printf("\nIngrese el tipo de vehiculo (auto/moto/camion): ");
                fflush(stdin);
                gets(punt->vehiculo_tipo);
                for(i = 0; i < strlen(punt->vehiculo_tipo); i++){
                    punt->vehiculo_tipo[i] = tolower(punt->vehiculo_tipo[i]);
                }

                while(strcmp(punt->vehiculo_tipo, "auto") != 0 && strcmp(punt->vehiculo_tipo, "moto") != 0 && strcmp(punt->vehiculo_tipo, "camion") != 0)
                {
                    printf("Tipo incorrecto. Ingrese el tipo de vehiculo (auto/moto/camion): ");
                    fflush(stdin);
                    gets(punt->vehiculo_tipo);
                    for(i = 0; i < strlen(punt->vehiculo_tipo); i++){
                        punt->vehiculo_tipo[i] = tolower(punt->vehiculo_tipo[i]);
                    }
                }

                printf("Ingrese la patente (XXXX123BB): ");
                fflush(stdin);
                gets(punt->patente);
                for(i = 0; i < strlen(punt->patente); i++){
                    punt->patente[i] = toupper(punt->patente[i]);
                }

                while(!(isalpha(punt->patente[0]) && isalpha(punt->patente[1]) && isalpha(punt->patente[2]) && isalpha(punt->patente[3]) && isdigit(punt->patente[4]) && isdigit(punt->patente[5]) && isdigit(punt->patente[6]) && isalpha(punt->patente[7]) && isalpha(punt->patente[8])))
                {
                    printf("Patente incorrecta. Ingrese la patente (XXXX123BB): ");
                    fflush(stdin);
                    gets(punt->patente);
                    for(i = 0; i < strlen(punt->patente); i++){
                        punt->patente[i] = toupper(punt->patente[i]);
                    }
                }

                printf("Ingrese la velocidad: ");
                fflush(stdin);
                scanf("%d", &punt->velocidad_registrada);

                printf("Ingrese si el vehiculo esta normal o multado: ");
                fflush(stdin);
                gets(punt->estado);
                for(i = 0; i < strlen(punt->estado); i++){
                    punt->estado[i] = tolower(punt->estado[i]);
                }

                while(strcmp(punt->estado, "multado") != 0 && strcmp(punt->estado, "normal") != 0)
                {
                    printf("Estado incorrecto. Ingrese si el vehiculo esta normal o multado: ");
                    fflush(stdin);
                    gets(punt->estado);
                    for(i = 0; i < strlen(punt->estado); i++){
                        punt->estado[i] = tolower(punt->estado[i]);
                    }
                }

                fseek(fv, -(sizeof(vehiculo)), SEEK_CUR);
                fwrite(punt, sizeof(vehiculo), 1, fv);
                fseek(fv, 1, SEEK_CUR);
            }
        }

        fgetc(fv);
        fread(punt, sizeof(vehiculo), 1, fv);
    }

    if(!cant_apariciones)
    {
        printf("\n\nPATENTE NO ENCOTNRADA\n");
    }

    fclose(fv);

    return 0;
}

void Salir()
{
    printf("\n");
    system("pause");
    system("cls");
    printf("FIN\n\n");
}
