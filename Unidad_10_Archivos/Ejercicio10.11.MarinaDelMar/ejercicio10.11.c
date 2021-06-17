/*
 *ejercicio 10.11 Marina del Mar
 *
 *
 *
 * */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
    int anio;
    int bimestre;
    float importe;
}Importe;

typedef struct{
    int contribuyente;
    int anio;
    int bimestre;
}Control;

int  main() {

    FILE *pfw, *pfr;
    Importe auxImporte;
    Control auxControl;

    Importe importes[18];
    float importeTotal;
    float matControl[50][6];
    for(int i=0;i<50;i++)
        for(int j=0;j<6;j++)
            matControl[i][j]=0;

    if((pfr=fopen("importes,dat", "rb")) == NULL){
        printf("No se puede abrir importes.dat\n");
        getchar();
        exit(1);
    }

    for(int i=0;i<18;i++)
        fread(&importes[i],sizeof(Importe),1,pfr);
    fclose(pfr);

    if((pfr=fopen("control,dat", "rb")) == NULL){
        printf("No se puede abrir control.dat\n");
        getchar();
        exit(1);
    }

    fread(&auxControl,sizeof(Control),1,pfr);
    while(!feof(pfr)){
      matControl[auxControl.contribuyente-1][auxControl.bimestre-1]=1;









    return 0;
}
