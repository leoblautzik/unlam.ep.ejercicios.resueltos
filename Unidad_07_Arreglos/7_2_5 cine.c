#include <stdio.h>
#include <stdlib.h>

void inicializar(char [][9],int,int);
void mostrar(char[][9],int,int );
void reserva(char[][9]);
int ContarLetras(char[][9], char, int, int );
void MostrarFilasVacias(char[][9], int, int );
void ContarReservasXFila(char[][9],int[], int, int );
void ContarReservasXColumnas(char[][9],int[], int, int );
int ValorMaximo(int [], int);
void MostrarValor(int[], int, int);
void Ordenar (int[], int[], int);
void MostrarOcupacionButacas(int[], int[], int);

int main()
{
    int reservasXfila[12], reservasXColumna[9], maximo; 
    int numerosButaca[] = {8,6,4,2,1,3,5,7,9};


    char M[12][9];
    inicializar(M,12,9);
    reserva(M);

    //punto a
    printf("\nSe reservaron %d butacas", ContarLetras(M,'R',12,9));
    printf("\nQuedaron vacias %d butacas", ContarLetras(M,'D',12,9));

    //punto b
    MostrarFilasVacias(M,12,9);

    //punto C
    ContarReservasXFila(M,reservasXfila,12,9);
    maximo = ValorMaximo(reservasXfila,12);
    printf("\nLa mayor cantidad de reserva por filas fue de %d y se repite en las filas: ",maximo);
    MostrarValor(reservasXfila, maximo,12);

    //punto d
    ContarReservasXColumnas(M,reservasXColumna,12,9);
    Ordenar(reservasXColumna, numerosButaca, 9);
    MostrarOcupacionButacas(reservasXColumna, numerosButaca, 9);

    printf("\n\n");
    system("pause");
    return 0;
}

void MostrarOcupacionButacas(int vr[], int vn[], int ce)
{
    int i;
    printf("\n\nButaca Cantidad");
    for (i=0;i<ce;i++)
        printf("\n%6d %8d",vn[i],vr[i]);
}

void Ordenar (int vo[], int vi[], int ce)
{
    int i,j, aux;
    for (i=0;i<ce-1;i++)
        for (j=0;j<ce-1-i;j++)
            if (vo[j] < vo[j+1])
            {
                aux = vo[j];
                vo[j] = vo[j+1];
                vo[j+1] = aux;

                aux = vi[j];
                vi[j] = vi[j+1];
                vi[j+1] = aux;
            }
}

void ContarReservasXColumnas(char M[][9], int v[], int cf, int cc)
{
    int f,c, cont=0;
    for(c=0;c<cc;c++)
    {
        v[c]=0;
        for (f=0;f<cf;f++)
            if(M[f][c]=='R')
                v[c]++;
    }

}
int ValorMaximo(int v[], int ce)
{
    int max, i;
    max = v[0];
    for (i=1;i<ce;i++)
        if (v[i]>max)
            max = v[i];
    return max;
}

void MostrarValor(int v[], int valor, int ce)
{
    int i;
    for (i=0;i<ce;i++)
        if(v[i]==valor)
            printf("\n%d", i+1);
}

void ContarReservasXFila(char M[][9], int v[], int cf, int cc)
{
    int f,c, cont=0;
    for(f=0;f<cf;f++)
    {
        v[f]=0;
        for (c=0;c<cc;c++)
            if(M[f][c]=='R')
                v[f]++;
    }

}

void MostrarFilasVacias(char M[][9], int cf, int cc)
{
    int f,c;
    for(f=0;f<cf;f++)
    {
        c=0;
        while(c<cc && M[f][c]!='R')
            c++;

        if (c==cc)
            printf("\nLa fila %d esta vacia", f+1);
    }
}

int ContarLetras(char M[][9], char letra, int cf, int cc)
{
    int f,c, cont=0;
    for(f=0;f<cf;f++)
        for (c=0;c<cc;c++)
            if (M[f][c]==letra)
                cont++;
    return cont;
}

void inicializar(char M[][9],int cf,int cc)
{
    int i,j;
    for(i=0;i<cf;i++)
        for(j=0;j<cc;j++)
           M[i][j]='D';
}

void mostrar(char M[][9],int cf,int cc )
{
    int i,j;
    system("cls"); //system("clear"); //en linux
    printf("Sistema de Reservas - Cine UNLaM\n");
    printf ("              Butaca\n");
    printf ("         8 6 4 2 1 3 5 7 9");
    for(i=0;i<cf;i++)
    {
    	printf ("\nFila %2d ",i+1);
	 	for(j=0;j<cc;j++)
          printf("%2c",M[i][j]);
    }
}

void reserva(char M[][9])
{
    int f,c;

    mostrar(M,12,9);
    do
    {
        printf ("\nIngrese la fila a reservar (finaliza con fila negativa) :");
        scanf("%d",&f);
    }while(f>12 || f==0);

    while(f>0)
    {

        do
        {
            printf("Ingrese butaca que desea: ");
            scanf("%d",&c);
        }while(c<1|| c>9 );

        switch(c)
        {
            case 8: c=0;
            break;

            case 6: c=1;
            break;

            case 4: c=2;
            break;

            case 2: c=3 ;
            break;

            case 1: c=4;
            break;

            case 3 : c=5;
            break;

            case 5 : c=6 ;
            break;

            case 7 : c=7;
            break;

            case 9 : c=8;
            break;
        }

         f = f-1;
         if (M [f] [c]== 'R')
         {
            printf (" *********EL LUGAR ESTA OCUPADO - Seleccione otro **********");
            getchar();
         }
         else
         {
            M[f][c]='R';
         }

        mostrar ( M,12,9);
        do
        {
            printf ("\nIngrese la fila a reservar (finaliza con fila negativa) :");
            scanf("%d",&f);
        }while(f>12 || f==0);
    }
}
