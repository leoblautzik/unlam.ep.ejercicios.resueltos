/*7.1.7 Se ingresan DNI, código de sector (1 a 5) y sueldo de los empleados de una empresa. Se sabe que como
máximo la empresa tiene 100 empleados. Se desea:
a. Cargar los datos de los empleados mediante la función CargaEmpleados. La carga finaliza con un
empleado con DNI 99.
b. Generar un vector con la cantidad de empleados en cada sector mediante la función
CuentaPorSector y mostrarlo en forma de listado.
c. Determinar el importe total a pagar de sueldos mediante la función TotalAPagar.
d. Volver a mostrar el listado de cantidad de empleados por sector, pero esta vez ordenado de
menor a mayor por cantidad de empleados en cada sector.*/
#include <stdio.h>
#include <conio.h>
void divisor();
void Cargaempleados(int [][2], float[], int);
void CargaSector(int[][2], int);
void CargaSueldo(float[], int);
void CuentaPorSector(int[][2], int[][2], int);
void MostrarCantidadSectores(int[][2]);
float TotalAPagar(float [], int);
void OrdenarCantidadSectores(int [][2]);
int main()
{
    int tamanio = 5;
    int mEmpleadosSectores[5][2] = {{0}}, vCantidadPorSector[5][2] = {{1,0},{2,0},{3,0},{4,0},{5,0}};
    float vSueldos [5] = {{0}};

    CargaEmpleados(mEmpleadosSectores, vSueldos, tamanio);
    CuentaPorSector(vCantidadPorSector, mEmpleadosSectores, tamanio);
    MostrarCantidadSectores(vCantidadPorSector);

    printf("El total a pagar es: $ %.2f", TotalAPagar(vSueldos, tamanio));

    OrdenarCantidadSectores(vCantidadPorSector);

    divisor();
    printf("Cantidades ordenadas");
    divisor();
    MostrarCantidadSectores(vCantidadPorSector);
    getch();
}

void divisor()
{
    printf("\n==============================\n");
}
void CargaEmpleados(int mEmpleadosSectores[][2], float vSueldos[], int tamanio)
{
    int dniIngresado, cont = 0;

    do {

        printf("Ingrese un DNI para el empleado en posicion %d: ", cont+1);
        scanf("%d", &dniIngresado);

        if(dniIngresado != 99 )
        {
            mEmpleadosSectores[cont][1] = dniIngresado;
            CargaSector(mEmpleadosSectores, cont);
            CargaSueldo(vSueldos, cont);
        }

        cont++;
    } while(dniIngresado != 99 && cont <tamanio);

}

void CargaSector(int mEmpleadoSectores[][2], int posicionEmpleado)
{
    int sector = 0, incorrecto = 0;
    do {
        if(incorrecto)
            printf("Codigo de sector invalido! (1 a 5) \n");

        printf("Ingrese el sector para el empleado en posicion %d: ", posicionEmpleado+1)   ;
        scanf("%d", &sector);

        if(sector < 1 || sector > 5)
            incorrecto = 1;

    } while(sector < 1 || sector > 5);

    mEmpleadoSectores[posicionEmpleado][2] = sector;
}

void CargaSueldo(float vSueldos[], int posicionEmpleado)
{
    int sueldo = -1, incorrecto = 0;
    do {
        if(incorrecto)
            printf("El sueldo debe ser mayor a cero! \n");

        printf("Ingrese el sueldo para el empleado en posicion %d: ", posicionEmpleado+1);
        scanf("%d", &sueldo);

        if(sueldo <= 0)
            incorrecto = 1;
    } while(sueldo <= 0 );

    vSueldos[posicionEmpleado] = sueldo;
}

void CuentaPorSector(int vCantidadPorSector[][2], int mEmpleadosSectores[][2], int tamanio)
{
    int i, indiceSector, sector;
    for(i = 0; i < tamanio; i++)
    {
        sector = mEmpleadosSectores[i][2];
        indiceSector = (sector-1);
        vCantidadPorSector[indiceSector][0] = sector;
        vCantidadPorSector[indiceSector][1] += 1;
    }
}

void MostrarCantidadSectores(int vCantidadPorSector[][2]) {
    int i;
    printf("\n || SECTOR || CANTIDAD || \n");
    for(i=0; i < 5; i++)
        printf(" ||   %d ||    %d  || \n",vCantidadPorSector[i][0],vCantidadPorSector[i][1]);
}

float TotalAPagar(float vSueldo[], int tamanio)
{
    int total = 0, cont = 0, sueldoCero = 0;

    while(cont < tamanio && !sueldoCero)
    {
        if(vSueldo[cont] != 0)
            total += vSueldo[cont];
        else
            sueldoCero = 1;
        cont++;
    }

    return total;
}

void OrdenarCantidadSectores(int vCantidadPorSector[][2])
{
    int i, desordenado = 1, cota = 4, auxSector, auxCantidad;

    while(desordenado)
    {
        desordenado = 0;
        for(i = 0; i < cota; i++)
        {
            if(vCantidadPorSector[i][1] > vCantidadPorSector[i+1][1])
            {
                auxSector = vCantidadPorSector[i+1][0];
                auxCantidad = vCantidadPorSector[i+1][1];

                vCantidadPorSector[i+1][0] = vCantidadPorSector[i][0];
                vCantidadPorSector[i+1][1] = vCantidadPorSector[i][1];

                vCantidadPorSector[i][0] = auxSector;
                vCantidadPorSector[i][1] = auxCantidad;

                desordenado = i;
            }
        }

        cota = desordenado;
    }
}
