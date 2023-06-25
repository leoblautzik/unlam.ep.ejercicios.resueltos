#include <stdio.h>
#include <ctype.h>
#include <sys/cdefs.h>

int main(){
    float importe, ventasTarjeta=0, ventasCheque=0, ventasEfectivo=0, iva=0;
    char formaPago;

    do
    {
        printf("Ingrese la forma de pago: (C/E/T/F para salir)");
        scanf("%c", &formaPago);
        formaPago = toupper(formaPago); 
    }while (formaPago != 'C' && formaPago != 'E' && formaPago != 'T' && formaPago != 'F');

    while (formaPago != 'F')
    {
        do{
            printf("Ingrese el iomporte: ");
            scanf("%f", &importe);
        }while (importe <= 0);

        switch(formaPago)
        {
            case 'C':
                importe *= 1.2;
                ventasCheque += importe;
                break;
            case 'E': 
                importe *= 0.9;
                ventasEfectivo += importe;
                break;
            case 'T': 
                importe *= 1.12;
                ventasTarjeta += importe;
                break;
        }
        do
        {
            printf("Ingrese la forma de pago: (C/E/T/F para salir)");
            scanf("%c", &formaPago);
            formaPago = toupper(formaPago); 
        }while (formaPago != 'C' && formaPago != 'E' && formaPago != 'T' && formaPago != 'F');
    }

}
