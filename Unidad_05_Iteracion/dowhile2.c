#include <stdio.h>

int main()
{
    int suma=0, cont=0, nota,error;


    do
    {
        error =0;
        printf("Ingrese una nota (0 fin):");
        scanf("%d",&nota);

        if(nota<0 || nota >10)
        {
            printf("Valor Incorrecto.\n");
            error = 1;
        }

    }while(error ==1);


    while(nota!=0)
    {
        suma+=nota;
        cont++;


        do
        {
            error =0;
            printf("Ingrese una nota (0 fin):");
            scanf("%d",&nota);

            if(nota<0 || nota >10)
            {
                printf("Valor Incorrecto.\n");
                error = 1;
            }

        }while(error ==1);
    }

    if (cont>0)
        printf("El promedio es %.2f", (float)suma/cont);
    else
        printf("No se ingresaron datos.");

    return 0;
}
