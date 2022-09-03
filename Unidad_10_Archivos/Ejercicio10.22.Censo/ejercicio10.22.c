/*Para estudiar la población extranjera en la Argentina, se decide realizar un censo por las distintas
  provincias. Para ello, se dispone del archivo PROVINCIAS de 24 registros de dos campos:
• Código de Provincia (cadena de 3 posiciones)
• Nombre de la Provincia (cadena de 30 posiciones) Argentina tiene 24 provincias, incluyendo CABA.
La información sobre el censo realizado se encuentra en un archivo secuencial (CENSO) cuyos registros
están formados por:
•
Código de Provincia
•
Nacionalidad (entero 1 a 50)
•
Cantidad de habitantes (entero, mayor a cero)
El archivo no está ordenado.
En el archivo secuencial (MODIF_CENSO), que tampoco está ordenado, se tienen modificaciones, cuyo
formato de registro es:
•
Código de modificación (carácter:  ́A ́ o  ́M ́)
•
Código de Provincia
•
Nacionalidad
•
Cantidad (entero, mayor a cero)
Si el código de modificación es  ́A ́, debe sumarse la Cantidad a la existente; si es  ́M ́, debe reemplazarse
Cantidad de Habitantes con la informada. Se pide:
a. Almacenar la información del archivo en memoria utilizando una estructura adecuada. Puede ocurrir
que no haya información alguna Provincia – Nacionalidad, en cuyo caso se asume 0 habitantes.
b. Actualizar los datos con las modificaciones.
c. Informar el total de habitantes por Provincia ordenado en forma descendente por cantidad de
habitantes.
d. Grabar el archivo actualizado.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char codProv[4];
	char nomProv[31];
}Provincia;

typedef struct
{
    char codProv[4];
    int nacion;
    int cantHab;
}Censo;

typedef struct
{
    char codModif;
    char codProv[4];
    int nacion;
    int cantHab;
}ModifCenso;

typedef struct
{
    int fila;
    int total;
}Total;


void leerProvincias(FILE *fprov, Provincia provincias[],int);

void leerCenso(FILE *fcenso,Provincia provincias[],int matDatos[][50]);

void leerModifCenso(FILE *fModifCenso,int matDatos[][50],Provincia provincias[]);

int buscar(Provincia [], char[], int);

void totalizar(Total [],int[][50]);

void ordenar(Total t[],int cant);

void actualizarCenso(FILE *fcenso, Provincia p[], int matDatos[][50],int f,int c);

void mostrar(Total t[], Provincia [], int cant);

int main(int argc, char *argv[])
{
    Provincia provincias[24];
    int matDatos[24][50];
    Total totales[24];

    for(int i=0;i<24;i++)
        for(int j=0;j<50;j++)
            matDatos[i][j]=0;

    FILE *fprov, *fcenso, *fModifCenso, *export;

    leerProvincias(fprov,provincias,24);
    leerCenso(fcenso,provincias,matDatos);
    leerModifCenso(fModifCenso,matDatos,provincias);
    totalizar(totales,matDatos);
    ordenar(totales,24);
    mostrar(totales,provincias,24);
    actualizarCenso(fcenso,provincias,matDatos,24,50);
    return 0;
}

void actualizarCenso(FILE *fcenso, Provincia p[],int matDatos[][50],int f,int c)
{
    if((fcenso = fopen("./censo.dat","wb"))==NULL){
        printf("ERROR al abrir censo.dat");
        getchar();
        exit(1);
    }
    Censo auxC;
    for(int i=0;i<f;i++)
    {
      for(int j=0;j<c;j++)
      {
        if(matDatos[i][j]!=0)
        {
            strcpy(auxC.codProv,p[i].codProv);
            auxC.cantHab=matDatos[i][j];
            auxC.nacion=j+1;
            fwrite(&auxC,sizeof(Censo),1,fcenso);
        }
      }
    }
    fclose(fcenso);
}

int buscar(Provincia p [],char cp[],int tam){
    int i=0,encontrado=-1;
    while(encontrado<0 && i<tam){
        if(strcmp(p[i].codProv, cp)==0)
            encontrado=i;
        i++;
    }
    //printf("%d\n",encontrado);
    return encontrado;
}

void totalizar(Total t[24],int m[24][50]){
    int auxTotal=0;
    for (int i=0;i<24;i++){
        auxTotal=0;
        for(int j=0;j<50;j++)
            auxTotal+=m[i][j];
        t[i].fila=i;
        t[i].total=auxTotal;
        //if(t[i].total!=0)
        //printf("%d\t%d\n",t[i].fila,t[i].total);
    }
}
void ordenar(Total t[],int cant)
{
    int i,j;
	Total aux;
	for (i=0;i<cant-1;i++)
	{
		for (j=0;j<cant-1-i;j++)
		{
			if (t[j].total <t[j+1].total)
			{
				aux= t[j];
				t[j]=t[j+1];
				t[j+1]=aux;
			}
		}
    }

}


void mostrar(Total t[], Provincia p[], int cant)
{

    printf("Provincia\tTotal Extranjeros\n");
    for(int i=0;i<cant;i++)
     if(t[i].total!=0)
      printf("%s\t\t\t%d\n",p[t[i].fila].nomProv,t[i].total);
}


void leerCenso(FILE *fcenso,Provincia provincias[],int matDatos[][50])
{
    if((fcenso = fopen("./censo.dat","rb"))==NULL){
        printf("ERROR");
        getchar();
        exit(1);
    }
    int fila=0;
    Censo censoAux;
    fread(&censoAux,sizeof(Censo),1,fcenso);
    while(!feof(fcenso)){
        fila=buscar(provincias,censoAux.codProv,24);

        if(fila>=0)
            matDatos[fila][censoAux.nacion-1]=censoAux.cantHab;

        fread(&censoAux,sizeof(Censo),1,fcenso);
    }
    fclose(fcenso);

}


void leerProvincias(FILE *fprov, Provincia provincias[],int cant)
{
    if ((fprov = fopen("./provincias.dat","rb"))==NULL) {
        printf("ERROR al abrir provincias.dat");
        getchar();
        exit(1);
    }

     for (int i = 0; i < cant; i++) {
        fread(&provincias[i],sizeof(Provincia),1,fprov);
    }
    fclose(fprov);
}

void leerModifCenso(FILE *fModifCenso,int matDatos[][50],Provincia provincias[])
{
    if((fModifCenso = fopen("./modif_censo.dat","rb"))==NULL){
        printf("ERROR");
        getchar();
        exit(1);
    }
    ModifCenso MCaux;
    int fila;
    fread(&MCaux,sizeof(ModifCenso),1,fModifCenso);
    while(!feof(fModifCenso)){
        fila=buscar(provincias,MCaux.codProv,24);
        if(MCaux.codModif=='A')
            matDatos[fila][MCaux.nacion-1]+=MCaux.cantHab;
        else
            matDatos[fila][MCaux.nacion-1]=MCaux.cantHab;

        fread(&MCaux,sizeof(ModifCenso),1,fModifCenso);
    }
    fclose(fModifCenso);
}
