#include <ctype.h>
#include <stdio.h>
#include <string.h>

void LeerTexto(char[], int);

int main() {
  char nombre[20];
  printf("Ingrese un nombre: ");
  LeerTexto(nombre, 20);
  printf("El nombre ingresado es: %s", nombre);
  return 0;
}

void LeerTexto(char texto[], int largo) {
  int i;
  fgets(texto, largo, stdin);
  i = 0;
  while (texto[i] != '\0') {
    if (texto[i] == '\n')
      texto[i] = '\0';
    else
      i++;
  }
}
