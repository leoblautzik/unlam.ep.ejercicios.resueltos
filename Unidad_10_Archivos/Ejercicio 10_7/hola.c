#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char codA[11];
    int dia;
    int numVuelo;
    float costo;
    int pasajeros;
} T_Vuelos;

typedef struct
{
    int dni;
    int numVuelo;
} T_Pasajeros;

int CargaVec(T_Vuelos[], int);
void ActualizarPasajeros(T_Vuelos[], int);
void GrabarArch(T_Vuelos[], int);

int main()
{
    int cant, i = 0;
    T_Vuelos Vvuelos[150];
    cant = CargaVec(Vvuelos, 150);
    printf("%d", cant);
    ActualizarPasajeros(Vvuelos, cant);
    for (i = 0; i < cant; i++)
    {
        printf("%d", Vvuelos[i].pasajeros);
    }
    GrabarArch(Vvuelos, cant);
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int CargaVec(T_Vuelos V[], int ce)
{
    T_Vuelos aux;
    FILE *pf;
    int i = 0;

    pf = fopen("Vuelos.dat", "rb");
    if (pf == NULL)
    {
        printf("\nNo se pudo abrir correctamente\t");
        exit(1);
    }

    fread(&aux, sizeof(T_Vuelos), 1, pf);
    while (!feof(pf) && i < ce)
    {
        if (strcmp(aux.codA, "Aero1") == 0)
        {
            V[i] = aux;
            i++;
        }
        fread(&aux, sizeof(T_Vuelos), 1, pf);
    }
    fclose(pf);
    return i;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ActualizarPasajeros(T_Vuelos V[], int ce)
{
    FILE *pf;
    T_Vuelos aux;
    int i = 0;

    pf = fopen("Pasajeros.dat", "rb");
    if (pf == NULL)
    {
        printf("\nNo se pudo abrir correctamente\t");
        exit(1);
    }

    fread(&aux, sizeof(T_Pasajeros), 1, pf);
    while (!feof(pf) && i < ce)
    {
        if (aux.numVuelo == V[i].numVuelo)
        {
            V[i].pasajeros++;
        }
        i++;
        fread(&aux, sizeof(T_Pasajeros), 1, pf);
    }
    fclose(pf);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void GrabarArch(T_Vuelos V[], int ce)
{
    int i;
    FILE *pf;

    printf("Pase por aqui..");

    pf = fopen("Aero1.dat", "wb");
    if (pf == NULL)
    {
        printf("\nNo se pudo abrir correctamente\t");
        exit(1);
    }

    for (i = 0; i < ce; i++)
    {
        fwrite(&V[i], sizeof(T_Vuelos), 1, pf);
    }
    printf("Pase por aqui..");
    fclose(pf);
}
