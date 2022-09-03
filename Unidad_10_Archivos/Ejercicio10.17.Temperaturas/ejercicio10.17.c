/*
   El archivo temperaturas.dat contiene información de las temperaturas registradas en 5 localidades a lo
   largo del primer trimestre del año con la siguiente estructura:
   • Código Localidad (alfanumérico 10 caracteres)
   • Mes (entero 1 a 12)
   • Temperatura (float)
   Por cada localidad pueden existir varias mediciones para un mismo mes, pero no se sabe la cantidad.
   Además, se dispone de un segundo archivo llamado localidades.dat que contiene 5 registros con la
   información de las localidades:
   • Código Localidad (alfanumérico 10 caracteres)
   • Descripción
   Se desea realizar un programa que basado en la información del archivo temperaturas.dat:
   a. Genere un listado de temperaturas promedio en cada localidad en cada mes con el siguiente formato
   (para ello usar una matriz), es posible que para una localidad mes no se tengan lecturas de
   temperaturas por lo tanto deberá mostrarse con un signo de interrogación.
   b. Grabar un archivo llamado promedios.dat que guarde por cada localidad y cada mes el promedio de
   temperaturas donde cada registro contenga: código de localidad, mes y promedio.
   c. Grabar un archivo llamado variaciones.dat que por cada localidad guarde la variación térmica
   (temperatura máxima - temperatura mínima). Los registros de este archivo contendrán dos datos
   código de localidad y el valor de la variación.
   */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define CANTLOC 5

typedef struct 
{
    char codLoc[11];
    int mes;
    float temperatura;
}Temperatura;

typedef struct 
{
    char codLoc[11];
    char descrLoc[30];
}Localidad;

typedef struct 
{
    char codLoc[11];
    float variacion;
}VarTemperatura;

typedef struct 
{
    float acum;
    int contador;
}Promedio;

typedef struct
{
    float min;
    float max;
    int flag;
}Extremas;

int strcmpi(char* s1, char* s2)
{
    int i;
    if(strlen(s1)!=strlen(s2))
        return -1;
    for(i=0;i<strlen(s1);i++)
    {
        if(toupper(s1[i])!=toupper(s2[i]))
            return s1[i]-s2[i];
    }
    return 0;
}

int buscarLocalidad(char[11], Localidad [], int);
void leerLocalidades(Localidad [],int );
void leerYprocesarTemperaturas(Localidad [], Promedio [][3], Extremas [], int);
void grabarPromedios(Promedio [][3],Localidad[]);
void grabarVariaciones(Extremas [], Localidad[]);
void informe(Localidad[], Promedio[][3], Extremas[]);

int main(){

    Promedio matPromedios[CANTLOC][3];
    Extremas extremas[CANTLOC];
    Localidad localidades[CANTLOC];

    FILE *pfProm;
    Temperatura auxT;
    int fila;

    for(int i=0;i<CANTLOC;i++)
        for(int j=0;j<3;j++)
        {
            matPromedios[i][j].acum = 0.0;
            matPromedios[i][j].contador = 0;
        }

    for(int i=0;i<CANTLOC;i++)
    {
        extremas[i].min = 0.0;
        extremas[i].max = 0.0;
        extremas[i].flag = -1;
    }

    leerLocalidades(localidades,CANTLOC);

    leerYprocesarTemperaturas(localidades, matPromedios, extremas, CANTLOC);

    informe(localidades, matPromedios, extremas);

    grabarPromedios(matPromedios, localidades);
    
    grabarVariaciones(extremas, localidades);
}

int buscarLocalidad(char locBuscada[], Localidad localidades[],int tam){
    int encontrado=-1;
    int i=0;
    while(encontrado<0 && i<tam){
        if(strcmpi(locBuscada,localidades[i].codLoc)==0)
            encontrado=i;
        i++;
    }
    return encontrado;
}

