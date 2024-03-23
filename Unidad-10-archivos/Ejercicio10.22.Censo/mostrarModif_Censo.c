#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char codModif;
    char codProv[4];
    int nacion;
    int cantHab;
}ModifCenso;

int main(int argc, char *argv[])
{
    FILE *fModifCenso;
    if ((fModifCenso = fopen("./modif_censo.dat","rb"))==NULL) {
        printf("No se pudo abrir el archivo modif_censo.dat");
        getchar();
        exit(1);
    }
 
    ModifCenso MCaux;
    
    fread(&MCaux,sizeof(ModifCenso),1,fModifCenso);
    while(!feof(fModifCenso)){
         
        printf("%c\t%s\t%d\t%d\n",MCaux.codModif, MCaux.codProv,MCaux.nacion,MCaux.cantHab);
        fread(&MCaux,sizeof(ModifCenso),1,fModifCenso);
    }
    fclose(fModifCenso);




    return 0;
}

