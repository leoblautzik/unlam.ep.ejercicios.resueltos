#include <stdio.h>
void CARGAR(int [][4], int, int);
void MOSTRAR(int [][4], int, int);
void SumaXFila(int [][4], int[], int, int);
void SumaXColumna(int [][4], int[], int, int);
void MostrarVector(int[],int);
int main()
{
    int mat[5][4] = {
                        {10,3,2,5},
                        {2,3,10,20},
                        {7,2,3,2},
                        {70,20,10,20},
                        {2,3,5,3}
                    };
    int vecSumFila[5], vecSumColumna[4];
    //CARGAR(mat,5,4);
    MOSTRAR(mat,5,4);

    SumaXFila(mat,vecSumFila, 5,4);
    SumaXColumna(mat, vecSumColumna,5,4);

    printf("\nVector de suma por fila:");
    MostrarVector(vecSumFila, 5);

    printf("\nVector de suma por Columna:");
    MostrarVector(vecSumColumna, 4);
    return 0;
}
void SumaXColumna(int m[][4], int v[], int cf, int cc)
{
    int f,c;
    for(c=0;c<cc;c++)
    {
        v[c]=0;
        for (f=0;f<cf;f++)
            v[c]+=m[f][c];
    }
}

void SumaXFila(int m[][4], int v[], int cf, int cc)
{
    int f,c;
    for (f=0;f<cf;f++)
    {
        v[f]=0;
        for(c=0;c<cc;c++)
            v[f]+=m[f][c];
    }
}
void MostrarVector(int v[],int ce)
{
    int i;
    for (i=0;i<ce;i++)
        printf("\n%4d",v[i]);
}

void CARGAR(int m[][4], int cf, int cc)
{
    int f, c;
    for (f=0;f<cf;f++)
        for(c=0;c<cc;c++)
        {
            printf("Ingrese un valor:");
            scanf("%d",&m[f][c]);
        }
}
void MOSTRAR(int m[][4], int cf, int cc)
{
    int f, c;
    for (f=0;f<cf;f++)
    {
        for(c=0;c<cc;c++)
            printf("%6d", m[f][c]);

        printf("\n");
    }
}
