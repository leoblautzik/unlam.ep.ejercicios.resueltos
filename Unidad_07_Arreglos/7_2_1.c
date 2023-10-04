#include <stdio.h>
void CARGAR (int[][3], int, int);
void MOSTRAR (int[][3], int, int);
void MULTIPLICAR (int[][3], int, int, int);

int
main ()
{
  int mat[3][3], numero;
  printf ("Ingrese un numero entero\n");
  scanf ("%d", &numero);

  CARGAR (mat, 3, 3);
  printf ("Matriz\n");
  MOSTRAR (mat, 3, 3);

  MULTIPLICAR (mat, 3, 3, numero);
  printf ("Matriz * %d: \n", numero);
  MOSTRAR (mat, 3, 3);

  return 0;
}

void
MULTIPLICAR (int m[][3], int cf, int cc, int num)
{

  int f, c;
  for (f = 0; f < cf; f++)
    for (c = 0; c < cc; c++)
      {
        m[f][c] *= num;
      }
}

void
CARGAR (int m[][3], int cf, int cc)
{
  int f, c;
  for (f = 0; f < cf; f++)
    for (c = 0; c < cc; c++)
      {
        printf ("Ingrese un valor:");
        scanf ("%d", &m[f][c]);
      }
}

void
MOSTRAR (int m[][3], int cf, int cc)
{
  int f, c;
  for (f = 0; f < cf; f++)
    {
      for (c = 0; c < cc; c++)
        printf ("%6d", m[f][c]);

      printf ("\n");
    }
}
