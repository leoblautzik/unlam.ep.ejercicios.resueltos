//Dibuja un triangulo rectangulo
#include <stdio.h>
int main()
{
    int i,j, filas;
    printf("Ingrese la cantidad de filas: ");
    scanf("%d",&filas);
    for (i=0;i<filas;i++)
    {
        for (j=0;j<=i;j++)
            printf("*");
        printf("\n");
    }
    return 0;
}
