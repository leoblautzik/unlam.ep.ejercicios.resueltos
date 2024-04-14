#include <ctype.h>
#include <stdio.h>

int main()
{
    char enMinuscula, car;
    // a=85 e=101 i=105 o=1111 u=117, A=65, E=65, I=73, O=79, U=85;

    printf("Ingrese un caracter alfanumerico: ");
    scanf("%c", &car);
    enMinuscula = tolower(car);
    if (enMinuscula == 'a' || enMinuscula == 'e' || enMinuscula == 'i' || enMinuscula == 'o' || enMinuscula == 'u')
        printf("El codigo ASCII de la vocal ingresada es: %d\n", car);
    else
        printf("El caracter ingresado no es una vocal\n");
    return 0;
}
