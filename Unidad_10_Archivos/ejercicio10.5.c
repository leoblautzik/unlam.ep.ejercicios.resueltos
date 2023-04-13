#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int	codart;		//•  Código de artículo (entero)
    char desc[51];	//•  Descripción (50 caracteres máximo)
    int	stock;		//•  Stock (entero)
}Sarticulos;                                                          //Stock.dat

typedef struct
{
    int codBuscado;	//•  Código de artículo                                    //Faltantes.dat
    int cant;		//•  Cantidad
}Sfaltantes;

int busqueda(Sarticulos[],int,int);

int main()
{
    //carga en el vector de estructuras
    Sarticulos aux,art[10];
    Sfaltantes falta;
    FILE *pf, *pf2;
    int i = 0;
    pf = fopen("Stock.dat","rb");
    if(pf==NULL)
    {
        printf("\nNo se pudo abrir el archivo...");
        exit (1);
    }
    pf2 = fopen("Faltantes.dat","wb");
    if(pf2==NULL)
    {
        printf("\nNo se pudo abrir el archivo...");
        exit (1);
    }

    printf("\n%-9s  %-30s %-10s\n","COD. ART","DESCRIPCION","STOCK");
    fread(&aux,sizeof(Sarticulos),1,pf);
    while(!feof(pf))
    {
        art[i] = aux;
        i++;

        printf("%9d  %-30s %-10d\n",aux.codart,aux.desc,aux.stock);  //  art[i].codart,art[i].desc,art[i].stock

        fread(&aux,sizeof(Sarticulos),1,pf);
    }
    fclose(pf);

    int codigo,cantidad,pos;

    printf("\nIngrese codigo del articulo...cero para terminar: ");
    scanf("%d",&codigo);
    while(codigo !=0)
    {
        pos = busqueda(art,10,codigo);
        //printf("\npos trae %d",pos);
        if(pos != -1)
        {
            printf("\nIngrese la cantidad vendida: ");
            scanf("%d",&cantidad);
            if(art[pos].stock >= cantidad)
                art[pos].stock -= cantidad;
            else
            {
                falta.codBuscado = art[pos].codart;
                falta.cant = cantidad - art[pos].stock;
                art[pos].stock = 0;
                fwrite(&falta,sizeof(Sfaltantes),1,pf2);
            }
        }
        else
            printf("\nNo esta\n");

        printf("\nIngrese codigo del articulo...cero para terminar: ");
        scanf("%d",&codigo);
    }
    fclose(pf2);
    
    
    pf = fopen("Stock.dat","wb");
    
    for(i = 0; i < 10; i++){                //cuando cargamos es con for hasta cant
        printf("%d\n", art[i].codart);
        fwrite(&art[i],sizeof(Sarticulos),1,pf);
    }
    
    fclose(pf); 

}


int busqueda(Sarticulos art[],int cant,int dato)
{
    int i=0, pos=-1;
    while(i<cant && pos == -1)
    {
        //printf("\nQue hay en codart %d y en dato %d",art[i].codart,dato);

        if(art[i].codart == dato)
            pos = i;
        else
            i++;
    }
    return pos;
}
/*
   Se dispone de un archivo llamado Stock.dat que contiene
   la información de los 10 productos que vende una fábrica.
   En el archivo se guarda:
   •  Código de artículo (entero)
   •  Descripción (50 caracteres máximo)
   •  Stock (entero)
   Luego se ingresan por teclado las ventas a realizar indicando:
   •  Código de artículo
   •  Cantidad
   La carga por teclado de las ventas finaliza con un código de artículo igual a 0.
   Por cada venta se debe controlar si hay stock suficiente y
   si lo hay, restar el stock de dicho producto,
   sino hay stock se debe vender lo que quede disponible y
   grabar un registro en un archivo Faltantes.dat con
   la cantidad que no pudo venderse,
   dicho registro debe contener:
   •  Código de artículo
   •  Cantidad
   Se genera un registro por cada venta que no pudo concretarse,
   pudiendo quedar en el archivo varios registros faltantes del mismo producto.
   Al finalizar actualizar el archivo Stock.dat con el stock actualizado luego de procesar las ventas.
   */
