/*Mostrar por pantalla los números pares comprendidos entre 100 y 500*/
#include <stdio.h>
int main()
{
    int i;
    for(i=100;i<=500;i+=2)  
        printf("%4d", i);
    return 0;
}
