#include <stdio.h>

int main()
{
    int suma=0, cont=0, nota,error;

    error = 0;
    do
    {
        if (error ==1)
            printf("Valor Incorrecto\n");

        printf("Ingrese una nota (0 fin):");
        scanf("%d",&nota);
        error=1;

    }while(nota<0 || nota >10);


    while(nota!=0)
    {
        suma+=nota;
        cont++;


        error = 0;
        do
        {
            if (error ==1)
                printf("Valor Incorrecto\n");

            printf("Ingrese una nota (0 fin):");
            scanf("%d",&nota);

            error=1;

        }while(nota<0 || nota >10);
    }

    if (cont>0)
        printf("El promedio es %.2f", (float)suma/cont);
    else
        printf("No se ingresaron datos.");

    return 0;
}
