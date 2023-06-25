#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int canal;
    char programa[36];
    float rating;
}Programa;

typedef struct
{
    int canal;
    float promedio;
}Canal;

int main()
{

    float sumarating;
    float maxrating;
    int canalMasVisto;
    int cuentoProgramas;
    FILE *pf, *pfw;
    Programa aux;
    int flag=0;
    int canalActual;
    Canal canalAux;

    pf = fopen("Rating.dat", "rb");
    pfw = fopen("Promedios.dat", "wb");

    if(pf == NULL || pfw == NULL)
    {
        printf("Error");
        getchar();
        exit(1);
    }

    fread(&aux, sizeof(aux),1,pf);
    while(!feof(pf))
    {
        canalActual = aux.canal;
        sumarating = 0;
        cuentoProgramas = 0;

        while(!feof(pf) && aux.canal == canalActual)
        {
            sumarating += aux.rating;
            cuentoProgramas ++;
            fread(&aux, sizeof(aux),1,pf);
        }
        if(sumarating < 15)
        {
            printf("Canal con menos de 15 puntos:  %d\n", canalActual);
        }
        //escribir en el archivo de promedios
        canalAux.canal = canalActual;
        canalAux.promedio = sumarating/cuentoProgramas;
        fwrite(&canalAux, sizeof(Canal), 1, pfw);

        if(flag == 0 || sumarating > maxrating)
        {
            canalMasVisto = canalActual;
            maxrating = sumarating;
            flag = 1;
        }
    }
    printf("El canal mas visto es:  %d\n", canalMasVisto);
    fclose(pf);
    fclose(pfw);
    pfw = fopen("Promedios.dat", "rb");
    fread(&canalAux, sizeof(canalAux), 1, pfw);
    while (!feof(pfw)) {
        printf("%d \t %f\n", canalAux.canal, canalAux.promedio);
        fread(&canalAux, sizeof(canalAux), 1, pfw);
    }
    fclose(pfw); 
}

