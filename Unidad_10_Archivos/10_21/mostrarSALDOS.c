#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int nroCajaAhorro;
    char apeNom[31];
    float saldo;
} Cuenta;

int main()
{
    Cuenta ca;
    int i;
    FILE *saldos;
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
        printf("%d\t%-30s\t%10.2f\n", ca.nroCajaAhorro, ca.apeNom, ca.saldo);
        i++;
        fread(&ca, sizeof(ca), 1, saldos);
    }
    printf("\nCantidad de registros leidos: %d\n", i);
    fclose(saldos);
}
