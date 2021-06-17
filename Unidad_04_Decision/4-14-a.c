#include<stdio.h>

int main()
{

    float importe;
    printf("Ingrese el importe: ");
    scanf("%f", &importe);
    printf("Importe: %6.2f\n",importe);

    if(importe < 55)
    {
        printf("Descuento: %6.2f\n", importe * 0.045);
        printf("Neto: %6.2f\n", importe * 0.955);

    }
    else     
        if(importe <= 100)
        {
            printf("Descuento: %6.2f\n", importe * 0.080);
            printf("Neto: %6.2f\n", importe * 0.920);
        }
        else
        { 
            printf("Descuento: %6.2f\n", importe * 0.105);
            printf("Neto: %6.2f\n", importe * 0.895);
        }

    return 0;
}
