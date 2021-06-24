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
    FILE * ap;
    ap = fopen("productos.dat","rb");
    if (ap==NULL)
    {
        printf("Error al abrir el archivo.");
        getch();
        exit(1);
    }

    printf("%8s   %-20s %10s","CODIGO","DESCRIPCION", "PRECIO");
    fread(&prod,sizeof(prod),1,ap);
    while(!feof(ap))
    {
        printf("\n%8d   %-20s %10.2f", prod.codigo, prod.descripcion, prod.precio);
        fread(&prod,sizeof(prod),1,ap);
    }
    fclose(ap);
    return 0;
}


