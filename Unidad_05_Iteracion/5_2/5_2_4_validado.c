#include <stdio.h>
#include <ctype.h>

int main()
{
    float totalCheque =0, totalEfectivo=0, totalTarjeta=0, importe;
    char codigo;

    do
    {
        printf("Ingrese el codigo (C cheque, E efectivo, T tarjeta, F salir):");
        scanf("%c", &codigo);
        codigo = toupper(codigo);
        getchar();
    }while(codigo !='C' && codigo!='E' && codigo!='T' && codigo!='F');

    while (codigo!='F')
    {
        do
        {
            printf("Ingrese el importe:");
            scanf("%f",&importe);
        }while (importe <=0);

        switch(codigo)
        {
            case 'C':
                importe *=1.2;
                totalCheque+=importe;
                break;
            case 'E':
                importe *=0.9;
                totalEfectivo+=importe;
                break;
            case 'T':
                importe *=1.12;
                totalTarjeta+=importe;
        }

       do
        {
            printf("Ingrese el codigo (C cheque, E efectivo, T tarjeta, F salir):");
            getchar(); //fflush(stdin);
            scanf("%c", &codigo);
            codigo = toupper(codigo);
        }while(codigo !='C' && codigo!='E' && codigo!='T' && codigo!='F');
    }//cierre de la condicion de fin

    printf("\n-------------------------------");
    printf("\nEfectivo en Caja  : $%10.2f", totalEfectivo);
    printf("\nVentas con Tarjeta: $%10.2f", totalTarjeta);
    printf("\nVentas con Cheque : $%10.2f", totalCheque);
    printf("\nTotal de Venta    : $%10.2f", totalEfectivo + totalTarjeta + totalCheque);
    printf("\nImporte del IVA   : $%10.2f", (totalEfectivo + totalTarjeta + totalCheque)*0.21);
    printf("\n-------------------------------\n");

    return 0;
}
