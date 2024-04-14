/**
 * Ejercicio 4-1
 * Se ingresan 3 números distintos. Determinar el mayor.
 */
#include <stdio.h>

int main()
{
    int num1, num2, num3, mayor;
    printf("Ingrese un número: ");
    scanf("%d", &num1);
    printf("Ingrese otro número: ");
    scanf("%d", &num2);
    printf("Ingrese otro más número: ");
    scanf("%d", &num3);

    mayor = num1;

    if (num2 > mayor)
        mayor = num2;
    if (num3 > mayor)
        mayor = num3;

    printf("El mayor es: %d\n", mayor);
}
