#include <stdio.h>


int main()
{
    int cantHorasT = 0;
    float valorHora = 0;
    printf("Ingrese la cantidad de horas trabajadas \n");
    scanf("%d", &cantHorasT);
    printf("Ingrese el valor hora \n");
    scanf("%f", &valorHora);
    printf("El sueldo es: %8.2f \n", cantHorasT * valorHora);
    return 0;

}
