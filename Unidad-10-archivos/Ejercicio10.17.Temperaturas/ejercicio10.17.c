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

typedef struct {
    char codLoc[11];
    int mes;
    float temperatura;
}Temperatura;

typedef struct {
    char codLoc[11];
    char descrLoc[30];
}Localidad;

typedef struct {
    char codLoc[11];
    float variacion;
}VarTemperatura;

int strcmpi(char* s1, char* s2){
      int i;
      if(strlen(s1)!=strlen(s2))
          return -1;
      for(i=0;i<strlen(s1);i++){
          if(toupper(s1[i])!=toupper(s2[i]))
              return s1[i]-s2[i];
      }
      return 0;
  }

int buscarLocalidad(char[11], Localidad [], int);
void leerLocalidades(Localidad [],int );
void grabarPromedios(float[][3],int[][3],Localidad[]);
void grabarVariaciones(float[][2],int[], Localidad[]);

int main(){

    int matContadores [CANTLOC][3];
    float matSumatoria [CANTLOC][3];
    float matExtremas [CANTLOC][2];
    int flags [CANTLOC];
    Localidad localidades [CANTLOC];
    FILE *pfTemp, *pfProm;
    Temperatura auxT;
    int fila;

    for(int i=0;i<CANTLOC;i++)
        for(int j=0;j<3;j++){
            matSumatoria[i][j]=0.0;
            matContadores[i][j]=0;
        }

    for(int i=0;i<CANTLOC;i++)
        for(int j=0;j<2;j++)
            matExtremas[i][j]=0.0;

    for(int i=0;i<CANTLOC;i++)
        flags[i]=-1;

    leerLocalidades(localidades,CANTLOC);

    //leo y proceso temperaturas.dat

    if ( ( pfTemp = fopen("temperaturas.dat", "rb")) == NULL )
    {
        printf("No se puede abrir temperaturas.dat.\n");
        getchar(); exit(1);
    }

    fread(&auxT, sizeof(Temperatura),1,pfTemp);
    while ( !feof (pfTemp) ){
        fila=buscarLocalidad(auxT.codLoc,localidades,CANTLOC);
        matSumatoria[fila][auxT.mes-1]+=auxT.temperatura;
        matContadores[fila][auxT.mes-1]++;
        //analizo los flags
        if(flags[fila]<0){
            matExtremas[fila][0]=auxT.temperatura;
            matExtremas[fila][1]=auxT.temperatura;
            flags[fila]=1;
        }
        else {
            if(auxT.temperatura<matExtremas[fila][0])
                matExtremas[fila][0]=auxT.temperatura;
            if(auxT.temperatura>matExtremas[fila][1])
                matExtremas[fila][1]=auxT.temperatura;
        }

        fread(&auxT, sizeof(Temperatura),1,pfTemp);
    }
    fclose(pfTemp);

    printf("Localidad\t Ene\tFeb\tMar\tVariacion Termica\n\n");

    for(int i=0;i<CANTLOC;i++){
        printf("%s\t",localidades[i].descrLoc);

        for(int j=0;j<3;j++){
            if(matContadores[i][j]!=0)
                printf("%.2f\t",matSumatoria[i][j]/matContadores[i][j]);
            else printf("?\t");
        }
        printf("%.2f\n", matExtremas[i][1]-matExtremas[i][0]);
    }

    grabarPromedios(matSumatoria,matContadores,localidades);
    grabarVariaciones(matExtremas,flags,localidades);
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

void grabarPromedios(float matSumatoria[][3],int matContadores[][3],Localidad localidades[]){
    FILE *prom;
    Temperatura auxProm;
    if ( ( prom = fopen("promedios.dat", "wb")) == NULL )
    {
        printf("No se puede abrir.\n");
        getchar(); exit(1);
    }

    for(int i=0;i<CANTLOC;i++){
        strcpy(auxProm.codLoc,localidades[i].codLoc);

        for(int j=0;j<3;j++){
            if(matContadores[i][j]!=0){
                auxProm.mes=j+1;
                auxProm.temperatura=matSumatoria[i][j]/matContadores[i][j];
                fprintf(prom,"%s;%d;%.2f\n",auxProm.codLoc,auxProm.mes,auxProm.temperatura);
                // fwrite(&auxProm,sizeof(Temperatura),1,prom);
            }
        }
    }
    fclose(prom);
}

void grabarVariaciones(float matExtremas[][2], int flags[], Localidad localidades[]){
    FILE *pvar;
    VarTemperatura auxVarTemp;

    if ( ( pvar = fopen("variaciones.dat", "wb")) == NULL )
    {
        printf("No se puede abrir.\n");
        getchar(); exit(1);
    }

    for(int i=0;i<CANTLOC;i++){
        if(flags[i]>0){
            strcpy(auxVarTemp.codLoc,localidades[i].codLoc);
            auxVarTemp.variacion=matExtremas[i][1]-matExtremas[i][0];
            fwrite(&auxVarTemp,sizeof(VarTemperatura),1,pvar);
        }
    }
    fclose(pvar);

}
