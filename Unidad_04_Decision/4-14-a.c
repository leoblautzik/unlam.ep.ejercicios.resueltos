#include<stdio.h>

int main()
{

    float importe;
    printf("Ingrese el importe: ");
    scanf("%f", &importe);
    printf("Importe: %6.2f\n",importe);

    if(importe < 55)
    {
<<<<<<< HEAD
        printf("Descuento: %6.2f\n", importe * 0.045);
=======
        printf("Descuento: %8.3f\n", importe * 0.045);
>>>>>>> 855ad7f (Consultas 2022)
        printf("Neto: %6.2f\n", importe * 0.955);

    }
    else     
        if(importe <= 100)
        {
<<<<<<< HEAD
            printf("Descuento: %6.2f\n", importe * 0.080);
            printf("Neto: %6.2f\n", importe * 0.920);
        }
        else
        { 
            printf("Descuento: %6.2f\n", importe * 0.105);
            printf("Neto: %6.2f\n", importe * 0.895);
=======
            printf("Descuento: %8.2f\n", importe * 0.080);
            printf("Neto: %8.2f\n", importe * 0.920);
        }
        else
        { 
            printf("Descuento: %2.4f\n", importe * 0.105);
            printf("Neto: %.2f\n", importe * 0.895);
>>>>>>> 855ad7f (Consultas 2022)
        }

    return 0;
}
