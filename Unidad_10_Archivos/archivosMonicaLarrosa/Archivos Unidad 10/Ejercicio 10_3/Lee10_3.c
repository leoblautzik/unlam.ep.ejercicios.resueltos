#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct
{
    int cod;
    float pre;
    char descr[51];} TProd;

int main()
{
    FILE *pf;
    TProd prod;

    setlocale (LC_ALL, "spanish");   //Configuración regional para aceptar el español

    pf=fopen("productos.dat","rb");

    if (pf==NULL)
    {
        printf("\n***Error al abrir el archivo.***");
        exit(1);
    }
    printf("\nCódigo\tPrecio\tDescripción\n");
    fread(&prod,sizeof(TProd),1,pf);
    while (!feof(pf))
        {
         printf("\n%-6d\t%-10.2f\t%-50s", prod.cod, prod.pre, prod.descr);
         fread(&prod,sizeof(TProd),1,pf);
        }

    fclose(pf);
}
