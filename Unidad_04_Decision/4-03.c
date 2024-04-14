/**
 * Confeccionar un programa que pueda determinar de 3 números enteros
 * que se ingresan si alguno de ellos es igual a la suma de los otros dos.
 */

#include <stdio.h>

int main()
{
    int num1, num2, num3, mayor;
    printf("Ingrese un número: ");
    scanf("%d", &num1);
    printf("Ingrese otro número: ");
    scanf("%d", &num2);
    printf("Ingrese otro más: ");
    scanf("%d", &num3);

    if (num1 == num2 + num3)
        printf("%d = %d + %d\n", num1, num2, num3);
    else if (num2 == num1 + num3)
        printf("%d = %d + %d\n", num2, num1, num3);
    else if (num3 == num1 + num2)
        printf("%d = %d + %d\n", num3, num1, num2);
    else
        printf("Ninguno es igual a la suma de los otros dos\n");
    return 0;
}
