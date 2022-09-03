#include <stdio.h>

int main()
{
    int suma=0, cont=0, num;

    printf("Ingrese un numero (0 fin):");
    scanf("%d",&num);

    while(num!=0)
    {
        suma+=num;
        cont++;

        printf("Ingrese un numero (0 fin):");
        scanf("%d",&num);
    }

    if (cont>0)
        printf("El promedio es %.2f", (float)suma/cont);
    else
        printf("No se ingresaron datos.");

    return 0;
}
