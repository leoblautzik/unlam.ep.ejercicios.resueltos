	#include <stdio.h>

int diasDelMes(int ,int );
int fechaValida(int, int, int);
int anioBisiesto(int);

int main ()
{
	int dia, mes , anio;

	do{
		
		do{
			printf("\ningresar el dia \n");
			scanf("%2d" ,&dia);
		}while(dia<1 || dia>31);

		do{
			printf("\ningresar el mes \n");
			scanf("%2d" ,&mes);
		}while(mes<1 || mes>12);

		do{
			printf("\ningresar el anio \n");
			scanf("%4d" ,&anio);
		}while(anio<1580 || anio>2030);
				
		
	}while(!fechaValida(dia,mes,anio));


	printf("mostar fecha: %2d/%2d/%4d",dia,mes,anio);
	
	return 0;
};	

int diasDelMes(int mes ,int anio)
{
	int dias=-1; 
	if(mes==4 || mes == 6 || mes == 9 || mes == 11)
		dias=30;
	else
		{
			if(mes==2)
				return 28+anioBisiesto(anio);
			else	
				dias =31; 
	}

	return dias;
}

int fechaValida(int dia, int mes, int anio)
{
		return 1;
}

int anioBisiesto(int anio)
{
	if((anio/4 == 0 && anio/100 != 0) || anio/400 == 0)
		return 1;
	return 0;
}



