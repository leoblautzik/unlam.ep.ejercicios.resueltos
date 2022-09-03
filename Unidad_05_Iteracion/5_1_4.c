//Se ingresan 100 letras. Determinar la cantidad de vocales ingresadas.


#include <stdio.h>

int main()
{
    char letra;
    for(int i=0; i<5; i++){
        printf("Ingrese una letra");
        scanf("%c", &letra);
        getchar();
        printf("letra: %c",letra);
    }   

return 0;
}
