#include <stdio.h>

#define desc1 imp*0.045
#define desc2 imp*0.08
#define desc3 imp*0.105

int main ()
{
    float imp;
    float total1, total2, total3;

    printf("Ingrese el importe de su producto:");
    scanf("%f", &imp);

    if (imp<55)
    {
        total1=imp-desc1;
        printf("Su descuento es de %.2f y su precio final de %.2f", desc1, total1);
    }
    else
    {
        if (imp>=55&&imp<=100)
        {
            total2=imp-desc2;
            printf("Su descuento es de %.2f y su precio final de %.2f", desc2, total2);
        }
        else
        {
            if (imp>100)
            {
                total3=imp-desc3;
                printf("Su descuento es de %.2f y su precio final de %.2f", desc3, total3);
            }
        }
    }
    return 0;
}
