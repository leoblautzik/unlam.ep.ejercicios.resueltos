#include<stdio.h>
#define DESCUENTO_1 0.045
#define DESCUENTO_2 0.080
#define DESCUENTO_3 0.105

<<<<<<< HEAD
=======
/*La farmacia Sindical efectúa descuentos a sus afiliados según el importe de la compra con la siguiente
escala:
a. menor de $55 el descuento es del 4.5%
b. entre $55 y $100 el descuento es del 8%
c. más de $100 el descuento es del 10.5%
Confeccionar un programa que reciba un importe e informe: el descuento y el precio neto a cobrar, con
mensajes aclaratorios.
*/

>>>>>>> 855ad7f (Consultas 2022)
int main(){

    float importe, descuento, neto;
    printf("Ingrese el importe: ");
    scanf("%f", &importe);

    if(importe < 55){
        descuento = importe * DESCUENTO_1;
    }
    else     
<<<<<<< HEAD
        if(importe >= 55 && importe <= 100){
=======
        if(importe <= 100){
>>>>>>> 855ad7f (Consultas 2022)
            descuento = importe * DESCUENTO_2;
        }
        else
        { 
            descuento = importe * DESCUENTO_3;
        }

    neto = importe - descuento;
<<<<<<< HEAD
    printf("Importe: %6.2f \nDescuento: %6.2f \nImporte a abonar: %6.2f \n", importe, importe*0.045, importe*(1-0.054));
=======
    printf("Importe: %6.2f \nDescuento: %6.2f \nImporte a abonar: %6.2f \n", importe, importe*DESCUENTO_1, importe*(1-DESCUENTO_1));
>>>>>>> 855ad7f (Consultas 2022)

    return 0;
}
