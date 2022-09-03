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

int main(){
    int tam=98;
    Visitante aux;
    char auxApenom[36] = "ApellidoYNombre   ";
    int auxDNI=30000000;
    char auxLocalidad[41]="Localidad ";
    char auxEmail[21]="email   @uno.edu.ar";
    Fecha auxFecha;
    auxFecha.dia=25;
    FILE *pwf;
    auxFecha.mes=6;
    auxFecha.anio=2020;

    if ( ( pwf= fopen("visitantes.dat", "wb")) == NULL )
    {
        printf("No se puede abrir.\n");
        getchar(); exit(1);
    }

    for (int i = 0; i < tam; i++){
        auxApenom[15]=(i/100)+'0';     // 345/100=3
        auxApenom[16]=((i/10)%10)+'0'; // 345/10=34%10=4
        auxApenom[17]=(i%10)+'0';     // 345%10=5
        strcpy(aux.apeNom,auxApenom);
        aux.dni=auxDNI+i;
        auxLocalidad[9]=(i%10)+'0';
        strcpy(aux.localidad,auxLocalidad);
        auxEmail[5]=(i/100)+'0';
        auxEmail[6]=(i/10)%10+'0';
        auxEmail[7]=(i%10)+'0';
        strcpy(aux.email,auxEmail);
        aux.fecha=auxFecha;
        fwrite(&aux,sizeof(Visitante),1,pwf);
    }
    fclose(pwf);
}

