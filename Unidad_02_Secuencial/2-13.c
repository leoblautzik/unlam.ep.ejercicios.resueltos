#include<stdio.h>

long sumacifras(long);
long sumacifrasX9(long);

int main()
{
    long numero;
    printf("\nIngrese un nume entero: ");
    scanf("%ld",&numero);
    printf("\n%ld\n", sumacifras(numero)); 
    printf("\n%ld\n", sumacifrasX9(numero)); 
    return 0;
}

long sumacifras(long numero) {
    long i, sum; 
    while(numero > 9){
        i = 1;
        sum = 0;
        while(numero >= i ) {
            sum += (numero / i) % 10;
            i*=10;
        }
        numero = sum;
    }
    return numero;
}
long sumacifrasX9(long n){
    int suma = n % 9;
    if(suma == 0) suma = 9;
    return suma;
}
