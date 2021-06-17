#include <stdio.h>
#include <stdlib.h>  //para el exit
typedef struct
{
    int codigo;
    float precio;
    char descripcion[51];
}sProducto;

int LeerProductos(sProducto[], int);
void MostrarProductos(sProducto[], int);
int ModificarPrecios(sProducto[], int);
int BuscarProducto(sProducto[],int, int);
float IngresarRealPositivo();
void ActualizarYExportarProductos(sProducto[], int);

int main()
{
    sProducto productos[100];
    int cantProd, modificados;
    cantProd = LeerProductos(productos,100);

    printf("Los productos disponibles son:");
    MostrarProductos(productos, cantProd);

    modificados = ModificarPrecios(productos, cantProd);
    if (modificados >0)
    {
        printf("\nSe modificaron los precios de %d productos.", modificados);
        printf("\nLista de productos actualizada:");
        MostrarProductos(productos, cantProd);
        ActualizarYExportarProductos(productos, cantProd);
    }
    else
        printf("No se ha modificado ningun precio.");
    return 0;
}

int LeerProductos(sProducto vp[], int ce)
{
    int i=0;
    FILE *pp;
    sProducto prod;

    pp = fopen("PRODUCTOS.dat", "rb");
    if (pp == NULL)
    {
        printf("Error al abrir el archivo de productos.\n");
        system("pause");
        exit(1);
    }

    fread(&prod, sizeof(sProducto),1,pp);
    while(!feof(pp) && i < ce)
    {
        vp[i] = prod;
        i++;
        fread(&prod, sizeof(sProducto),1,pp);
    }

    fclose(pp);
    return i;
}

void MostrarProductos(sProducto vp[], int ce)
{
    int i;
    printf("\n%6s %10s   %s","CODIGO","PRECIO","DESCRIPCION");
    for (i=0;i<ce;i++)
        printf("\n%6d %10.2f   %s", vp[i].codigo, vp[i].precio, vp[i].descripcion);
}

int ModificarPrecios(sProducto vp[], int ce)
{
    int cod, cantModificados=0, pos;
    float precioAnterior;
    printf("\n\nModificacion de Precios\n");
    printf("---------------------------");
    printf("\nIngrese el codigo del producto a modificar (0 para finalizar):");
    scanf("%d", &cod);
    while (cod!=0)
    {
        pos =BuscarProducto(vp, cod, ce);
        if (pos!=-1)
        {
            printf("El precio actual del producto %s es %.2f", vp[pos].descripcion, vp[pos].precio);
            printf("\nIngrese el nuevo precio:");
            precioAnterior = vp[pos].precio;
            vp[pos].precio = IngresarRealPositivo();
            if (vp[pos].precio != precioAnterior)
                cantModificados++;
        }
        else
            printf("Codigo de producto inexistente\n");

        printf("\nIngrese el codigo del producto a modificar (0 para finalizar):");
        scanf("%d", &cod);
    }

    return cantModificados;
}

int BuscarProducto(sProducto vp[], int buscado, int ce)
{
    int i=0, pos=-1;
    while(pos==-1 && i<ce)
    {
        if (vp[i].codigo==buscado)
            pos =i;
        else
            i++;
    }

    return pos;
}

float IngresarRealPositivo()
{
    int error=0;
    float valor;
    do
    {
        if (error)
        {
            printf(" --- El valor ingresado debe ser mayor a 0 ---\n");
            printf("Ingrese nuevamente:");
        }
        else
            error =1;

        scanf("%f", &valor);
    }while (valor<=0);

    return valor;
}

void ActualizarYExportarProductos(sProducto vp[], int ce)
{
    int i;
    FILE *archDat, *archCSV;
    archDat = fopen("PRODUCTOS.dat", "wb");
    archCSV = fopen("productos.csv", "wt");

    if (archDat ==NULL || archCSV==NULL)
    {
        printf("\n\n---No se pudieron crear los archivos para grabar los datos---\n\n");
        system("pause");
        exit(2);
    }

    fprintf(archCSV,"CODIGO;PRECIO;DESCRIPCION\n");

    for (i=0;i<ce;i++)
    {
        fwrite(&vp[i], sizeof(sProducto),1, archDat);
        fprintf(archCSV, "%d;%.2f;%s\n", vp[i].codigo, vp[i].precio, vp[i].descripcion);
        //printf(         "\n%6d %10.2f   %s", vp[i].codigo, vp[i].precio, vp[i].descripcion);
    }

    fclose(archDat);
    fclose(archCSV);
}