void leerLocalidades(Localidad localidades[],int tam){
    FILE *pfLoc;
    if ( ( pfLoc = fopen("localidades.dat", "rb")) == NULL )
    {
        printf("No se puede abrir.\n");
        getchar(); exit(1);
    }
    for(int i=0; i<tam; i++)
        fread(&localidades[i], sizeof(Localidad),1,pfLoc);

    fclose(pfLoc);
}
void leerYprocesarTemperaturas(Localidad localidades[], Promedio matPromedios[][3], Extremas extremas[], int cant)
{
    FILE *pfTemp;
    Temperatura auxT;
    int fila;

    if ( ( pfTemp = fopen("temperaturas.dat", "rb")) == NULL )
    {
        printf("No se puede abrir temperaturas.dat.\n");
        getchar(); exit(1);
    }

    fread(&auxT, sizeof(Temperatura),1,pfTemp);
    while (!feof(pfTemp))
    {
        fila=buscarLocalidad(auxT.codLoc, localidades, cant);
        matPromedios[fila][auxT.mes-1].acum += auxT.temperatura;
        matPromedios[fila][auxT.mes-1].contador ++;
        //analizo los flags
        if(extremas[fila].flag < 0)
        {
            extremas[fila].min = auxT.temperatura;
            extremas[fila].max = auxT.temperatura;
            extremas[fila].flag = 1;
        }
        else {
            if(auxT.temperatura < extremas[fila].min)
                extremas[fila].min = auxT.temperatura;
            if(auxT.temperatura > extremas[fila].max)
                extremas[fila].max = auxT.temperatura;
        }

        fread(&auxT, sizeof(Temperatura),1,pfTemp);
    }
    fclose(pfTemp);
}

void grabarPromedios(Promedio matPromedios[][3],Localidad localidades[]){
    FILE *prom;
    Temperatura auxProm;
    if ( ( prom = fopen("promedios.dat", "wb")) == NULL )
    {
        printf("No se puede abrir.\n");
        getchar(); 
        exit(1);
    }

    for(int i=0;i<CANTLOC;i++){
        strcpy(auxProm.codLoc,localidades[i].codLoc);

        for(int j=0;j<3;j++){
            if(matPromedios[i][j].contador != 0){
                auxProm.mes=j+1;
                auxProm.temperatura=matPromedios[i][j].acum / matPromedios[i][j].contador;
                fprintf(prom,"%s;%d;%.2f\n", auxProm. codLoc, auxProm.mes, auxProm.temperatura);
                // fwrite(&auxProm,sizeof(Temperatura),1,prom);
            }
        }
    }
    fclose(prom);
}

void informe(Localidad localidades[], Promedio matPromedios[][3], Extremas extremas[])
{

    printf("Localidad\tEne\tFeb\tMar\tVariacion Termica\n\n");

    for(int i=0;i<CANTLOC;i++){
        printf("%s\t",localidades[i].descrLoc);

        for(int j=0;j<3;j++){
            if(matPromedios[i][j].contador != 0)
                printf("%.2f\t", matPromedios[i][j].acum / matPromedios[i][j].contador);
            else printf("?\t");
        }
        printf("%.2f\n", extremas[i].max - extremas[i].min);
    }
}
void grabarVariaciones(Extremas extremas[], Localidad localidades[]){
    FILE *pvar;
    VarTemperatura auxVarTemp;

    if ( ( pvar = fopen("variaciones.dat", "wb")) == NULL )
    {
        printf("No se puede abrir.\n");
        getchar(); 
        exit(1);
    }

    for(int i=0;i<CANTLOC;i++){
        if(extremas[i].flag > 0){
            strcpy(auxVarTemp.codLoc, localidades[i].codLoc);
            auxVarTemp.variacion = extremas[i].max - extremas[i].min;
            fwrite(&auxVarTemp, sizeof(VarTemperatura), 1, pvar);
        }
    }
    fclose(pvar);

}
