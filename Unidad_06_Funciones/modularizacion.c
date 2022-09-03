#include<stdio.h>
int esNumeroPrimo(int);

int main()
{
    int cantPrimos=0,aVisualizar,posiblePrimo=2;

    do
    {
        printf("\n Ingrese la cantidad de numeros primos a visualizar: ");
        scanf("%d",&aVisualizar);
    }while(aVisualizar <=0);

    while(cantPrimos<aVisualizar)
    {
        if(esNumeroPrimo(posiblePrimo))
        {
            printf("\t %d",posiblePrimo);
            cantPrimos++;
        }
        posiblePrimo++;
    }

    return 0;
}

int esNumeroPrimo(int posiblePrimo)
{
    int esPrimo=1; //pongo un valor verdadero en la bandera, asumo que es primo hasta que encuentre un divisor
    int posibleDivisor=2;

    while(esPrimo==1 && posibleDivisor<posiblePrimo)
    {
        if(posiblePrimo%posibleDivisor==0)
            esPrimo=0; //si encuentro un divisor ya NO es primo
        else
            posibleDivisor++;
    }

    return esPrimo;
}
