/*
Ingresar 18 valores de temperatura distintos de cero.
Se pide determinar e informar cuantas ternas (tres valores seguidos)
de valores positivos y cuantas de negativos hay.

se puede considerar de dos formas ternas completas o si sigo ingresando con el mismo signo
puedo considerar otra terna mas ejemplo 1234 la primer terna es 123 y la segunda 234

Lo consideramos con ternas completas es decir que cuando se completa la terna se empieza nuevamente
*/

#include <stdio.h>
int main()
{
    int i, num, cantPos=0, cantNeg=0, ternasPos=0, ternasNeg=0;
    float temperatura;
    for (i=1;i<=18;i++)
    {
        printf("Ingrese la temperatura nro %d:", i);
        scanf("%f", &temperatura);
        if (temperatura<0)
        {
            cantNeg++;
            cantPos=0;
        }
        else
            if (temperatura>0)
            {
                cantPos++;
                cantNeg=0;
            }
            else
            {
                cantPos=0;
                cantNeg=0;
            }

        if (cantPos==3)
        {
            ternasPos++;
            cantPos=0;
        }
        else if(cantNeg==3)
        {
            ternasNeg++;
            cantNeg=0;
        }
    }

    printf("\n\n----------------");
    printf("\nTernas positivas %d", ternasPos);
    printf("\nTernas negativas %d\n", ternasNeg);

    return 0;
}
