#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char codProv[4];
    int nacion;
    int cantHab;
}Censo;

int main(int argc, char *argv[])
{
    
    
    FILE *fcenso;
    if ((fcenso = fopen("./censo.dat","rb"))==NULL) {
        printf("No se pudo abrir el archivo censo.dat");
        getchar();
        exit(1);
    }     
    Censo censoAux;

    fread(&censoAux,sizeof(Censo),1,fcenso);
    while(!feof(fcenso)){
        printf("%s\t%d\t%d\n",censoAux.codProv,censoAux.nacion,censoAux.cantHab);
        fread(&censoAux,sizeof(Censo),1,fcenso);
    }
    fclose(fcenso);


    return 0;
}

