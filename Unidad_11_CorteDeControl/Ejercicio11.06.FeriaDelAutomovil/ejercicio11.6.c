/*
   En la feria internacional del automóvil, una empresa autopartista que dispone de un stand registra la información de los visitantes interesados en sus productos. Por cada visitante se ingresa:
   • Nombre y Apellido (texto de máximo 35 caracteres)
   • DNI (entero)
   • Localidad (texto de 40 caracteres máximo)
   • Email (texto de máximo 20 caracteres)
   • Fecha (estructura con día, mes y año)
   Se solicita:
   a. Realizar una función para ingresar la información por teclado hasta que se ingrese un visitante con nombre FIN. (se admite como máximo cargar 500 visitantes).
   b. Una vez finalizado el ingreso de datos se debe generar un archivo llamado visitantes.dat que esté ordenado por localidad.
   c. Tomando el archivo visitantes.dat se debe calcular y mostrar la cantidad de visitas recibidas por cada localidad y generar un archivo para cada una de ellos conteniendo la información de los visitantes para que dicho archivo puede ser enviado a la sucursal más cercada de forma de contactar a los interesados. Cada archivo generado será nombrado con Nombre de la Localidad.dat.
   */

#include<stdlib.h>
#include<string.h>
#include "fechas.h"
#include<stdlib.h>


typedef struct{
    char apeNom[36];
    int dni;
    char localidad[41];
    char email[21];
    Fecha fecha;
}Visitante;


int cargarVisitantes(Visitante []);
void mostrarVisitantes(Visitante [], int);
void ordenarVisitantes(Visitante [], int);
void escribirArchivoVisitantes(Visitante [],int);
int leerArchivoVisitantes(Visitante []);
void generarLocalidades();

int main(){

    int cantidadVisitantes=0;
    Visitante visitantes[500];

//    cantidadVisitantes=cargarVisitantes(visitantes);
    cantidadVisitantes= leerArchivoVisitantes(visitantes);
    ordenarVisitantes(visitantes,cantidadVisitantes);
    escribirArchivoVisitantes(visitantes,cantidadVisitantes);
//    cantidadVisitantes= leerArchivoVisitantes(visitantes);
//    mostrarVisitantes(visitantes,cantidadVisitantes);
    generarLocalidades();

    return 0;
}

int cargarVisitantes(Visitante v[]){
    system("clear");
    Visitante aux;
    int i=0;

    printf("Apellido y Nombre: ");
    leerTexto(aux.apeNom,36);

    while(strcmpi(aux.apeNom,"FIN")!=0 && i<500)
    {
        printf("DNI: ");
        scanf("%d", &aux.dni);
        getchar();
        printf("Localidad: ");
        leerTexto(aux.localidad,41);
        printf("e-mail: ");
        leerTexto(aux.email,21);
        do{
            printf("Fecha(dia): ");
            scanf("%d", &aux.fecha.dia);
            getchar();
            printf("Fecha(mes): ");
            scanf("%d",&aux.fecha.mes);
            getchar();
            printf("Fecha(anio): ");
            scanf("%d",&aux.fecha.anio);
            getchar();
        }while(esFechaValida(aux.fecha)==0);
        v[i]=aux;
        i++;
        printf("Apellido y Nombre: ");
        leerTexto(aux.apeNom,36);
    }
    return i;
}

void mostrarVisitantes(Visitante v[],int cant){

    for(int i=0;i<cant;i++){
        printf("%s\t%d\t%s\t%s\t%d/%d/%d\n",v[i].apeNom, v[i].dni,v[i].localidad, v[i].email, v[i].fecha.dia, v[i].fecha.mes,v[i].fecha.anio);

    }
}

void ordenarVisitantes(Visitante v[],int cant){

    int i,j;
    Visitante aux;
    for (i=0;i<cant-1;i++)
    {
        for (j=0;j<cant-1-i;j++)
        {
            if (strcmpi(v[j].localidad,v[j+1].localidad) > 0)
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }
        }
    }
}

void escribirArchivoVisitantes(Visitante v[],int tam){

    int i;
    FILE *pwf;
    if ( ( pwf= fopen("visitantes.dat", "wb")) == NULL )
    {
        printf("No se puede abrir.\n");
        getchar(); exit(1);
    }

    for ( i = 0; i < tam; i++)
    {
        fwrite(&v[i],sizeof(Visitante),1,pwf);
    }
    
    fclose(pwf);

}

int leerArchivoVisitantes(Visitante v[]){

    int i=0;
    FILE *fp;
    if ( ( fp= fopen("visitantes.dat", "rb")) == NULL )
    {
        printf("No se puede abrir.\n");
        getchar(); exit(1);
    }


    fread(&v[i], sizeof(Visitante),1,fp);
    while ( !feof (fp) )
    {
        i++;
        fread(&v[i], sizeof(Visitante),1,fp);
    }
    fclose(fp);
    return i;
}

void generarLocalidades(){

    int i=0;
    int cantVisLoc=0;
    Visitante aux;
    char auxLocalidad[41],nomArchivo[45];
    FILE *fwL, *fp;
    if ( ( fp= fopen("visitantes.dat", "rb")) == NULL )
    {
        printf("No se puede abrir.\n");
        getchar(); exit(1);
    }

    fread(&aux,sizeof(Visitante),1,fp);
    while ( !feof (fp) )
    {
        strcpy(auxLocalidad,aux.localidad);
        strcpy(nomArchivo,aux.localidad);
        strcat(nomArchivo, ".dat");
        cantVisLoc=0;
        if ( ( fwL= fopen(nomArchivo, "wb")) == NULL )
        {
            printf("No se puede abrir.\n");
            getchar(); exit(1);
        }

        while (strcmp(aux.localidad,auxLocalidad)==0 && !feof (fp) ){
            cantVisLoc++;
            fwrite(&aux,sizeof(Visitante),1,fwL);
            fread(&aux, sizeof(Visitante),1,fp);
        }
        printf("%s  %d visitantes\n", auxLocalidad,cantVisLoc);

        fclose(fwL);
    }
    fclose(fp);

}
