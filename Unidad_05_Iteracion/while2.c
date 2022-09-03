#include <stdio.h>

int main()
{
    int suma=0, num;

    printf("Ingrese un numero:");
    scanf("%d",&num);

    while(num%2==0 || (num>=1000&&num<=2000))
    {
        suma+=num;

        printf("Ingrese un numero:");
        scanf("%d",&num);
    }

    printf("Suma = %d", suma);

    return 0;
}
