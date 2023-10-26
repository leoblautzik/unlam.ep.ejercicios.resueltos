/*7.1.7 Se ingresan DNI, código de sector (1 a 5) y sueldo de los empleados de
  una empresa. Se sabe que como máximo la empresa tiene 100 empleados. Se
  desea: a. Cargar los datos de los empleados mediante la función
  CargaEmpleados. La carga finaliza con un empleado con DNI 99. b. Generar un
  vector con la cantidad de empleados en cada sector mediante la función
  CuentaPorSector y mostrarlo en forma de listado.
  c. Determinar el importe total a pagar de sueldos mediante la función
  TotalAPagar. d. Volver a mostrar el listado de cantidad de empleados por
  sector, pero esta vez ordenado de menor a mayor por cantidad de empleados en
  cada sector.*/

#include <stdio.h>

int IngresaEntero (int, int);
int ingresarSector (int, int);
int cargaEmpleados (int[], int[], float[], int);
float ingresarSueldo ();
void cuentaPorSector (int[], int[], int);
int
main ()
{
  int DNIs[100];
  int sectores[5];
  float sueldos[100];
  int empleadosPorSector[5] = { 0 };
  int ce = cargaEmpleados (DNIs, sectores, sueldos, 100);
  cuentaPorSector (empleadosPorSector, sectores, ce);

  return 0;
}

int
cargaEmpleados (int DNIs[], int sectores[], float sueldos[], int ceMax)
{
  int contador = 0;
  int dni;

  printf ("Ingrese un DNI para el empleado en posicion %d: ", contador + 1);
  scanf ("%d", &dni);

  while (dni != 99 && contador < ceMax)
    {
      DNIs[contador] = dni;
      sectores[contador] = ingresarSector (1, 5);
      sueldos[contador] = ingresarSueldo ();
      contador++;
      printf ("Ingrese un DNI para el empleado en posicion %d: ",
              contador + 1);
      scanf ("%d", &dni);
    }

  return contador;
}

void
cuentaPorSector (int empleadosPorSector[], int sectores[], int ce)
{
  for (int i = 0; i < ce; i++)
    {
      empleadosPorSector[sectores[i] - 1]++;
    }

  printf ("Empleados por sector\n");
  printf ("Sector\tCant.Empleados\n");

  for (int i = 0; i < 5; i++)
    printf ("%d\t%d\n", i + 1, empleadosPorSector[i]);
}

void
ordenaPorSector (int empleadosPorSector[])
{
  int nroSector[5];
  for (int i = 0; i < 5; i++)
    nroSector[i] = i + 1;
}

float
totalApagar (float sueldos[], int ce)
{
  float total = 0;

  for (int i = 0; i < ce; i++)
    total += sueldos[i];

  return total;
}

int
ingresarSector (int li, int ls)
{
  int sector = IngresaEntero (li, ls);
  return sector;
}

int
IngresaEntero (int li, int ls)
{
  int error = 0, n;
  do
    {
      if (error) // distinto de 0 verdadero
        printf ("Numero invalido.\n");

      printf ("Ingrese un numero (entre %d y %d):", li, ls);
      scanf ("%d", &n);

      error = 1;
    }
  while (n < li || n > ls);

  return n;
}

float
ingresarSueldo ()
{
  float sueldo;
  do
    {
      printf ("Ingrese el sueldo: ");
      scanf ("%f", &sueldo);
    }
  while (sueldo < 0);

  return sueldo;
}
