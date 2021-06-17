#include <stdio.h>
#include <ctype.h>
#define recargoCheque 20
#define descuentoEfectivo 10
#define recargoTarjeta 12
#define IVA 21

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int main()
{
    float importeVenta;
    float efectivoEnCaja=0, ventasConTarjeta=0, ventasConCheque=0;
    char formaDePago;
    int error = 0;
    do
    {
        if (error == 1)
            printf("Forma de pago incorrecta!\n");

        printf("Ingrese la forma de pago: ");

        scanf("%c", &formaDePago);
        formaDePago = toupper(formaDePago);
        error = 1;
        clean_stdin();

    }while(!((formaDePago == 'C') || (formaDePago == 'E') 
                || (formaDePago == 'T') || (formaDePago == 'F')));

    while(formaDePago !='F')
    {

        error = 0;
        do 
        {
            if(error == 1)
                printf("Importe incorrecto!\n ");
            printf("Ingrese el importe de la venta: ");
            scanf("%f",&importeVenta);
            error = 1;
            clean_stdin();
        }while(importeVenta <= 0);

        switch(formaDePago)
        {
            case 'C':
                importeVenta = importeVenta * (1+recargoCheque/100); 
                ventasConCheque += importeVenta;
                break;
            case 'E':
                importeVenta = importeVenta * (1-descuentoEfectivo/100);
                efectivoEnCaja += importeVenta;
                break;
            case 'T':
                importeVenta = importeVenta * (1+recargoTarjeta/100);
                ventasConTarjeta += importeVenta;
                break;
        }

        error = 0;
        do
        {
            if (error == 1)
                printf("Forma de pago incorrecta! \n");

            printf("Ingrese la forma de pago: ");
            scanf("%c", &formaDePago);
            clean_stdin();
            formaDePago = toupper(formaDePago);
            error = 1;

        }while(!((formaDePago == 'C') || (formaDePago == 'E') 
                    || (formaDePago == 'T') || (formaDePago == 'F')));
    }

    if(efectivoEnCaja + ventasConTarjeta + ventasConCheque == 0)
        printf("Sin procesamiento");
    else
    { 

        printf("Efectivo en caja \t\t$ %6.2f\n", efectivoEnCaja); 
        printf("Ventas con Tarjeta de credito \t$ %6.2f\n", ventasConTarjeta); 
        printf("Ventas con cheque \t\t$ %6.2f\n", ventasConCheque); 
        printf("Total de ventas\t\t\t$ %6.2f\n", efectivoEnCaja+ventasConTarjeta+ventasConCheque); 
        printf("Importe del IVA\t\t\t$ %6.2f\n", (efectivoEnCaja+ventasConTarjeta+ventasConCheque) * IVA/100);
    }
    return 0;
}


