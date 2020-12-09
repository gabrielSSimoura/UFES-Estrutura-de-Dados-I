#include <stdio.h>
#include "listaMat.h"

//definindo constantes para o número de linhas e colunas da matriz
#define NLINHAS 5
#define NCOLUNAS 4

int main()
{
    Matriz *mat1 = inicializaMatriz(NLINHAS, NCOLUNAS);
    Matriz *mat2 = inicializaMatriz(NLINHAS, NCOLUNAS);
    Matriz *mat3 = inicializaMatriz(NLINHAS, NCOLUNAS);

    Lista *lista = IniciaLista();

    int i, j;
    //preenchendo a matriz com valores para teste
    for (i = 0; i < NLINHAS; i++)
        for (j = 0; j < NCOLUNAS; j++)
            modificaElemento(mat1, i, j, 2 * (i + j));

    lista = InsereLista(lista, mat1);

    for (i = 0; i < NLINHAS; i++)
        for (j = 0; j < NCOLUNAS; j++)
            modificaElemento(mat2, i, j, i + j);

    lista = InsereLista(lista, mat2);

    for (i = 0; i < NLINHAS; i++)
        for (j = 0; j < NCOLUNAS; j++)
            modificaElemento(mat3, i, j, 5 * (i + j));

    lista = InsereLista(lista, mat3);

    
    lista = RetiraLista(lista, 1);
    lista = RetiraLista(lista, 0);
    lista = RetiraLista(lista, 2); //Posição não existe

    lista = InsereLista(lista, mat1);
    lista = InsereLista(lista, mat2);
    lista = InsereLista(lista, mat3);

    //Imprime a lista
    ImprimeLista(lista);

    //Apaga a lista
    DestroiLista(lista);

    //Apaga as matrizes
    destroiMatriz(mat1);
    destroiMatriz(mat2);
    destroiMatriz(mat3);
}