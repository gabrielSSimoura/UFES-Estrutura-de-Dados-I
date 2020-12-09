#include <stdio.h>
#include "listaMat.h"

//definindo constantes para o número de linhas e colunas da matriz
#define NLINHAS 5
#define NCOLUNAS 4

int main()
{
    Lista *lista = IniciaLista();
    Lista *listaTransposta = IniciaLista();
    Matriz *mat1 = inicializaMatriz(NLINHAS, NCOLUNAS);
    Matriz *mat2 = inicializaMatriz(NLINHAS, NCOLUNAS);
    Matriz *mat3 = inicializaMatriz(NLINHAS, NCOLUNAS);
    Matriz *trp1;
    Matriz *trp2;
    Matriz *trp3;

    int i, j;
    //preenchendo a matriz com valores para teste
    for (i = 0; i < NLINHAS; i++)
        for (j = 0; j < NCOLUNAS; j++)
            modificaElemento(mat1, i, j, 2 * (i + j));

    trp1 = transposta(mat1);
    InsereLista(lista, mat1);
    InsereLista(listaTransposta, trp1);

    for (i = 0; i < NLINHAS; i++)
        for (j = 0; j < NCOLUNAS; j++)
            modificaElemento(mat2, i, j, i + j);

    trp2 = transposta(mat2);
    InsereLista(lista, mat2);
    InsereLista(listaTransposta, trp2);

    for (i = 0; i < NLINHAS; i++)
        for (j = 0; j < NCOLUNAS; j++)
            modificaElemento(mat3, i, j, 5 * (i + j));

    trp3 = transposta(mat3);
    InsereLista(lista, mat3);
    InsereLista(lista, trp3);

    RetiraLista(lista, 0); //Primeira
    RetiraLista(lista, 1);
    RetiraLista(lista, 1);
    RetiraLista(lista, 2); //Posição não existe

    InsereLista(lista, mat1);
    InsereLista(lista, mat2);
    InsereLista(lista, mat3);

    //Imprime as listas
    ImprimeLista(lista);
    ImprimeLista(listaTransposta);

    //Apaga as listas
    DestroiLista(lista);
    DestroiLista(listaTransposta);

    //Apaga as matrizes
    destroiMatriz(mat1);
    destroiMatriz(mat2);
    destroiMatriz(mat3);

    //Apaga as matrizes transpostas
    destroiMatriz(trp1);
    destroiMatriz(trp2);
    destroiMatriz(trp3);
}