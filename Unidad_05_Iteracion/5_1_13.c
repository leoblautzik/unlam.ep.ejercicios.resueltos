/*
Realizar un programa que:

a.  Muestre todos los números primos entre 1 y 100.
 (Un nro. es primo cuando es divisible solamente por 1 y por sí mismo).
b.  Contar y mostrar la cantidad de primos encontrados
*/

#include <stdio.h>
int main()
{
    int num, i, divisores, cantPrimos =0;
    printf("Numeros primos entre 1 y 100\n");
    for (num =1; num<=100; num++)
    {
        divisores=0;
        for (i=1;i<=num;i++)
            if (num%i==0)
                divisores++;

        if (divisores==2)
        {
            printf ("\t%d", num);
            cantPrimos++;
        }

    }

    printf("\nCantidad de primos encontrados: %d", cantPrimos);
    return 0;
}
