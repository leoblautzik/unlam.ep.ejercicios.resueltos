/*
Se ingresan DNI y nota de un parcial de los alumnos de un curso.
El ingreso de datos finaliza con un DNI negativo.
Se sabe que como máximo pueden presentarse a rendir 60 alumnos.

Mostrar:
 a.  Listado de alumnos con su correspondiente DNI y la nota obtenida
    (en forma de listado).
 b.  La máxima nota obtenida y el DNI de los alumnos que la obtuvieron.
*/
#include <stdio.h>
int Buscar(int[],int, int);
int IngresarDatos(int [], int[], int);
void Listado(int [], int[], int);
int NotaMaxima(int[], int);
void MostrarDNINotaMaxima(int[],int[],int, int);

int main()
{
    int DNIs[60], notas[60], cant, max;

    cant = IngresarDatos(DNIs, notas, 60);
    
    if (cant>0)
    {
        Listado(DNIs,notas,cant);
        max = NotaMaxima(notas, cant);
        printf ("\n\nLa nota maxima fue de %d y corresponde a los alumnos con DNI:",max);;
        MostrarDNINotaMaxima(DNIs,notas,max,cant);
    }
    else
        printf("No se ingresaron datos.");

    return 0;
}

int Buscar(int v[],int buscado, int ce)
{
    int pos=-1,i=0;
    while(pos==-1 && i<ce)
        if(v[i]==buscado)
            pos =i;
        else
            i++;
    return pos;
}

int IngresarDatos(int vDNIs[], int vNotas[], int ce)
{
    int i=0,pos;
    do
    {
        printf("Ingrese DNI (negativo fin):");
        scanf("%d",&vDNIs[i]);
    }while(vDNIs[i]==0);

    while (i<ce && vDNIs[i] >0)
    {
        do
        {
            printf("Ingrese la nota del alumno:");
            scanf("%d", &vNotas[i]);
            if (vNotas[i]<0||vNotas[i]>10)
                printf("Nota incorrecta\n");
        }while(vNotas[i]<0||vNotas[i]>10);

        i++; //me muevo a la siguiente posición libre del vector

        if (i<ce) //si hay espacio en el vector
        {
            do //ingreso otro dni
            {
                printf("\nIngrese DNI (negativo fin):");
                scanf("%d",&vDNIs[i]);
                pos = Buscar(vDNIs,vDNIs[i],i);
                if (pos!=-1)
                    printf("\nDNI duplicado.");
            }while(vDNIs[i]==0 || pos!=-1);
        }
    }
    return i;
}

void Listado(int vDNIs[], int vNotas[], int ce)
{
    int i;
    printf("\n     DNI    NOTA");
    for (i=0;i<ce;i++)
        printf("\n%8d%5d",vDNIs[i],vNotas[i]);
}

int NotaMaxima(int vNotas[], int ce)
{
    int i,max;
    max= vNotas[0];
    for (i=1;i<ce;i++)
        if (vNotas[i]>max)
            max = vNotas[i];

    return max;
}

void MostrarDNINotaMaxima(int vDNIs[] ,int vNotas[],int notaMax, int ce)
{
    int i;
    for (i=0;i<ce;i++)
    {
        if (vNotas[i]==notaMax)
            printf("\n%d", vDNIs[i]);
    }
}

