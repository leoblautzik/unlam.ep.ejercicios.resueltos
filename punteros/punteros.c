#include <stdio.h>

void incrementar(int *x)
{
    int y = *x;
    printf("%d\n", y);
    y++;
    *x = y;
}

void intercambiar(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

int main()
{
    int x = 10;
    int y = 20;
    printf("%d\n", x);
    printf("%p\n", &x);
    incrementar(&x);
    printf("%d\n", x);
    printf("%d\t%d\n", x, y);
    intercambiar(&x, &y);
    printf("%d\t%d\n", x, y);

    return 0;
}
