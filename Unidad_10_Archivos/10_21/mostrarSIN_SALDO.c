#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int sucursal;
    int nroCajaAhorro;
    int mes;
    int dia;
    int operacion;
    float importe;
} Movimiento;

int main()
{
    Movimiento movimiento;
    int i;
    FILE *sinSaldo;
    sinSaldo = fopen("SIN_SALDO", "rb");
    if (sinSaldo == NULL)
    {
        printf("Error al abrir el archivo.");
        getchar();
        exit(1);
    }
    i = 0;
    fread(&movimiento, sizeof(movimiento), 1, sinSaldo);
    while (!feof(sinSaldo))
    {
        printf("%d\t%10.2f\n", movimiento.nroCajaAhorro, movimiento.importe);
        i++;
        fread(&movimiento, sizeof(movimiento), 1, sinSaldo);
    }
    // printf("%d", cantidadDeCuentas);
    fclose(sinSaldo);
}
