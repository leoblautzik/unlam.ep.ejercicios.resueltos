/*
Dadas 20 notas y legajos de alumnos de un curso. Determinar:

a.  Cantidad de alumnos aplazados.
b.  Cuando la nota sea mayor a 7, mostrar el mensaje:
“El alumno con legajo xxx ha Promocionado”.
*/
#include <stdio.h>
#define CA 20
int main()
{
    int i, cantAplazados=0, nota, legajo;
    for (i=1;i<=CA;i++)
    {
        printf("\n\nAlumno %d", i);
        printf("\n-----------");
        printf("\nIngrese el legajo:");
        scanf("%d",&legajo);
        printf("Ingrese la nota:");
        scanf("%d",&nota);
        if (nota<4)
            cantAplazados++;
        else
            if (nota>7)
                printf ("\nEl alumno con legajo %d ha Promocionado",legajo);
    }
    printf("\n\nCantidad de Aplazos: %d \n", cantAplazados);
    return 0;
}
