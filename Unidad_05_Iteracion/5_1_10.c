/*
Confeccionar un programa que: solicite el ingreso de un valor entero N < 12
y luego una lista de N números reales sobre la cual debe calcular:

a.  el promedio de los positivos.
b.  el promedio de los negativos.
c.  la cantidad de ceros.

Si el valor ingresado N es mayor que 12 informar 'VALOR EXCEDIDO”
y si es menor o igual a 0 informar “CANTIDAD INVALIDA”.
*/

#include <stdio.h>
int main()
{
    int N,i,cantNeg=0, cantPos=0, cantCeros=0, sumPos=0, sumNeg=0,num;
    printf("Ingrese un numero entre 1 y 12: ");
    scanf("%d", &N);
    if (N>=1 && N<=12)
        for (i=1;i<=N;i++)
        {
            printf ("Ingrese un numero (%d): ",i);
            scanf("%d", &num);
            if (num==0)
                cantCeros++;
            else
                if (num<0)
                {
                    cantNeg++;
                    sumNeg+=num;
                }
                else
                {
                    sumPos+=num;
                    cantPos++;
                }
        } //for
    else
        if (N<=0)
            printf ("\nCANTIDAD INVALIDA.");
        else
            printf("\nVALOR EXCEDIDO.");

    printf ("\n\nCantidad de ceros: %d", cantCeros);
    if (cantNeg>0)
        printf("\nEl promedio de los negativos es: %.2f", (float)sumNeg/cantNeg);
    else
        printf("\nNo se ingresaron negativos.");

    if (cantPos>0)
        printf("\nEl promedio de los positivos es: %.2f", (float)sumPos/cantPos);
    else
        printf("\nNo se ingresaron positivos.");

    return 0;
}
