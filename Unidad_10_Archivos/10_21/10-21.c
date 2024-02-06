#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int nroCajaAhorro;
    char apeNom[31];
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
int cargarSaldos(Cuenta[], int);
void actualizarSaldos(Cuenta[], int);
void mostrarCuentasConMasDeCincoExtracciones(Cuenta[], int[], int);
void registrarMovimientos(Cuenta[], int[], int);

int main()
{
    Cuenta cuentas[20000];
    int cantidadDeExtracciones[20000] = {0};
    int cantidadDeCuentas = cargarSaldos(cuentas, 20000);

    registrarMovimientos(cuentas, cantidadDeExtracciones, cantidadDeCuentas);
    actualizarSaldos(cuentas, cantidadDeCuentas);
    mostrarCuentasConMasDeCincoExtracciones(cuentas, cantidadDeExtracciones, cantidadDeCuentas);
    return 0;
}

void registrarMovimientos(Cuenta cuentas[], int cantidadDeExtracciones[], int ce)
{
    int posCuenta;
    Movimiento movimiento;
    FILE *movis, *sinSaldo;
    movis = fopen("MOVI", "rb");
    if (movis == NULL)
    {
        printf("Error al abrir el archivo MOVI.");
        getchar();
        exit(1);
    }
    sinSaldo = fopen("SIN_SALDO", "wb");
    if (sinSaldo == NULL)
    {
        printf("Error al abrir el archivo SIN_SALDO.");
        getchar();
        exit(1);
    }

    fread(&movimiento, sizeof(movimiento), 1, movis);
    while (!feof(movis))
    {
        posCuenta = buscaCuenta(cuentas, ce, movimiento.nroCajaAhorro);
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
}

void mostrarCuentasConMasDeCincoExtracciones(Cuenta cuentas[], int cantidadDeExtracciones[], int ce)
{
    int i;
    printf("C.Ahorro\tCant.Extracciones\n"); // imprimir titulos
    for (i = 0; i < ce; i++)
    {
        if (cantidadDeExtracciones[i] > 5)
        {
            printf("%d\t\t%3d\n", cuentas[i].nroCajaAhorro, cantidadDeExtracciones[i]);
        }
    }
}

void actualizarSaldos(Cuenta cuentas[], int ce)
{
    FILE *saldos;
    int i;
    saldos = fopen("SALDOS", "wb");
    for (i = 0; i < ce; i++)
    {
        fwrite(&cuentas[i], sizeof(Cuenta), 1, saldos);
    }
    fclose(saldos);
}

int cargarSaldos(Cuenta cuentas[], int ce)
{
    FILE *saldos;
    int i;
    Cuenta ca;
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
    fclose(saldos);
    return i;
}

int buscaCuenta(Cuenta cuentas[], int ce, int vb)
{
    int i = 0, pos = -1;
    while (i < ce && cuentas[i].nroCajaAhorro != vb)
    {
        i++;
    }
    if (i < ce)
        pos = i;
    return pos;
}
