#include <stdio.h>

int EstaDentroDelRango(int,int,int);
int LeerYValidar(int , int);
int main(){
    int rangosu = 2000, rangoin = 99, numero, a , contadorA=0, contadorB=0, promedioC=0,contadorC=0, bandera=0;
    a = LeerYValidar(rangoin, rangosu);
    while(a!=99){
        bandera = 1;
      if (a>=100 && a<500)
        contadorA++;
      else
        if(a>500 && a<1200){
            if (a%2 == 0)
                contadorB++;}
        else
            if(a>=1200 && a<=2000){
            promedioC+=a;
            contadorC++;}
    a = LeerYValidar(rangoin, rangosu);
    }
    if(bandera){
        printf("A) %d, B) %d, C) %.2f", contadorA, contadorB, (float)(promedioC/contadorC));
    }
    else
        printf("no se ingreso nada");

    return 0;
}
int EstaDentroDelRango(int Numero, int limitein, int limitesu){

    int validar =0;

    if(Numero>=limitein && Numero<=limitesu){

        validar = 1;
    }
    return validar;
}
int LeerYValidar(int rangoin, int rangosu){

    int rango, numero;
    printf("Ingrese un numero: \n"); scanf("%d", &numero);
    rango = EstaDentroDelRango(numero, rangoin, rangosu);
    while(rango == 0){
        printf("Ingrese un numero valido: \n"); scanf("%d", &numero);
        rango = EstaDentroDelRango(numero, rangoin, rangosu);
    }

    return numero;
}

