#include <stdio.h>
#include <string.h>
#include <ctype.h>
void LeerTexto (char texto[], int largo)
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

int ingresarDatoValido(int, int, char[] );


int main()
{
    float nota1, nota2;
    char condicion [2];
    char condicionChar;
    char mensaje [16];
    strcpy(mensaje,"Ingrese nota1: ");
    //printf("Ingrese la nota del 1° parcial: ");
    nota1 = ingresarDatoValido(1,10,mensaje);
    fflush(stdin);
    /*printf("Ingrese la condición:[char] ");
      scanf("%c",&condicionChar);
      condicionChar = tolower(condicionChar);
      printf("%c", condicionChar);


    //printf("Ingrese la condición: ");
    //LeerTexto(condicion, 2);
    */
    strcpy(mensaje,"Ingrese nota2: ");
    nota2 = ingresarDatoValido(1,10,mensaje);

    printf("\nLa nota promedio es: %4.2f \n", (nota1 + nota2)/2);
    return 0;
}

int ingresarDatoValido(int inferior, int superiror, char mensaje [])
{
    int nota;
    do
    {
        printf("%s",mensaje);
        scanf("%d", &nota);

    } while(nota < inferior || nota > superiror);

    return nota;
}
