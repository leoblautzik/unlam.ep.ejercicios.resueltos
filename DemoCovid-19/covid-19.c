
// Se desea desarrollar una aplicación para controlar a las personas que
// requieren ingresar a la UNLaM en el marco de la emergencia sanitaria por COVID-19.
// En la entrada de la UNLaM hay un enfermero que por cada persona que solicita ingresar, 
// le efectúa una toma de temperatura, y adicionalmente le pregunta, a modo de declaración jurada, 
// si tuvo dolor de garganta, si tuvo tos y la edad.
// El enfermero ingresa a la aplicación el valor de la temperatura y las respuestas a las tres preguntas. 
// La temperatura la ingresa en formato numérico decimal, la edad en formato numérico entero, y para la respuesta
// a las dos preguntas ingresa "S" si fue SI o "N" si fue NO.
// La aplicación emitirá un cartel que dirá "SI Puede ingresar” solamente en el caso que
// las respuestas a las preguntas relacionadas a la tos y el dolor de garganta sean "N" y la
// temperatura sea inferior a 37,5. Caso contrario emitirá un cartel que dirá "NO puede ingresar”.
// Se finaliza el proceso informando cuantas personas pudieron ingresar, cuantas no pudieron ingresar, 
// y la edad de la persona más joven que no pudo ingresar.
// Se controlan personas hasta que el enfermero lo determine.

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}

int main()
{
	int contadorIngresa=0;
	int contadorNoIngresa=0;
	float temperatura;
	int edad, edadMasJoven;
	int bandera=0;
	char opcion, tos ,dolorDeGarganta;

	printf("Universidad Nacional de La Matanza COVID-19\n");

	do
	{
		printf("Desea ingresar a UNLaM? S/N : ");
		scanf("%c",&opcion);
		clean_stdin();
	}while(opcion!='S' && opcion!='N');
	
	while(opcion =='S')
	{
		do{
		printf("\nIngrese la temperatura: ");
		scanf("%f",&temperatura);
		}while(temperatura<=27 || temperatura>=45);

		do{
		printf("\nIngrese la edad:");
		scanf("%d",&edad);
		}while(edad<0 || edad>120); // !(edad>0 && edad<120)
 
		do
		{
			printf("\nTuvo tos? ");
			clean_stdin();
			scanf("%c", &tos);			
		}while((tos!='S' && tos!='N') && (tos!='s' && tos!='n'));
        // n        V     V     V      F      V     F     F
		do
		{
			printf("\nTuvo dolor de garganta? ");
			clean_stdin();
			scanf("%c",&dolorDeGarganta);
			
			dolorDeGarganta=toupper(dolorDeGarganta); 	

		}while(dolorDeGarganta!='S' && dolorDeGarganta!='N');

		if(temperatura<37.5 && tos=='N' && dolorDeGarganta == 'N')
		{
			printf("\nPuede Ingresar");
			contadorIngresa++;
		}else//no podrá ingresar
			{
				if(bandera==0 || edad<edadMasJoven) 
				{
					edadMasJoven=edad;
					bandera=1;
				}
				
				printf("\nNO Puede Ingresar");
				contadorNoIngresa++;
			}
		do
		{
			printf("\nSeguir procesando? S/N ");
			clean_stdin();
			scanf("%c",&opcion);
		}while(opcion!='S' && opcion!='N');
		//limpiamos la pantalla
		system("clear");

	}

	if(bandera!=0 || contadorIngresa!=0)
	{
		printf("\nPudieron ingresar: %d", contadorIngresa );
		printf("\nNo Pudieron Ingresar: %d", contadorNoIngresa );
		if(bandera!=0) {
			printf("\nLa edad de la persona mas joven que no pudo ingresar: %d", edadMasJoven );
		}
	}
	else
	{
		printf("\nSin Procesar");
	}

	return 0;
}