//Dibuja un rombo
#include <stdio.h>
int main()
{
    int f,j, filas, espacios, asteriscos;
    printf("Ingrese la cantidad de filas: ");
    scanf("%d",&filas);
    asteriscos=1;
    espacios = filas-1;
    for (f=0;f<filas;f++)
    {
        for (j=0;j<espacios;j++)
            printf(" ");
        espacios--;

        for (j=0;j<asteriscos;j++)
            printf("*");
        asteriscos+=2;

        printf("\n");
    }

    asteriscos-=4;
    espacios+=2;

    for (f=0;f<filas;f++)
    {
        for (j=0;j<espacios;j++)
            printf(" ");
        espacios++;

        for (j=0;j<asteriscos;j++)
            printf("*");
        asteriscos-=2;

        printf("\n");
    }


    return 0;
}
