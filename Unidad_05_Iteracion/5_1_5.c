/*Confeccionar un programa para calcular la suma de los primeros N números naturales.
  El valor de N lo solicita por teclado el programa.*/

#include <stdio.h>
int main()
{
    int i, suma=0, num;

    printf("Ingrese un numero positivo mayor a 0: ");
    scanf("%d", &num);
    if(num > 0){

        for (i=1;i<=num;i++){
            //printf("entre al for\n");
            suma+=i;
        }
        printf("La suma da: %d\n", suma);
    }
    else

        printf("Numero incorrecto\n");


    return 0;
}
