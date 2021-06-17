	#include <stdio.h>

int diasDelMes(int ,int );


int main ()
{
	int dia, mes ;

	do{
		printf("\ningresar dia:\n");
		scanf("%2d %2d",&dia,&mes);
		//printf("\ningresar mes:\n");
		//scanf("%2d",&mes);
	}while(!(((mes==1||mes==3 || mes==5 || mes==7|| mes==8 || mes== 10 || mes==12) 
			&&  (dia>=1 && dia<=31)) || (mes==2 && dia>=1 && dia<=29) 
			|| (mes==4||mes==6 || mes==9 || mes==11) && dia>=1 && dia<=30));

	printf("mostar fecha: %2d/%2d",dia,mes);
	scanf("%2d%2d",&dia,&mes);


	return 0;
}
int diasDelMes(int mes ,int anio)
{
	int dias; 
	if(mes==1||mes==3 || mes==5 || mes==7|| mes==8 || mes== 10 || mes==12)
		dias = 31;
	if(mes==2)
		if((anio/4==0 && anio/100!=0) || anio/400==0)
			dias = 29;
    return dias;

}


