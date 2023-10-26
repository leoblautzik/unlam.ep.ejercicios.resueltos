#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int nroCajaAhorro;
    char saldoseNom[31];
    float saldo;
} Cuenta;

typedef struct
{
    int sucursal;
    int nroCajaAhorro;
    int mes;
    int dia;
    int operacion;
    float importe;
} Movimiento;

int buscaCuenta(Cuenta[], int, int);
int main()
{
    Cuenta ca;
    Cuenta cuentas[20000];
    int cantidadDeExtracciones[20000] = {0};
    Movimiento movimiento;
    int i, cantidadDeCuentas, posCuenta;
    FILE *saldos, *movis, *sinSaldo;
    saldos = fopen("SALDOS", "rb");
    if (saldos == NULL)
    {
        printf("Error al abrir el archivo.");
        getchar();
        exit(1);
    }
    i = 0;
    fread(&ca, sizeof(ca), 1, saldos);
    while (!feof(saldos))
    {
        printf("%d\n", ca.nroCajaAhorro);
        cuentas[i] = ca;
        i++;
        fread(&ca, sizeof(ca), 1, saldos);
    }
    cantidadDeCuentas = i;
    // printf("%d", cantidadDeCuentas);
    fclose(saldos);
    movis = fopen("MOVI", "rb");
    if (movis == NULL)
    {
        printf("Error al abrir el archivo.");
        getchar();
        exit(1);
    }
    sinSaldo = fopen("SIN_SALDO", "wb");
    if (sinSaldo == NULL)
    {
        printf("Error al abrir el archivo.");
        getchar();
        exit(1);
    }
    fread(&movimiento, sizeof(movimiento), 1, movis);
    while (!feof(movis))
    {
        posCuenta = buscaCuenta(cuentas, cantidadDeCuentas, movimiento.nroCajaAhorro);
        // printf("%d\n", movimiento.nroCajaAhorro);
        if (posCuenta != -1)
        {
            if (movimiento.operacion == 1)
                cuentas[posCuenta].saldo += movimiento.importe;
            else
            {
                if (cuentas[posCuenta].saldo < movimiento.importe)
                    fwrite(&movimiento, sizeof(movimiento), 1, sinSaldo);
                else
                {
                    cuentas[posCuenta].saldo -= movimiento.importe;
                    cantidadDeExtracciones[posCuenta]++;
                }
            }
        }
        fread(&movimiento, sizeof(movimiento), 1, movis);
    }
    fclose(movis);
    fclose(sinSaldo);

    saldos = fopen("SALDOS", "wb");
    for (i = 0; i < cantidadDeCuentas; i++)
    {
        fwrite(&cuentas[i], sizeof(Cuenta), 1, saldos);
    }
    fclose(saldos);

    printf("C.Ahorro\tCant.Extracciones\n"); // imprimir titulos
    for (i = 0; i < cantidadDeCuentas; i++)
    {
        if (cantidadDeExtracciones[i] > 5)
        {
            printf("%d\t\t%d\n", cuentas[i].nroCajaAhorro, cantidadDeExtracciones[i]);
        }
    }
}

int buscaCuenta(Cuenta cuentas[], int ce, int vb)
{
    int i = 0, pos = -1;
    while (pos == -1 && i < ce)
    {
        if (cuentas[i].nroCajaAhorro == vb)
        {
            pos = i;
        }
        i++;
    }
    return pos;
}
