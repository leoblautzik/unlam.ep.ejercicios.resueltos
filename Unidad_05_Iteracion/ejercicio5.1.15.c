#include <stdio.h>
int main()
{
int cont1,cont2,cont3,cont4,cont0,i,j,x,y;
cont1=0;
cont2=0;
cont3=0;
cont4=0;
cont0=0;

for(i=1;i<=5;i++)
{
    for(j=1;j<=3;j++)
    {
    printf("Ingresar coordenada x y: ");
    scanf("%d%d",&x,&y);

    if(x>0 && y>0)
        {
        cont1++;
        }
    else
        {
        if(x<0 && y>0)
            {
            cont2++;
            }
        else
            {
            if(x<0 && y<0)
                {
                cont3++;
                }
            else
                {
                if(x>0 && y<0)
                    {
                    cont4++;
                    }
                else
                    {
                    cont0++;
                    }
                }
            }
        }
    }
printf("El participante %d efectuo en cada cuadrante: \nPrimer cuadrante: %d",i,cont1);
printf("\nSegundo cuadrante: %d",cont2);
printf("\nTercer cuadrante: %d",cont3);
printf("\nCuarto cuadrante: %d",cont4);

}
printf("\nCantidad tiros al centro: %d",cont0);

}