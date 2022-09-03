#include<stdio.h>


int leerYvalidar(int , int );
int estaDentroDelRango(int, int, int);

int main(){
    int numero,contadorA=0,contadorB=0,contadorC=0,sumadorC=0;

    numero=leerYvalidar(99,2000);
    while(numero!=99){
        if(estaDentroDelRango(numero,100,500)==1){
            contadorA++;
        }
        if(estaDentroDelRango(numero,500,1200)==1 && numero%2==0){
            contadorB++;
        }
        if(estaDentroDelRango(numero,1200,2000)==1){
            contadorC++;
            sumadorC+=numero;
        };
        numero=leerYvalidar(99,2000);
    }
    printf("Cantidad entre 100 y 500 %d\n",contadorA);
    printf("Cantidad de pares entre 500 y 1200 %d\n",contadorB);
    if(contadorC>0)
        printf("Promedio blalala %.2f",(float)sumadorC/contadorC);


    return 0;    
}

int leerYvalidar(int linf, int lsup){
    int numeroValido;

    do{
        printf("Ingrese un numero entre 100 y 2000 - 99 para salir ");
        scanf("%d", &numeroValido);
    }while(estaDentroDelRango(numeroValido,99,2000)==0);

    return numeroValido;
}

int estaDentroDelRango(int numero, int linf, int lsup){
    int v=0; 
    if(numero>=linf && numero<=lsup)
        v=1;
    return v;
} 
