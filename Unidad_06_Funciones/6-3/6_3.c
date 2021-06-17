#include <stdio.h>
#include <stdlib.h>   

int leerParticipante();
int CUADRANTE (float,float);
int PUNTAJE (int,int,int,int,int);

int main()
{
    int participante, cuad, cuad0, cuad1, cuad2, cuad3, cuad4, centro=0, error;
    float x,y;
    int ganador, puntajeParticipante, maxPuntaje = 0;
    int flagMax = 0;
    
    participante = leerParticipante();
    
    while(participante >= 0)
    {
        cuad0 = cuad1 = cuad2 = cuad3 = cuad4 = 0;
        printf("Ingrese los disparos del participante Nro: %d\n", participante);
        
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
        
            cuad=CUADRANTE(x,y);
            switch (cuad)
            {
                case 0: cuad0 ++;
                        break;
                case 1: cuad1 ++;
                        break;
                case 2: cuad2 ++;
                        break;
                case 3: cuad3 ++;
                        break;
                case 4: cuad4 ++;
                        break;
            }
        }// cierro el for de tiros por participante. 
        
        centro += cuad0;
        puntajeParticipante = PUNTAJE(cuad0, cuad1, cuad2, cuad3, cuad4);

        if(flagMax == 0 || puntajeParticipante > maxPuntaje)
        {
            maxPuntaje = puntajeParticipante;
            ganador = participante;
            flagMax = 1;
        }

        printf("Puntaje: %d\n", puntajeParticipante);
        printf("Centro: %d\t Cuad_1: %d\t Cuad_2: %d\t Cuad_3: %d\t Cuad_4: %d\n\n", cuad0,cuad1,cuad2,cuad3,cuad4);
        
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
    else
        if(x>0 && y>0)
            cuadrante = 1;
        else
            if(x<0 && y>0)
                cuadrante = 2;
            else
                if(x<0 && y<0)
                    cuadrante = 3;
                else cuadrante = 4;

    return cuadrante;
}

int PUNTAJE (int cuad0, int cuad1,int cuad2,int cuad3,int cuad4)
{
    return (cuad1+cuad2)*50 + (cuad4+cuad3)*40 + cuad0*100;
}



