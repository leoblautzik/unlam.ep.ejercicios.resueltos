/*Ingresar nombre y DNI de los alumnos de un curso. Como máximo el curso puede tener 50 alumnos. La
carga finaliza con un alumno de nombre FIN. Luego de cargar los alumnos se pide:
a. Ingresar nombres de a uno en uno y buscarlos. Si el nombre está en el curso mostrar su DNI y sino
informar que no está. Seguir ingresando nombres hasta que se ingrese un nombre igual a
NOBUSCARMAS.
b. Mostrar el listado de alumnos ordenado alfabéticamente de menor a mayor.*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>

int strcmpi(char* s1, char* s2){
    int i;
     
    if(strlen(s1)!=strlen(s2))
        return -1;
         
    for(i=0;i<strlen(s1);i++){
        if(toupper(s1[i])!=toupper(s2[i]))
            return s1[i]-s2[i];
    }
    return 0;}

void leerTexto (char[], int);
int cargarAlumnos(char[][21], int[], int);
int buscarNombre(char[][21], char[], int);
void buscarAlumnos(char[][21], int[], int);
void ordenarAlumnos(char[][21], int[],int);
void mostrarAlumnos(char[][21],int[], int );

void main()
{
	int DNIs[50],cantAlumnos;
	char nombres[50][21];
	cantAlumnos = cargarAlumnos(nombres,DNIs,50);
	if(cantAlumnos>0)
	{
		buscarAlumnos(nombres,DNIs,cantAlumnos);
		ordenarAlumnos(nombres,DNIs,cantAlumnos);
		mostrarAlumnos(nombres,DNIs,cantAlumnos);
	}
	printf("\nBye!!");	
}
//---------------------------------------------------------------------
int cargarAlumnos(char nombres[][21],int DNIs[],int tamMax)
{
	int cantAlumnos=0;
	char nombre[21]="";
	int dni=0;
	printf("Ingrese el nombre: ");
	leerTexto(nombre,21);
	while(strcmpi(nombre,"FIN")!=0 && cantAlumnos<tamMax)
	{		
		printf("Ingrese el DNI: ");
		scanf("%d",&dni);
		getchar();
		strcpy(nombres[cantAlumnos],nombre);
		DNIs[cantAlumnos]=dni;
		cantAlumnos++;
		printf("Ingrese el nombre: ");
		leerTexto(nombre,21);
	}
	return cantAlumnos;	
}
//---------------------------------------------------------------------
void mostrarAlumnos(char nombres[][21],int DNIs[],int cantAlumnos)
{
	printf("Nombre  DNI\n");
	for(int i=0;i<cantAlumnos;i++)
	{
		printf("%s\t%d\n", nombres[i], DNIs[i]);
	}
}
//---------------------------------------------------------------------
int buscarNombre(char nombres[][21], char nombreAbuscar[21], int cantAlumnos)
{
	int pos=-1, i=0;
	while(pos==-1 && i<cantAlumnos)
	{	if(strcmp(nombreAbuscar,nombres[i])==0)
			pos=i;
		else
			i++;	
	}
	return pos;	
}
//---------------------------------------------------------------------
void buscarAlumnos(char nombres[][21], int DNIs[], int cantAlumnos)
{
	int posDNI=-1;
	char nombre[21]="";
	printf("Ingrese el nombre a buscar: ");
	leerTexto(nombre,21);
	while(strcmpi(nombre,"NOBUSCARMAS")!=0)
	{	
		posDNI=buscarNombre(nombres,nombre,cantAlumnos);
		
		if(posDNI>-1)
			printf("DNI:%d\n", DNIs[posDNI]);
		else
			printf("Nombre no encontrado\n");

		printf("Ingrese el nombre a buscar: ");
		leerTexto(nombre,21);
	}	
}
//---------------------------------------------------------------------
void ordenarAlumnos(char nombres[][21], int DNIs[], int cant)
{
	int i,j;
	char str_aux[21];
	int dni_aux;
	for (i=0;i<cant-1;i++)
	{
		for (j=0;j<cant-1-i;j++)
		{
			if (strcmp(nombres[j],nombres[j+1]) > 0)
			{
				strcpy(str_aux, nombres[j]);
				strcpy (nombres[j],nombres[j+1]);
				strcpy (nombres[j+1], str_aux);

				dni_aux=DNIs[j];
				DNIs[j]=DNIs[j+1];
				DNIs[j+1]=dni_aux;
			}
		}
}
}
//---------------------------------------------------------------------
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
//---------------------------------------------------------------------
