#include <stdio.h>

float promedio (float, float, float);

int main()
{
    int i;
    float a, b, c, pr;
    for (i=1;i<=10;i++)
    {
        printf("Ingrese 3 numeros: ");
        scanf("%f%f%f",&a,&b,&c);
        pr = promedio(a,b,c);
        printf("Promedio: %.2f\n\n", pr);
    }

    return 0;
}

float promedio (float x, float y, float c)
{
    float prome;
    prome = (x+y+c)/3;

    return prome;
}

