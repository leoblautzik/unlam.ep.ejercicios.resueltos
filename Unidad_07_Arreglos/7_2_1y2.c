#include <stdio.h>
void CARGAR(int [][4], int, int);
void MOSTRAR(int [][4], int, int);
void MOSTRARTras(int [][5], int, int);
void Multiplicar(int [][4], int, int, int);
void Traspuesta(int [][4], int [][5],int, int);

int main()
{
    int cte = -2;
    int mat[5][4] = {
                        {10,3,2,5},
                        {2,3,10,20},
                        {7,2,3,2},
                        {70,20,10,20},
                        {2,3,5,3}
                    };

    int matTras[4][5];
    //CARGAR(mat,5,4);
    printf("Matriz\n");
    MOSTRAR(mat,5,4);
    
    Multiplicar(mat,5,4,-1);
    printf("Matriz * %d: \n", cte);
    
    MOSTRAR(mat,5,4);
    Traspuesta(mat, matTras, 5,4);
    
    printf("Matriz Traspuesta: \n");
    MOSTRARTras(matTras, 4, 5);

    return 0;
}

void Traspuesta(int mat[5][4], int matTras[4][5],int cf, int cc)
{
    int f, c;
    for (f=0;f<cf;f++)
        for(c=0;c<cc;c++)
        {
            matTras[c][f] = mat[f][c]; 
        }
}

void Multiplicar(int m[][4], int cf, int cc, int num)
{
    
    int f, c;
    for (f=0;f<cf;f++)
        for(c=0;c<cc;c++)
        {
            m[f][c] *= num; 
        }

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

void MOSTRARTras(int m[][5], int cf, int cc)
{
    int f, c;
    for (f=0;f<cf;f++)
    {
        for(c=0;c<cc;c++)
            printf("%6d", m[f][c]);

        printf("\n");
    }
}
