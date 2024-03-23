#include <stdio.h>
#define TAM 3

// void buscar(int[][TAM], int);
void mover(int[][TAM], int);
void mostrar(int[][TAM]);
int esGanadora(int[][TAM]);

int main()
{
    int n;
    int mat[3][3] = {{2, 5, 1}, {7, 6, 3}, {8, 0, 4}};
    mostrar(mat);
    do
    {
        printf("Mover: ");
        scanf("%d", &n);
        mover(mat, n);
        mostrar(mat);
    } while (esGanadora(mat) == 0);
}

void mostrar(int matriz[][TAM])
{
    for (int i = 0; i < TAM; i++)
    {
        printf("\n");
        for (int j = 0; j < TAM; j++)
            if (matriz[i][j] == 0)
                printf("  ");
            else
                printf("%d ", matriz[i][j]);
    }
    printf("\n");
}
void mover(int matriz[TAM][TAM], int n)
{
    int i, j;
    int encontrado = 0;
    i = 0;
    while (i < TAM && encontrado == 0)
    {
        j = 0;
        while (j < TAM && encontrado == 0)
        {
            if (matriz[i][j] == n)
            {
                encontrado = 1;
                if (j < TAM && matriz[i][j + 1] == 0)
                {
                    matriz[i][j + 1] = n;
                    matriz[i][j] = 0;
                }
                if (j > 0 && matriz[i][j - 1] == 0)
                {
                    matriz[i][j - 1] = n;
                    matriz[i][j] = 0;
                }
                if (i > 0 && matriz[i - 1][j] == 0)
                {
                    matriz[i - 1][j] = n;
                    matriz[i][j] = 0;
                }
                if (i < TAM && matriz[i + 1][j] == 0)
                {
                    matriz[i + 1][j] = n;
                    matriz[i][j] = 0;
                }
            }
            j++;
        }
        i++;
    }
    printf("\n");
}

int esGanadora(int mat[][TAM])
{
    int gana[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 0}};
    int ganadora = 1;
    int i, j;
    i = 0;
    while (i < TAM && ganadora == 1)
    {
        j = 0;
        while (j < TAM && ganadora == 1)
        {
            if (mat[i][j] != gana[i][j])
                ganadora = 0;

            j++;
        }
        i++;
    }
    return ganadora;
}
