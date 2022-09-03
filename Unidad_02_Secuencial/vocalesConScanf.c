#include<stdio.h>

char leerChar()
{
    char letra;    
    scanf("%c", &letra);
    getchar();
    return letra;
}

int main()
{
    char vocal;
    for(char i = 'a'; i <= 'd'; i++)
    {
        printf("Ingrese la %c: ", i);
        vocal = leerChar();
        printf("La vocal ingresada fue la:  %c\n", vocal);
    }
}
