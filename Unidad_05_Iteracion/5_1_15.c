#include <stdio.h>

int main()
{
    float x,y;
    int c1,c2,c3,c4,centro=0,invalidos=0;

    for(int j=1; j<=2; j++)
    {
        c1=0;
        c2=0;
        c3=0;
        c4=0;

        printf("Ingrese los disparos del jugador N° %d: \n",j);   
        for(int i=1; i<=3; i++)
        {  
            printf("Ingrese la coordenada x del %d° disparo ",i);
            scanf("%f", &x);
            printf("Ingrese la coordenada y del %d° disparo ",i);
            scanf("%f", &y);
            if(x==0 && y==0)
                centro++;
            else
                if((x==0 && y!=0) || (x!=0 && y==0))
                    invalidos++;
                else
                {
                    if(x>0)
                        if(y>0)
                            c1++;
                        else
                            c4++;
                    else
                        if(y>0)
                            c2++;
                        else
                            c3++;
                }
        }
        printf("El jugador N°%d realizó los siguientes disparos:\n",j);   
        printf("En el 1° cuadrante %d\n",c1);
        printf("En el 2° cuadrante %d\n",c2);
        printf("En el 3° cuadrante %d\n",c3);
        printf("En el 4° cuadrante %d\n",c4);
    }

    printf("Disparos en el centro: %d\n", centro);
    printf("Disparos invalidos: %d\n", invalidos);
    return 0;

}
