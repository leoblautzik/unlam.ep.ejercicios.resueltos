#include <stdio.h>

int leerYvalidar(int, int);
int estaDentroDelRango(int, int, int);
int esPar(int);
int main()
{
    int numero;
    int contador100y500 = 0, contadorPares500y1200 = 0, contador1200y2000 = 0, acum1200y2000 = 0;
    numero = leerYvalidar(99, 2000);
    while (numero != 99)
    {
        // Cantidad de números ingresados entre 100 y 500
        if (estaDentroDelRango(numero, 100, 500) == 1)
            contador100y500++;
        else if (estaDentroDelRango(numero, 500, 1200) == 1 && esPar(numero) == 1)
            contadorPares500y1200++;
        else if (estaDentroDelRango(numero, 1200, 2000) == 1)
        {
            acum1200y2000 += numero;
            contador1200y2000++;
        }
        numero = leerYvalidar(99, 2000);
    }

    printf("Entre 100 y 500: %d ", contador100y500);
    printf("\nPares entre 500 y 1200: %d", contadorPares500y1200);
    if (contador1200y2000 > 0)
        printf("\nPromedio entre 1200 y 2000: %.2f\n", (float)acum1200y2000 / contador1200y2000);
}

int leerYvalidar(int inf, int sup)
{
    int numero;
    int flag = 0;
    do
    {
        if (flag == 0)
        {
            printf("Ingrese un valor entero entre %d y %d (99 para salir): ", inf, sup);
            flag = 1;
        }
        else
            printf("Valor incorrecto -> Ingrese un valor entero entre %d y %d: ", inf, sup);

        scanf("%d", &numero);

    } while (estaDentroDelRango(numero, inf, sup) == 0);

    return numero;
}

int estaDentroDelRango(int numero, int inf, int sup)
{
    int seEncuentra = 0;
    if (numero >= inf && numero <= sup)
        seEncuentra = 1;
    return seEncuentra;
}
int esPar(int valor)
{
    int par = 0;
    if (valor % 2 == 0)
        par = 1;
    return par;
}
