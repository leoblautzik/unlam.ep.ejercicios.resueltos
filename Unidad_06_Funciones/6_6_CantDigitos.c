#include <stdio.h>

int CantidadDigitos(int, int);
int main()
{
    int i, cont=0,c3,c4;
    for (i=10001;i<=90009;i++)
    {
        c3=CantidadDigitos(i,3);
        c4=CantidadDigitos(i,4);
        if (c4>0 && c3>c4)
        {
            cont++;
            printf("%7d",i);
        }
    }

    printf("\n\nCantidad total: %d ",cont);
    return 0;
}

int CantidadDigitos(int num, int digito)
{
    int cont=0;
    while(num)
    {
        if (num%10==digito)
            cont++;
        num/=10;
    }
    return cont;
}
