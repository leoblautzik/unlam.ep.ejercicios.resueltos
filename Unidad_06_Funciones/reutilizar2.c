#include <stdio.h>
int IngresaEntero(int, int);

int main()
{
    int suma=0, cont=0, nota;

    nota = IngresaEntero(0,10);

    while(nota!=0)
    {
        suma+=nota;
        cont++;

        nota = IngresaEntero(0,10);
    }

    if(cont>0)
        printf("El promedio es: %.2f", (float)suma/cont);
    else
        printf("No se ingresaron notas.");
    return 0;
}

int IngresaEntero(int li, int ls)
{
    int error=0, n;
    do
    {
        if(error) //distinto de 0 verdadero
            printf("Numero invalido.\n");

        printf("Ingrese un numero (entre %d y %d):", li, ls);
        scanf("%d",&n);

        error=1;
    }while(n<li||n>ls);

    return n;
}
