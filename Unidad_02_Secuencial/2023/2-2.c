#include <stdio.h>
#include <math.h>

int main(){
    int nota1, nota2, promedio;
    double PI = acos(-1.0);
    printf("Ingrese la nota 1: ");
    scanf("%d", &nota1);
    printf("Ingrese la nota 2: ");
    scanf("%d", &nota2);
    promedio = (nota1 + nota2) / 2;
    printf("La nota promedio es: %d\n", promedio);
    printf("PI vale: %lf\n", PI);

}
