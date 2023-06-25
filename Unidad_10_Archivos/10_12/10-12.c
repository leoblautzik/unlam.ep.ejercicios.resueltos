#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int nrovisitador;
    int codigomedicamento;
    int cantvendida;
} Venta;

int main()
{
    int total[15][30] = {0};
    float factXmedicamento[30] = {0};
    float totalXvisitador[15] = {0};
    int cliente;
    int visitador;
    int codMedicamento;
    int cantidadVendida;
    float importeFacturado;
    
    FILE *pf;
    pf = fopen("VENTAS.dat", "rb");
    if(pf == NULL)
    {
        printf("Error");
        getchar();
        exit(1);
    }
    Venta aux;
    fread(&aux, sizeof(Venta), 1, pf);
    while(!feof(pf))
    {
        total[aux.nrovisitador-1][aux.codigomedicamento-1] = aux.cantvendida; 
        fread(&aux, sizeof(Venta), 1, pf);
    }
    printf("\nIngrese Nro Cliente: ");
    scanf("%d", &cliente);
    while(cliente != 0)
    {
        printf("\nIngrese visitador: ");
        scanf("%d", &visitador);
        printf("\nIngrese Codigo Medicamento: ");
        scanf("%d", &codMedicamento);
        printf("\nIngrese Cant.Vendida: ");
        scanf("%d", &cantidadVendida);
        printf("\nIngrese Importre Facturado: ");
        scanf("%f", &importeFacturado);
        total[visitador-1][codMedicamento-1] += cantidadVendida;
        totalXvisitador[visitador-1] += importeFacturado;
        factXmedicamento[codMedicamento-1] += importeFacturado;
        printf("\nIngrese Nro Cliente: ");
        scanf("%d", &cliente);
    }
// Seguir

}
