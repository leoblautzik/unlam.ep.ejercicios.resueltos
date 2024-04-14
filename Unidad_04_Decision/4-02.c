/**
 * Ejercicio 4.2
 * Dados tres números determinar e informar con un mensaje
 * si el primer número ingresado es menor que los otros dos.
 */
#include <stdio.h>

int main()
{
    int num1, num2, num3;
    printf("Ingrese un número: ");
    scanf("%d", &num1);
    printf("Ingrese otro número: ");
    scanf("%d", &num2);
    printf("Ingrese otro más número: ");
    scanf("%d", &num3);

    if (num1 < num2 && num1 < num3)
    {
        printf("Efectivamente, el primer número ingresado es menor que los otros dos. \n");
    }
    else
        printf("Lamentablemente, el primer número ingresado NO es menor que los otros dos. \n");
}
