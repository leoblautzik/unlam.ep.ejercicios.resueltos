#include <stdio.h>
void CARGAR(int [][3], int, int);
void MOSTRAR(int [][3], int, int);
void MOSTRARTras(int [][2], int, int);
void Traspuesta(int [][3], int [][2],int, int);

int main()
{
    int mat[2][3];
    int matTras[3][2];
    CARGAR(mat,2,3);
    printf("Matriz:\n");
    MOSTRAR(mat,2,3);
    Traspuesta(mat, matTras, 2,3);
    printf("Matriz Traspuesta: \n");
    MOSTRARTras(matTras, 3, 2);

    return 0;
}

void Traspuesta(int mat[][3], int matTras[][2],int cf, int cc)
{
    int f, c;
    for (f=0;f<cf;f++)
        for(c=0;c<cc;c++)
        {
            matTras[c][f] = mat[f][c]; 
        }
}

void CARGAR(int m[][3], int cf, int cc)
{
    int f, c;
    for (f=0;f<cf;f++)
        for(c=0;c<cc;c++)
        {
            printf("Ingrese un valor:");
            scanf("%d",&m[f][c]);
        }
}

void MOSTRAR(int m[][3], int cf, int cc)
{
    int f, c;
    for (f=0;f<cf;f++)
    {
        for(c=0;c<cc;c++)
            printf("%6d", m[f][c]);

        printf("\n");
    }
}

void MOSTRARTras(int m[][2], int cf, int cc)
{
    int f, c;
    for (f=0;f<cf;f++)
    {
        for(c=0;c<cc;c++)
            printf("%6d", m[f][c]);

        printf("\n");
    }
}
