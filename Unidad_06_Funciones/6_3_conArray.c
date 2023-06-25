#include <stdio.h>
#include <stdlib.h>   

int leerParticipante();
int CUADRANTE (float,float);
int PUNTAJE (int[]);

int main()
{
    int participante,centro, error;
    float x,y;
    int ganador, puntajeParticipante, maxPuntaje = 0;
    int flagMax = 0;
    
    participante = leerParticipante();
    
    while(participante >= 0)
    {
        printf("Ingrese los disparos del participante Nro: %d\n", participante);
        int cuadrantes[] = {0,0,0,0,0}; 
        for(int i=0; i<3; i++)
        {
            error = 0;
            do // leo los tiros.
            {
                if(error)
                    printf("No se admiten tiros en los ejes\n ");
                
                printf("Ingrese disparo %d (X e Y): ", i+1);
                scanf("%f%f" ,&x,&y);
                error=1;

            }while(x*y==0 && x!=y);
        
            cuadrantes[CUADRANTE(x,y)]++;
        }// cierro el for de tiros por participante. 
        
        centro += cuadrantes[0];
        puntajeParticipante = PUNTAJE(cuadrantes);

        if(flagMax == 0 || puntajeParticipante > maxPuntaje)
        {
            maxPuntaje = puntajeParticipante;
            ganador = participante;
            flagMax = 1;
        }

        printf("Puntaje: %d\n", puntajeParticipante);
        printf("Centro: %d\t Cuad_1: %d\t Cuad_2: %d\t Cuad_3: %d\t Cuad_4: %d\n\n", 
                cuadrantes[0],cuadrantes[1],cuadrantes[2],cuadrantes[3],cuadrantes[4]);
        
        participante = leerParticipante();
    } // fin while

    if(flagMax != 0)
    {
        printf("Tiros totales al centro %d\n", centro); 
        printf("Gana el participante Nro: %d con un puntaje de: %d\n", ganador, maxPuntaje);
    }
    else
        printf("Sin procesamiento\n");
    return 0;
}

int leerParticipante ()
{
    int part;
    printf("\nIngrese Nro de participante: ");
    scanf("%d" ,&part);
    return part;
}


int CUADRANTE (float x, float y)
{
    int cuadrante;

    if(x==0 && y == 0)
        cuadrante = 0;
    else if(x>0 && y>0)
        cuadrante = 1;
    else if(x<0 && y>0)
        cuadrante = 2;
    else if(x<0 && y<0)
        cuadrante = 3;
    else cuadrante = 4;

    return cuadrante;
}

int PUNTAJE (int cuadrantes[])
{
    return (cuadrantes[1] + cuadrantes[2]) * 50 + 
        (cuadrantes[4] + cuadrantes[3]) * 40 + 
        cuadrantes[0] * 100;
}



