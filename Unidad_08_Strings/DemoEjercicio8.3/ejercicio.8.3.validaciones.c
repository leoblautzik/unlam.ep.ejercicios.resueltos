/*Ingresar nombre y DNI de los alumnos de un curso. Como máximo el curso puede tener 50 alumnos. La
<<<<<<< HEAD
carga finaliza con un alumno de nombre FIN. Luego de cargar los alumnos se pide:
a. Ingresar nombres de a uno en uno y buscarlos. Si el nombre está en el curso mostrar su DNI y sino
informar que no está. Seguir ingresando nombres hasta que se ingrese un nombre igual a
NOBUSCARMAS.
b. Mostrar el listado de alumnos ordenado alfabéticamente de menor a mayor.*/
=======
  carga finaliza con un alumno de nombre FIN. Luego de cargar los alumnos se pide:
  a. Ingresar nombres de a uno en uno y buscarlos. Si el nombre está en el curso mostrar su DNI y sino
  informar que no está. Seguir ingresando nombres hasta que se ingrese un nombre igual a
  NOBUSCARMAS.
  b. Mostrar el listado de alumnos ordenado alfabéticamente de menor a mayor.*/
>>>>>>> 855ad7f (Consultas 2022)


#include <stdio.h>
#include <string.h>
#include <ctype.h>

int strcmpi(char* s1, char* s2){
    int i;
<<<<<<< HEAD
     
    if(strlen(s1)!=strlen(s2))
        return -1;
         
=======

    if(strlen(s1)!=strlen(s2))
        return -1;

>>>>>>> 855ad7f (Consultas 2022)
    for(i=0;i<strlen(s1);i++){
        if(toupper(s1[i])!=toupper(s2[i]))
            return s1[i]-s2[i];
    }
    return 0;
}

void leerTexto (char[], int);
void leerYvalidarNombre(char [], int, char[]);
int leerYvalidarDNI();
int cargarAlumnos(char[][21], int[], int);
int buscarNombre(char[][21], char[], int);
void buscarAlumnos(char[][21], int[], int);
void ordenarAlumnos(char[][21], int[],int);
void mostrarAlumnos(char[][21],int[], int );

<<<<<<< HEAD
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
=======
int main()
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
>>>>>>> 855ad7f (Consultas 2022)
}
//---------------------------------------------------------------------
int cargarAlumnos(char nombres[][21],int DNIs[],int tamMax)
{
<<<<<<< HEAD
	int cantAlumnos=0;
	char nombre[21]="";
	char mensaje[]="Ingrese el nombre: ";
	
	leerYvalidarNombre(nombre,21,mensaje);
	while(strcmpi(nombre,"FIN")!=0 && cantAlumnos<tamMax)
	{		
		DNIs[cantAlumnos]=leerYvalidarDNI();
		strcpy(nombres[cantAlumnos],nombre);
		cantAlumnos++;
		leerYvalidarNombre(nombre,21,mensaje);
	}
	return cantAlumnos;	
=======
    int cantAlumnos=0;
    char nombre[21]="";
    char mensaje[]="Ingrese el nombre: ";

    leerYvalidarNombre(nombre,21,mensaje);
    while(strcmpi(nombre,"FIN")!=0 && cantAlumnos<tamMax)
    {		
        DNIs[cantAlumnos]=leerYvalidarDNI();
        strcpy(nombres[cantAlumnos],nombre);
        cantAlumnos++;
        leerYvalidarNombre(nombre,21,mensaje);
    }
    return cantAlumnos;	
>>>>>>> 855ad7f (Consultas 2022)
}
//---------------------------------------------------------------------
void mostrarAlumnos(char nombres[][21],int DNIs[],int cantAlumnos)
{
<<<<<<< HEAD
	printf("Nombre  DNI\n");
	for(int i=0;i<cantAlumnos;i++)
	{
		printf("%s\t%d\n", nombres[i], DNIs[i]);
	}
=======
    printf("Nombre  DNI\n");
    for(int i=0;i<cantAlumnos;i++)
    {
        printf("%s\t%d\n", nombres[i], DNIs[i]);
    }
>>>>>>> 855ad7f (Consultas 2022)
}
//---------------------------------------------------------------------
int buscarNombre(char nombres[][21], char nombreAbuscar[21], int cantAlumnos)
{
<<<<<<< HEAD
	int pos=-1, i=0;
	while(pos==-1 && i<cantAlumnos)
	{	if(strcmp(nombreAbuscar,nombres[i])==0)
			pos=i;
		else
			i++;	
	}
	return pos;	
=======
    int pos=-1, i=0;
    while(pos==-1 && i<cantAlumnos)
    {	
        if(strcmp(nombreAbuscar,nombres[i])==0)
            pos=i;
        else
            i++;	
    }
    return pos;	
>>>>>>> 855ad7f (Consultas 2022)
}
//---------------------------------------------------------------------
void buscarAlumnos(char nombres[][21], int DNIs[], int cantAlumnos)
{
<<<<<<< HEAD
	int posDNI=-1;
	char nombre[21]="";
	char mensaje[]="Ingrese el nombre a buscar: ";
	leerYvalidarNombre(nombre,21,mensaje);
	while(strcmpi(nombre,"NOBUSCARMAS")!=0)
	{	
		posDNI=buscarNombre(nombres,nombre,cantAlumnos);
		
		if(posDNI>-1)
			printf("DNI:%d\n", DNIs[posDNI]);
		else
			printf("Nombre no encontrado\n");

		leerYvalidarNombre(nombre,21,mensaje);
	}	
=======
    int posDNI=-1;
    char nombre[21]="";
    char mensaje[]="Ingrese el nombre a buscar: ";
    leerYvalidarNombre(nombre,21,mensaje);
    while(strcmpi(nombre,"NOBUSCARMAS")!=0)
    {	
        posDNI=buscarNombre(nombres,nombre,cantAlumnos);

        if(posDNI>-1)
            printf("DNI:%d\n", DNIs[posDNI]);
        else
            printf("Nombre no encontrado\n");

        leerYvalidarNombre(nombre,21,mensaje);
    }	
>>>>>>> 855ad7f (Consultas 2022)
}
//---------------------------------------------------------------------
void ordenarAlumnos(char nombres[][21], int DNIs[], int cant)
{
<<<<<<< HEAD
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
=======
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
>>>>>>> 855ad7f (Consultas 2022)
}
//---------------------------------------------------------------------
void leerTexto (char texto[], int largo)
{
<<<<<<< HEAD
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
=======
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
>>>>>>> 855ad7f (Consultas 2022)
}
//---------------------------------------------------------------------
void leerYvalidarNombre(char texto[], int largo,char mensaje[])
{
<<<<<<< HEAD
	do
	{
		printf("%s",mensaje);
		leerTexto(texto,largo);
	}while(strcmp(texto,"")==0);
=======
    do
    {
        printf("%s",mensaje);
        leerTexto(texto,largo);
    }while(strcmp(texto,"")==0);
>>>>>>> 855ad7f (Consultas 2022)
}

int leerYvalidarDNI()
{
<<<<<<< HEAD
	int dni=0;
	do
	{
		printf("Ingrese el DNI: ");
		scanf("%d",&dni);
		getchar();
	}while(dni<5000000||dni>100000000);

	return dni;
	
}
=======
    int dni=0;
    do
    {
        printf("Ingrese el DNI: ");
        scanf("%d",&dni);
        getchar();
    }while(dni<5000000||dni>100000000);

    return dni;

}
>>>>>>> 855ad7f (Consultas 2022)
