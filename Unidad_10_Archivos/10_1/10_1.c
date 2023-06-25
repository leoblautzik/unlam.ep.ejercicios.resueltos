#include <stdio.h> 
#include <stdlib.h> 
#include <locale.h> 
#include <string.h>

void lectura();
void generarArchivo();

typedef struct {
    int dni;
    char apenom[81];
    int nota1;
    int nota2;
}Alumno;

int main(){
    generarArchivo();
}

void generarArchivo(){
    
    Alumno aux;
    FILE *pf;
    pf = fopen("ALUMNOS.dat", "wb");
    if(pf == NULL) {
        printf("No se pudo abrir el archivo");
    }
    printf("Ingrese DNI: ");
    scanf("%d", &aux.dni);
    while(aux.dni > 0){
        
        printf("Ingrese Apellido y Nombre: ");
        getchar();
        fgets(aux.apenom, 81, stdin);
        
        printf("Ingrese Nota 1: ");
        scanf("%d", &aux.nota1);
         
        printf("Ingrese Nota 2: ");
        scanf("%d", &aux.nota2);
        
        fwrite(&aux, sizeof(aux), 1, pf);

        printf("Ingrese DNI: ");
        scanf("%d", &aux.dni);
    }
    fclose(pf);

}
