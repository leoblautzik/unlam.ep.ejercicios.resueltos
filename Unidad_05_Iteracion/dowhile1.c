#include <stdio.h>

int main()
{
    int suma=0, cont=0, nota;

    do
    {
        printf("Ingrese una nota (0 fin):");
        scanf("%d",&nota);

        if(nota<0 || nota >10)
            printf("Valor Incorrecto.\n");

    }while(nota<0 || nota >10);


    while(nota!=0)
    {
        suma+=nota;
        cont++;

        do
        {
            printf("Ingrese una nota (0 fin):");
            scanf("%d",&nota);

            if(nota<0 || nota >10)
                printf("Valor Incorrecto.\n");
        }while(nota<0 || nota >10);
    }

    if (cont>0)
        printf("El promedio es %.2f", (float)suma/cont);
    else
        printf("No se ingresaron datos.");

    return 0;
}
