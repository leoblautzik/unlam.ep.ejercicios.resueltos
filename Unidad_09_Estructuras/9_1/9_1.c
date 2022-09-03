#include <stdio.h>
#include <string.h>

void leerTexto (char texto[], int largo)
{
    int i;
    fgets(texto, largo, stdin);
    i=0;
    while (texto[i]!='\0')
    {
        if (texto[i]=='\n')
            texto[i]='\0';
        else
            i++;
    }
}            

struct NEUMATICO
{
    char codigo[6];
    float precio;
    char descripcion[31];
    int cantVendida;
    float importeVendido;
};

int cargaProductos(struct NEUMATICO []);

int main()
{
    int cantProductos;   
    struct NEUMATICO productos[50];
    cantProductos = cargaProductos(productos);

    return 0;
}

int cargaProductos(struct NEUMATICO productos[])
{
    int i = 0;
    printf("Ingrese la descripción del producto: ");
    leerTexto(productos[i].descripcion,31);
    while(strcmp(productos[i].descripcion, "FIN") != 0)
    {   
        printf("Ingrese el código de producto: ");
        leerTexto(productos[i].codigo, 6);

        printf("Ingrese el precio del producto: ");
        scanf("%f", &productos[i].precio);
        getchar();

        printf("Ingrese la cantidad vendida: ");
        scanf("%d", &productos[i].cantVendida);
        getchar();

        printf("Ingrese  el importe vendido: ");
        scanf("%f", &productos[i].importeVendido);
        getchar();

        i++;

        printf("Ingrese la descripción del producto: ");
        leerTexto(productos[i].descripcion,31);
    }
    return i;
}
