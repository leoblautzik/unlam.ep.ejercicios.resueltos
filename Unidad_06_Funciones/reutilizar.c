#include <stdio.h>
int IngresaNota();

int main()
{
    int suma=0, cont=0, nota;

    nota = IngresaNota();

    while(nota!=0)
    {
        suma+=nota;
        cont++;

        nota = IngresaNota();
    }

    if(cont>0)
        printf("El promedio es: %.2f", (float)suma/cont);
    else
        printf("No se ingresaron notas.");
    return 0;
}

int IngresaNota()
{
    int error=0, n;
    do
    {
        if(error) //distinto de 0 verdadero
            printf("Nota invalida.\n");

        printf("Ingrese una nota (0 fin):");
        scanf("%d",&n);

        error=1;
    }while(n<0||n>10);

    return n;
}
