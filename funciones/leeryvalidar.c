#include <stdio.h>

int  leeryvalidarentreconfin(int desde, int hasta, int fin);
int main()
{

    int dato = leeryvalidarentreconfin(1,40,1);
    printf("Es dato valido: %d\n", dato);
}
int leeryvalidarentreconfin(int desde, int hasta, int fin)
{
    int dato;
    do 
    {
        printf("Ingrese un dato (%d para terminar): ", fin);
        scanf("%d", &dato);

    } while (dato != fin && (dato < desde || dato > hasta)) ;   
    return dato;
}
