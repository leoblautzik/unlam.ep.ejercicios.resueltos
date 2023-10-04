#include <stdio.h>
#define TAM 5

void cargarProductos(float[], int);
void cargarVentas(int[][12], float[], float[], float[], int);
int productoDeMayorRecaudacion(float[], int);
void detallePorProductoYporMes(int[][12], int);
int trimestreDeMenorRecaudacion(float[], int);

int main() {
  float productos[TAM];
  int ventas[TAM][12] = {{0}};
  float ventasPorProducto[TAM] = {0};
  float ventasPorTrimestre[4] = {0};

  cargarProductos(productos, TAM);

  cargarVentas(ventas, productos, ventasPorProducto, ventasPorTrimestre, TAM);
  printf("\nEl producto con mayor recaudación fue: %d\n",
         productoDeMayorRecaudacion(ventasPorProducto, TAM));
  printf("\nEl trimestre de menor recaudación fue: %d\n",
         trimestreDeMenorRecaudacion(ventasPorTrimestre, 4));
  printf("Detalle de unidades vendidas por producto y por mes\n");
  detallePorProductoYporMes(ventas, TAM);

  return 0;
}

void cargarProductos(float productos[], int ce) {
  int i = 0;
  int producto;
  float precio;
  for (i = 0; i < ce; i++) {
    printf("Ingrese el precio del producto %d: ", i + 1);
    do {
      scanf("%f", &precio);
    } while (precio <= 0);
    productos[i] = precio;
  }
}

void cargarVentas(int ventas[][12], float productos[],
                  float ventasPorProducto[], float ventasPorTrimestre[],
                  int ce) {

  int codPro, cantidadVendida, trimestre;
  float precio;
  int dia, mes;
  printf("Ingrese el código de producto: ");
  do {
    scanf("%d", &codPro);
  } while (codPro < 0 || codPro > TAM);

  while (codPro > 0) {
    printf("Ingrese el día de la venta: ");
    do {
      scanf("%d", &dia);
    } while (dia < 1 || dia > 31);

    printf("Ingrese el mes de la venta: ");
    do {
      scanf("%d", &mes);
    } while (mes < 1 || mes > 12);

    printf("Ingrese la cantidad de unidades vendidas: ");
    do {
      scanf("%d", &cantidadVendida);
    } while (cantidadVendida < 0);

    trimestre = (mes - 1) / 3;

    ventas[codPro - 1][mes - 1] += cantidadVendida;
    ventasPorProducto[codPro - 1] += productos[codPro - 1] * cantidadVendida;
    ventasPorTrimestre[trimestre] += productos[codPro - 1] * cantidadVendida;

    printf("Ingrese el código de producto: ");
    do {
      scanf("%d", &codPro);
    } while (codPro < 0 || codPro > TAM);
  }
}

int productoDeMayorRecaudacion(float ventasPorProducto[], int ce) {
  int i;
  float max = ventasPorProducto[0];
  int codProductoDeMayorRecaudacion = 1;
  for (i = 1; i < ce; i++) {
    if (ventasPorProducto[i] > max) {
      max = ventasPorProducto[i];
      codProductoDeMayorRecaudacion = i + 1;
    }
  }
  return codProductoDeMayorRecaudacion;
}

int trimestreDeMenorRecaudacion(float ventasPorTrimestre[], int ce) {
  int i;
  float min = ventasPorTrimestre[0];
  int trimestreMin = 0;
  for (i = 1; i < ce; i++) {
    if (ventasPorTrimestre[i] < min) {
      min = ventasPorTrimestre[i];
      trimestreMin = i;
    }
  }
  return trimestreMin + 1;
}

void detallePorProductoYporMes(int ventas[][12], int cf) {
  int i, j;
  printf("CodPro\tene\tfeb\tmar\t\abr\tmay\tjun\t");
  for (i = 0; i < TAM; i++) {
    printf("\n%d\t", i + 1);
    for (j = 0; j < 12; j++)
      printf("%d\t", ventas[i][j]);
  }
}
