#include<stdio.h>
#include<string.h>
#include<ctype.h>

typedef struct{
    int dia;
    int mes;
    int anio;
}Fecha;


int strcmpi(char* s1, char* s2){
    int i;

    if(strlen(s1)!=strlen(s2))
        return -1;

    for(i=0;i<strlen(s1);i++){
        if(toupper(s1[i])!=toupper(s2[i]))
            return s1[i]-s2[i];
    }
    return 0;
}

void leerTexto (char texto[], int largo)
{
	int i;
	fgets(texto, largo, stdin);
	i=0;
	while (texto[i]!='\0')
	{
		if (texto[i]=='\n')
			texto[i]='\0';
		else
			i++;
	}
}

int diasMes(int mes, int anio);
int esBisiesto(int anio);
int esFechaValida(Fecha fecha);
void aniosBisiestosEntre(int ini, int fin);
void sumarUndia(Fecha );
void sumarNdias(int ,Fecha );

void sumarUndia(Fecha fecha)
{
    if(esFechaValida(fecha))
    {
        if(fecha.dia==diasMes(fecha.mes,fecha.anio))
        {
            fecha.dia=1;
            fecha.mes+=1;

            if(fecha.mes>12)
            {
                fecha.mes=1;
                fecha.anio+=1;
            }
        }
        else fecha.dia+=1;
        //printf("%d %d %d\n", dia,mes,anio);

    }else printf("fecha inválida\n");
}

void sumarNdias(int n,Fecha fecha)
{
    if(esFechaValida(fecha))
    {
        for(int i=1;i<=n;i++)
        {
            if(fecha.dia==diasMes(fecha.mes,fecha.anio))
            {
                fecha.dia=1;
                fecha.mes+=1;

                if(fecha.mes>12)
                {
                    fecha.mes=1;
                    fecha.anio+=1;
                }
            }
            else fecha.dia+=1;
        }

        //printf("%d %d %d", dia,mes,anio);
    }
    else printf("fecha inválida\n");

}

int esFechaValida(Fecha fecha)
{
    int esValida=0;
    if(fecha.anio>=1900 && fecha.anio<=2100)
    if(fecha.mes>=1 && fecha.mes<=12)
        if(fecha.dia>=1 && fecha.dia<=diasMes(fecha.mes,fecha.anio))
            esValida=1;

    return esValida;
}

int esBisiesto(int anio)
    //es bisiesto si es divisible entre cuatro y
    //(no es divisible entre 100 o es divisible entre 400).

{
    int esBi=0;
    if(anio % 4 == 0 && (anio % 100 != 0 || anio % 400 == 0))
        esBi=1;

    return esBi;
}

int diasMes(int mes, int anio)
{
    int dias=0;
    dias = 31;
    if(esBisiesto(anio) && mes==2)
        dias = 29;
    if(!esBisiesto(anio) && mes==2)
        dias = 28;
    if(mes==4 || mes==6 || mes==9 || mes==11)
        dias = 30;

    return dias;
}

void aniosBisiestosEntre(int ini, int fin)
{
    for(int i=ini;i<=fin;i++)
        if(esBisiesto(i))
            printf("%d\n",i );
}
