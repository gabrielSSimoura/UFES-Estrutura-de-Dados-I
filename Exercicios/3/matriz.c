#include "matriz.h"
#include <stdlib.h>
#include <stdio.h>

struct matriz
{
    int **mat;
    int nlinhas;
    int ncolunas;
};

Matriz *inicializaMatriz(int nlinhas, int ncolunas)
{
    Matriz *matriz = (Matriz *)malloc(sizeof(Matriz));

    matriz->nlinhas = nlinhas;
    matriz->ncolunas = ncolunas;

    matriz->mat = (int **)calloc(sizeof(int *), nlinhas);

    for (int i = 0; i < nlinhas; i++)
        matriz->mat[i] = (int *)calloc(ncolunas, sizeof(int));

    return matriz;
}

void modificaElemento(Matriz *mat, int linha, int coluna, int elem)
{
    mat->mat[linha][coluna] = elem;
}

int recuperaElemento(Matriz *mat, int linha, int coluna)
{
    return mat->mat[linha][coluna];
}

int recuperaNColunas(Matriz *mat)
{
    return mat->ncolunas;
}

int recuperaNLinhas(Matriz *mat)
{
    return mat->nlinhas;
}

Matriz *transposta(Matriz *mat)
{
    Matriz *transp = inicializaMatriz(mat->ncolunas, mat->nlinhas);

    for (int i = 0; i < transp->nlinhas; i++)
    {
        for (int j = 0; j < transp->ncolunas; j++)
        {
            transp->mat[i][j] = mat->mat[j][i];
        }
    }

    return transp;
}

Matriz *multiplicacao(Matriz *mat1, Matriz *mat2)
{
    // Matriz resultado[linhaMat1][ColunaMat2];
    Matriz *multi = inicializaMatriz(mat1->nlinhas, mat2->ncolunas);

    if (mat1->ncolunas == mat2->nlinhas)
    {
        int aux = 0;
        for (int i = 0; i < multi->nlinhas; i++)
        {
            for (int j = 0; j < multi->ncolunas; j++)
            {

                multi->mat[i][j] = 0;
                for (int x = 0; x < mat2->nlinhas; x++)
                {
                    aux += mat1->mat[i][x] * mat2->mat[x][j];
                }

                multi->mat[i][j] = aux;
                aux = 0;
            }
        }
        return multi;
    }
}

void imprimeMatriz(Matriz *mat)
{
    for (int i = 0; i < mat->nlinhas; i++)
    {
        for (int j = 0; j < mat->ncolunas; j++)
        {
            printf("%d ", mat->mat[i][j]);
        }
        printf("\n");
    }
}

void destroiMatriz(Matriz *mat)
{

    for (int i = 0; i < mat->nlinhas; i++)
        free(mat->mat[i]);

    free(mat->mat);
    free(mat);
}