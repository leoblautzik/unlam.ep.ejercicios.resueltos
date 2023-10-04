#include <stdio.h>
#include <stdlib.h>

int Validaringreso(int,int,int);
int Resto(int,int);
int Espar(int);
int Esprimo(int);
float Promedio(int,int);

int main ()
{
 int Num,Contpar=0,Contprimos=0,Acumimpar=0,Contimpar;
  float Prom;


 Num=Validaringreso(1,50);
 
 while (Num!=-10);
 {
   Contprimos+=Esprimo(Num);
    if(Espar(Num)==1)
    Contpar++;
    else
    {
     Acumimpar+=Num;
     Contimpar++;
        }

      Num=Validaringreso(1,50,-10);

 }
 Prom=Promedio(Acumimpar,Contimpar);
 printf ("\n Cantidad de numeros primos %d ",Contprimos);
 printf ("\n Cantidad de numeros pares %d ",Contpar);
 printf ("\n Promedio de los numeros  impares %f ",Prom);



return 0;
}

int ingresarYvalidar(int a,int b,int c)
{
  int Num1;
do {
    printf ("Ingresa un numero ;");
    scanf ("%d",&Num1);
}while ((Num1<a||Num1>b)&&Num1!=c);
return Num1;
};

int Resto (int a,int b)
{
int opera=0;
opera=a%b;
if (opera==0) return 1;
else return 0;
};

int Espar(int a)
{
  int r;
  r=a%2;
  if (r==0)
    return 1;
  else return 0;
};


int Esprimo(int a)
{
  int x,r=0;
   for (x=1;x<a;x++)
   r+=Resto(a,x);
  if (r==2)
    return 1;
  else return 0;
};


float Promedio(int a,int b)
{
float P;
P =(float)a/b;
return P ;
};