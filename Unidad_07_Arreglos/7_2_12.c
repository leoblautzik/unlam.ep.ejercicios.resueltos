#include <stdio.h>
void inicializar(int[][15], int, int);
void cargarTours(int[][15], int[], int[]);
void pasajesVendidosPorTour(int[], int);
void agenciaConMaxCantPasajesVendidos(int[], int);

int main() {
  int mat[10][15];
  int pasajesPorTour[10] = {0};
  int pasajesPorAgencia[15] = {0};
  inicializar(mat, 10, 15);
  cargarTours(mat, pasajesPorTour, pasajesPorAgencia);
  pasajesVendidosPorTour(pasajesPorTour, 10);
  agenciaConMaxCantPasajesVendidos(pasajesPorAgencia, 15);
  return 0;
}

void inicializar(int mat[][15], int cf, int cc) {
  int i, j;
  for (i = 0; i < cf; i++)
    for (j = 0; j < cc; j++)
      mat[i][j] = 0;
}

void agenciaConMaxCantPasajesVendidos(int ppa[], int ce) {
  int i;
  int max = ppa[0];
  int agenciaMax = 0;
  for (i = 0; i < ce; i++) {
    if (ppa[i] > max) {
      max = ppa[i];
      agenciaMax = i;
    }
  }
  printf("La agencia que vendió mas pasajes es la Nro. %d, con %d pasajes "
         "vendidos\n",
         agenciaMax + 1, max);
}

void pasajesVendidosPorTour(int pasajesVendidosPorTour[], int ce) {
  int i;
  printf("\nPasajes vendidos por Tour\n");
  printf("Tour\t\tPasajes\n");
  for (i = 0; i < ce; i++) {
    printf("%d\t\t%d\n", i + 1, pasajesVendidosPorTour[i]);
  }
}

void cargarTours(int mat[][15], int ppt[], int ppa[]) {

  int agencia, tour, cantPasajes, i, j;
  printf("\nIngreso de datos: \n");
  printf("Ingrese el código de agencia: ");
  do {
    scanf("%d", &agencia);
  } while (agencia < 0 || agencia > 15);

  while (agencia != 0) {
    printf("Ingrese el código de tour: ");
    do {
      scanf("%d", &tour);
    } while (tour < 1 || tour > 10);

    printf("Ingrese cantidad de pasajes: ");
    do {
      scanf("%d", &cantPasajes);
    } while (cantPasajes < 1 || cantPasajes > 20);

    mat[agencia - 1][tour - 1] += cantPasajes;
    ppt[tour - 1] += cantPasajes;
    ppa[agencia - 1] += cantPasajes;

    printf("Ingrese el código e agencia: ");
    do {
      scanf("%d", &agencia);
    } while (agencia < 0 || agencia > 15);
  }
}
