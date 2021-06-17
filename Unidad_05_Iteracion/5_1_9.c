/*Confeccionar un programa que exhiba por pantalla una lista, a dos columnas,
 con los primeros 15 números impares en la primera y los 15 primeros pares en la segunda,
  incluyendo los títulos..*/

#include <stdio.h>
#define cantAlumnos 2
#define repeticiones 15

int main()
{
    int i;
    for (i=1;i<=repeticiones*2;i+=2)
        printf("\n%5d %5d", i, i+1);


    return 0;
}
