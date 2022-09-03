/*9.3.Se sabe que como máximo en una comisión de Elementos de Programación hay 
  80 alumnos. De cada alumno se conoce:
  •Número de DNI (entero).
  •Apellido y Nombre(80 caracteres).
  •Nota1, Nota2 (entero).
  •Nota Promedio (real, calculado según Nota1 y Nota2).

  Se solicita:
  a.Declarar un tipo de dato que contenga la información del alumno.
  b.Declarar un vector de estructuras del tipo de dato creado en el punto a.
  c.Cargar  en  un  vector  de  estructuras,  los  datos  referentes  a  los  
  alumnos  de  la  comisión,  esta información termina con DNI igual al 0.Función INGRESO.
  d.Indicar cuántos alumnos aprobaron (ambos parciales con nota >= 4 y 
  cuántos reprobaron la materia. Función RESULTADO.
  e.Informar los datos de los alumnos de (DNI–Apellido y Nombre –Nota Promedio) 
  de los alumnos. PROMOCIONADOS (ambas notas>= 7).Función INFORME_PROM
  */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_ALUMNOS 80

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

typedef struct
{
    int DNI;
    char Apenom[81];
    int notas[2];
    float Promedio;
}Alumno;

int ingreso(Alumno[], int);
void resultado(Alumno[], int);
void informePromo(Alumno[], int);
int buscar(Alumno[], int, int);
int leerDNI(Alumno[], int);
void leerApenom(char[], int);
void leerTexto (char[], int);
int leerNota();

int main()
{
    int cantidadDeAlumnos = 0;
    Alumno alumnos[80];
    cantidadDeAlumnos = ingreso(alumnos, MAX_ALUMNOS);
    
    if(cantidadDeAlumnos > 0)
    {
        resultado(alumnos, cantidadDeAlumnos);
        informePromo(alumnos, cantidadDeAlumnos);
    }
    
    return 0;
}

int ingreso(Alumno alumnos[], int tamanio)
{
    int i = 0;
    int j;
    alumnos[i].DNI = leerDNI(alumnos, i);
    while(alumnos[i].DNI !=0 && i < tamanio)
    {
        leerApenom(alumnos[i].Apenom, 81);
        for(j=0; j<2; j++)
        {
            printf("Ingrese nota %d: ",j+1);
            alumnos[i].notas[j] = leerNota();
        }
        alumnos[i].Promedio = (float)(alumnos[i].notas[0] + alumnos[i].notas[1])/2; 

        i++;
        if(i < tamanio)
            alumnos[i].DNI = leerDNI(alumnos, i);
        else
            printf("Se alcanzó el valor maximo de carga\n");
    }      

    return i; 
}
void resultado(Alumno alumnos[], int cantidadDeAlumnos)
{
    int cantidadDeAprobados = 0;
    int i;
    for(i=0; i<cantidadDeAlumnos; i++)
    {
        if( alumnos[i].notas[0] >=4 && alumnos[i].notas[1] >= 4)
            cantidadDeAprobados ++; 
    }

    printf("\nCantidad de alumnos APROBADOS: %d\n", cantidadDeAprobados);
    printf("Cantidad de alumnos REPROBADOS: %d\n", 
            cantidadDeAlumnos - cantidadDeAprobados);

}

void informePromo(Alumno alumnos[], int cantidadDeAlumnos)
{
    printf("\n%-10s\t%-42s\t%-9s\n","DNI", "Apellido y Nombres", "Promedios");
    for(int i=0; i<cantidadDeAlumnos; i++)
    {
        if(alumnos[i].notas[0] >=7 && alumnos[i].notas[1] >=7)
        {
            printf("%-10d\t%-42s\t%-4.1f\n", 
                    alumnos[i].DNI, alumnos[i].Apenom, alumnos[i].Promedio);
        }
    }
}

int leerDNI(Alumno alumnos[], int cant)
{
    int dni;
    int  pos = -1;
    do
    {
        printf ("Ingrese DNI(0 para terminar): ");

        scanf("%d", &dni);

        pos = buscar(alumnos, dni, cant);

        if (pos!=-1)
            printf("Ya se ha registrado ese Alumno\n");
    }while (((dni < 10000 || dni > 99999999) && dni!=0 ) || pos!=-1);

    return dni;

}

int buscar(Alumno alumnos[], int dni, int cant)
{
    int i = 0;
    int pos = -1;
    while(pos == -1 && i < cant)
    {
        if(alumnos[i].DNI == dni)
            pos = i;
        else 
            i++;
    }
    return pos;
}

void leerApenom(char texto[], int largo)
{
    clean_stdin();
	do
	{
		printf("Ingrese Apellido, Nombre: ");
		leerTexto(texto,largo);
	}while(strcmp(texto,"")==0);
}
                                                                 
void leerTexto (char texto[], int largo)                                        
{                                                                               
     int i;                                                                      
     fgets(texto, largo, stdin);                                                 
     i=0;                                                                        
     while (texto[i]!='\0')                                                      
     {                                                                           
         if (texto[i]=='\n')                                                     
             texto[i]='\0';                                                      
         else                                                                                                                      
            i++;                                                                
     }                                                                           
}            

int leerNota()
{
	int nota = 0;
	int error = 0;
    do
	{   if (error)
            printf("Nota invalida, ingrese nuevamente: ");  
		scanf("%d", &nota);
        error = 1;
	}while(nota < 1 || nota > 10);
	return nota;
}
