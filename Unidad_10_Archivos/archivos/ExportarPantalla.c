#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int codigo;
    char descripcion[21];
    float precio;
}sProducto;

int main()
{
    sProducto prod;
    int i;
    FILE *ap, *exportar;
    ap = fopen("productos.dat","rb");
   // exportar = fopen("productos.csv","wt");
    if (ap==NULL)// || exportar==NULL)
    {
        printf("Error al abrir el archivo.");
        getch();
        exit(1);
    }

    fprintf(stdout, "CODIGO;DESCRIPCION;PRECIO\n");
    fread(&prod,sizeof(prod),1,ap);
    while(!feof(ap))
    {
        fprintf(stdout,"%d;%s;%.2f\n", prod.codigo, prod.descripcion, prod.precio);
        fread(&prod,sizeof(prod),1,ap);
    }
    fclose(ap);
    //fclose(exportar);
    printf("\n");
    return 0;
}


