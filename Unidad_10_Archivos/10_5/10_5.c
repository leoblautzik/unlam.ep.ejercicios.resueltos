/*Se dispone de un archivo llamado Stock.dat que contiene la información de
 * los 10 productos que vende una fábrica. En el archivo se guarda:
 • Código de artículo (entero)
 • Descripción (50 caracteres máximo)
 • Stock (entero)
 Luego se ingresan por teclado las ventas a realizar indicando:
 • Código de artículo
 • Cantidad
 La carga por teclado de las ventas finaliza con un código de artículo igual a 0.
 Por cada venta se debe controlar si hay stock suficiente y si lo hay, restar
 el stock de dicho producto, sino hay stock se debe vender lo que quede
 disponible y grabar un registro en un archivo Faltantes.dat con la
 cantidad que no pudo venderse, dicho registro debe contener:
 • Código de artículo
 • Cantidad
 */
#include <stdio.h>
#include <stdlib.h> //para el exit

void clean_stdin(void)
{
    int c;
    do
    {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

typedef struct
{
    int codigo;
    char descripcion[51];
    int stock;
} sProducto;

typedef struct
{
    int codigo;
    int cantidad;
} sFaltante;

void LeerProductos(sProducto[], int);
void MostrarProductos(sProducto[], int);
int BuscarProducto(sProducto[], int, int);
int IngresarEnteroPositivo();
void ActualizarStock(sProducto[], int ce);
void ingresarVentas(sProducto[], int);
void leerTexto(char[], int);
void MostrarFaltantes(char[]);

int main()
{
    // generarStock();
    sProducto productos[10];
    LeerProductos(productos, 10);
    MostrarProductos(productos, 10);
    ingresarVentas(productos, 10);
    ActualizarStock(productos, 10);
    MostrarProductos(productos, 10);

    MostrarFaltantes("faltantes.dat");
    return 0;
}

void LeerProductos(sProducto vp[], int ce)
{
    int i;
    FILE *pp;

    pp = fopen("Stock.dat", "rb");
    if (pp == NULL)
    {
        printf("Error al abrir el archivo de productos.\n");
        system("pause");
        exit(1);
    }

    for (i = 0; i < ce; i++)
        fread(&vp[i], sizeof(vp[i]), 1, pp);

    fclose(pp);
    return;
}

void MostrarProductos(sProducto vp[], int ce)
{
    int i;
    printf("\n%6s %-50s %6s", "CODIGO", "DESCRIPCION", "STOCK");
    for (i = 0; i < ce; i++)
        printf("\n%6d %-50s %6d", vp[i].codigo, vp[i].descripcion, vp[i].stock);
}

void MostrarFaltantes(char archivo[])
{
    FILE *archFaltantes;
    sFaltante faltante;

    archFaltantes = fopen(archivo, "rb");
    if (archFaltantes == NULL)
    {
        printf("\n\n---No se pudio abrir el archivo---\n\n");
        system("pause");
        exit(2);
    }

    printf("\nFALTANTES");
    printf("\n%6s %6s", "CODIGO", "STOCK");

    fread(&faltante, sizeof(faltante), 1, archFaltantes);
    while (!feof(archFaltantes))
    {
        printf("\n%6d %6d", faltante.codigo, faltante.cantidad);
        fread(&faltante, sizeof(faltante), 1, archFaltantes);
    }
    printf("\n");
    fclose(archFaltantes);
    return;
}

void ingresarVentas(sProducto vp[], int ce)
{
    FILE *archFaltantes;
    int cod, cantidad = 0, pos;
    sFaltante faltante;
    int hayFaltantes = 0;

    archFaltantes = fopen("faltantes.dat", "wb");
    if (archFaltantes == NULL)
    {
        printf("\n\n---No se pudo crear el archivos para grabar los datos---\n\n");
        system("pause");
        exit(2);
    }

    printf("\n\nVenta de Productos\n");
    printf("---------------------------");
    printf("\nIngrese el codigo de artículo (0 para finalizar):");
    scanf("%d", &cod);
    while (cod != 0)
    {
        pos = BuscarProducto(vp, cod, ce);
        if (pos != -1)
        {
            printf("\n%-50s", vp[pos].descripcion);
            printf("\nIngrese la cantidad vendida: ");
            cantidad = IngresarEnteroPositivo();
            if (vp[pos].stock >= cantidad)
            {
                vp[pos].stock -= cantidad;
            }
            else
            {
                faltante.codigo = vp[pos].codigo;
                faltante.cantidad = cantidad - vp[pos].stock;
                vp[pos].stock = 0;
                fwrite(&faltante, sizeof(faltante), 1, archFaltantes);
            }
        }
        else
            printf("Codigo de producto inexistente\n");

        printf("\nIngrese el codigo de articulo (0 para finalizar):");
        scanf("%d", &cod);
    }

    fclose(archFaltantes);
    return;
}

void ActualizarStock(sProducto vp[], int ce)
{
    int i;
    FILE *archStock;
    archStock = fopen("Stock.dat", "wb");
    if (archStock == NULL)
    {
        printf("\n\n---No se pudio crear el archivos para grabar los datos---\n\n");
        system("pause");
        exit(2);
    }

    for (i = 0; i < ce; i++)
    {
        fwrite(&vp[i], sizeof(sProducto), 1, archStock);
    }
    fclose(archStock);
    return;
}

int BuscarProducto(sProducto vp[], int buscado, int ce)
{
    int i = 0, pos = -1;
    while (pos == -1 && i < ce)
    {
        if (vp[i].codigo == buscado)
            pos = i;
        else
            i++;
    }
    return pos;
}

int IngresarEnteroPositivo()
{
    int error = 0;
    int valor;
    do
    {
        if (error)
        {
            printf(" --- El valor ingresado debe ser mayor a 0 ---\n");
            printf("Ingrese nuevamente:");
        }
        else
            error = 1;
        scanf("%d", &valor);
    } while (valor <= 0);
    return valor;
}

void leerTexto(char texto[], int largo)
{
    clean_stdin();
    int i;
    fgets(texto, largo, stdin);
    i = 0;
    while (texto[i] != '\0')
    {
        if (texto[i] == '\n')
            texto[i] = '\0';
        else
            i++;
    }
}

void generarStock()
{
    FILE *pfStock;
    int i;
    sProducto registro;

    pfStock = fopen("Stock.dat", "wb");
    if (pfStock == NULL)
    {
        printf("\n\n---No se pudio crear el archivos para grabar los datos---\n\n");
        system("pause");
        exit(2);
    }
    printf("\nGeneración de archivo Stock.dat\n");
    for (i = 0; i < 10; i++)
    {
        printf("Código: ");
        registro.codigo = IngresarEnteroPositivo();
        printf("Descripción: ");
        leerTexto(registro.descripcion, 51);
        printf("Stock: ");
        registro.stock = IngresarEnteroPositivo();
        fwrite(&registro, sizeof(registro), 1, pfStock);
    }
    fclose(pfStock);
}
