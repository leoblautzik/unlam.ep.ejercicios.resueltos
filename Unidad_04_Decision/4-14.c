#include<stdio.h>
#define DESCUENTO_1 0.045
#define DESCUENTO_2 0.080
#define DESCUENTO_3 0.105

int main(){

    float importe, descuento, neto;
    printf("Ingrese el importe: ");
    scanf("%f", &importe);

    if(importe < 55){
        descuento = importe * DESCUENTO_1;
    }
    else     
        if(importe >= 55 && importe <= 100){
            descuento = importe * DESCUENTO_2;
        }
        else
        { 
            descuento = importe * DESCUENTO_3;
        }

    neto = importe - descuento;
    printf("Importe: %6.2f \nDescuento: %6.2f \nImporte a abonar: %6.2f \n", importe, importe*0.045, importe*(1-0.054));

    return 0;
}
