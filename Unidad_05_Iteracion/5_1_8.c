/*Dadas las edades y estaturas de 45 alumnos de un curso. Determinar:

a.  Edad promedio.
b.  Estatura promedio.
c.  Cantidad de alumnos mayores de 10 años.
d.  Cantidad de alumnos que miden menos de 1.40 cm.*/

#include <stdio.h>
#define cantAlumnos 2
#define HMAX 1.4
int main()
{
    int i, edad, sumaEdad=0, cantM10=0, cantm140=0;
    float altura, sumaAltura=0;
    float hMax = 1.4;
    for (i=1;i<=cantAlumnos;i++)
    {
        printf("\n----------------");
        printf("\nAlumno %d\n",i);

        printf("Ingrese la edad:");
        scanf("%d", &edad);

        printf("Ingrese la altura:");
        scanf("%f", &altura);

        sumaEdad+=edad;
        sumaAltura+=altura;

        if (edad>10)
            cantM10++;

        if (altura < (float)HMAX)
            cantm140++;
    }
    printf("\n\n------------RESULTADOS-----------");
    printf("\nEdad promedio: %d", sumaEdad/cantAlumnos);
    printf("\nAltura promedio: %.2f", sumaAltura/cantAlumnos);
    printf("\nCantidad de alumnos mayores de 10 anios: %d", cantM10);
    printf("\nCantidad de alumnos que miden menos de 1.4: %d\n", cantm140);

    return 0;
}
