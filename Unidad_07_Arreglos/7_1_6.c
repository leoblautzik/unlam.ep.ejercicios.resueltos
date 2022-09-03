#include <stdio.h>
int IngresaCodigos(int[], int);
int IngresarProducto();
int IngresarPositivo();
int Buscar(int[], int, int);
void Listar(int[],int[],int);
int ValorMaximo(int [], int);
int ValorMinimo(int [], int);
void MostrarValor(int[], int[], int, int);
int main()
{
    int codProd, cant,vecCodProd[10], vecPed[10]={0}, pos, max, min;
    IngresaCodigos(vecCodProd,10);
    printf("\n\nCARGA DE PEDIDOS\n");
    codProd=IngresarProducto();
    while(codProd!=0)
    {
        pos = Buscar(vecCodProd,codProd,10);
        if (pos!=-1)
        {
            printf("Ingrese la cantidad que quiere pedir del producto: ");

            cant = IngresarPositivo();
            vecPed[pos]+=cant;
            /*
                Alternativa a las dos lineas superiores y ahorro una variable
                vecPed[pos]+=IngresarPositivo();
            */
        }
        else
            printf("Codigo de producto Incorrecto\n");

        codProd=IngresarProducto();
    }
    Listar(vecCodProd, vecPed, 10);

    max = ValorMaximo(vecPed,10);
    printf("\nLa mayor cantidad pedida fue de %d y corresponde a los productos:", max);
    MostrarValor(vecCodProd,vecPed,max,10);

    min = ValorMinimo(vecPed,10);
    printf("\nLa menor cantidad pedida fue de %d y corresponde a los productos:", min);
    MostrarValor(vecCodProd,vecPed,min,10);

    return 0;
}

int IngresarPositivo()
{
    int cant;
    do
    {
        scanf("%d", &cant);
        if (cant<=0)
            printf("Valor incorrecto debe ser mayor a 0.\n");
    }while(cant<=0);

    return cant;
}
int IngresaCodigos(int vcod[], int ce)
{
    int i, pos, error;
    for(i=0;i<ce;i++)
    {
        do
        {
            error =0; //no hay error

            printf("Ingrese un codigo de producto de 4 digitos:");
            scanf("%d", &vcod[i]);

            if (vcod[i]<1000 || vcod[i]>9999)
            {
                printf("CODIGO ERRONEO\n");
                error=1;
            }
            else
            {
                pos = Buscar(vcod,vcod[i], i);
                if (pos != -1)
                {
                    printf("CODIGO DUPLICADO\n");
                    error =1;
                }
            }
        }while(error);
    }
}

int IngresarProducto()
{
    int cod;
    printf("Ingrese un codigo de producto (0 fin):");
    scanf("%d", &cod);
    return cod;
}

void Listar(int vcod[], int vp[], int ce)
{
    int i;
    printf("\n    PEDIDOS\n");
    printf("-----------------\n");
    printf("Producto Cantidad");
    for (i=0;i<ce;i++)
        printf("\n%8d%9d",vcod[i],vp[i]);
}

int Buscar(int v[],int buscado, int ce)
{
    int pos=-1,i=0;
    while(pos==-1 && i<ce)
        if(v[i]==buscado)
            pos =i;
        else
            i++;
    return pos;
}

int ValorMaximo(int v[], int ce)
{
    int max, i;
    max = v[0];
    for (i=1;i<ce;i++)
        if (v[i]>max)
            max = v[i];
    return max;
}

int ValorMinimo(int v[], int ce)
{
    int min, i;
    min = v[0];
    for (i=1;i<ce;i++)
        if (v[i]<min)
            min = v[i];
    return min;
}

void MostrarValor(int vCod[], int vPed[], int valor, int ce)
{
    int i;
    for (i=0;i<ce;i++)
        if(vPed[i]==valor)
            printf("\n%d", vCod[i]);
}
