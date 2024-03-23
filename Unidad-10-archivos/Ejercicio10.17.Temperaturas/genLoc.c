#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct {
    char codLoc[11];
    int mes;
    float temperatura;
}Temperatura;

typedef struct {
    char codLoc[11];
    char descrLoc[30];
}Localidad;

int main(){
    char auxCodLoc[11];
    char auxDesc[30];
    strcpy(auxCodLoc,"Loc_  ");
    strcpy(auxDesc,"Localidad00 ");

    FILE *pwf, *prf;
    Localidad auxL;
    Temperatura auxT;
    if ( ( pwf= fopen("localidades.dat", "wb")) == NULL )

    {
        printf("No se puede abrir.\n");
        getchar(); exit(1);
    }
    for(int i=0; i<5; i++){
        auxCodLoc[4]=(i+1)+'0';
        auxDesc[11]=(i+1)+'0';

        strcpy(auxL.codLoc,auxCodLoc);
        strcpy(auxL.descrLoc,auxDesc);
        fwrite(&auxL,sizeof(Localidad),1,pwf);
    }
    fclose(pwf);

    if ( ( pwf= fopen("temperaturas.dat", "wb")) == NULL )

    {
        printf("No se puede abrir.\n");
        getchar(); exit(1);
    }
    srand48(time(NULL));
    for(int i=0;i<10000;i++){
        auxCodLoc[4]=(i%5+1)+'0';
        strcpy(auxT.codLoc, auxCodLoc);
        auxT.mes=i%3+1;
        auxT.temperatura = drand48() * 40 - 8;
        fwrite(&auxT,sizeof(Temperatura),1,pwf);
    }
    fclose(pwf);

    if ( ( prf= fopen("localidades.dat", "rb")) == NULL )

    {
        printf("No se puede abrir.\n");
        getchar(); exit(1);
    }

    for(int i=0; i<5; i++){
        fread(&auxL,sizeof(Localidad),1,prf);
        printf("%s\t%s\n",auxL.codLoc,auxL.descrLoc);
    }
    fclose(prf);

    if ( ( prf= fopen("temperaturas.dat", "rb")) == NULL )

    {
        printf("No se puede abrir.\n");
        getchar(); exit(1);
    }

    fread(&auxT,sizeof(Temperatura),1,prf);
    while(!feof(prf)){
        printf("%s\t%d\t%f\n",auxT.codLoc,auxT.mes,auxT.temperatura);
        fread(&auxT,sizeof(Temperatura),1,prf);
    }
    fclose(prf);
}
