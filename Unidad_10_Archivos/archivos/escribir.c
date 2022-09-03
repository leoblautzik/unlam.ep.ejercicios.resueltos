#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int codigo;
    char descripcion[21];
    float precio;
}sProducto;

sProducto IngresarProducto();
int main()
{
    sProducto prod;
    int i;
    FILE * ap;
    ap = fopen("productos.dat","ab");
    if (ap==NULL)
    {
        printf("Error al abrir el archivo.");
        getch();
        exit(1);
    }
    for (i=0;i<3;i++)
    {
        prod=IngresarProducto();
        fwrite(&prod,sizeof(prod),1,ap);
    }
    fclose(ap);
    return 0;
}

sProducto IngresarProducto()
{
    sProducto producto;
    printf ("Ingrese el codigo:");
    scanf("%d",&producto.codigo);

    printf("Ingrese la descripcion:");
    fflush(stdin);
    gets(producto.descripcion);

    printf("Ingrese el precio:");
    scanf("%f", &producto.precio);

    printf("\n");
    return producto;
}
