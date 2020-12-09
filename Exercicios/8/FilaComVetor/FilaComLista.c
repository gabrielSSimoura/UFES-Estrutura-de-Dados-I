#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FilaComLista.h"

typedef struct celula Celula;

struct celula
{
    Aluno *aluno;
    Celula *proxima;
};

struct lista
{
    Celula *Prim;
    Celula *Ult;
};

Lista *IniciaLista(void)
{
    Lista *lista = (Lista *)malloc(sizeof(Lista));
    lista->Prim = NULL;
    lista->Ult = NULL;

    return lista;
}

void ImprimeLista(Lista *lista)
{
    Celula *celulaAtual;
    if (lista == NULL)
    {
        printf("Lista vazia\n");
        return;
    }
    for (celulaAtual = lista->Prim; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        ImprimeAluno(celulaAtual->aluno);
    }
}

void InsereLista(Lista *lista, Aluno *aluno)
{
    Celula *novaCelula = (Celula *)malloc(sizeof(Celula));

    novaCelula->aluno = aluno;
    novaCelula->proxima = lista->Prim;

    lista->Prim = novaCelula;

    if (lista->Ult == NULL)
    {
        lista->Ult = novaCelula;
    }
}

void InsereListaFim(Lista *lista, Aluno *aluno)
{
    Celula *novaCelula = (Celula *)malloc(sizeof(Celula));
    novaCelula->aluno = aluno;
    novaCelula->proxima = NULL;

    if (lista->Prim == NULL)
    {
        lista->Prim = lista->Ult = novaCelula;
        return;
    }

    lista->Ult->proxima = novaCelula;
    lista->Ult = novaCelula;
}

Aluno *RetiraLista(Lista *lista, char *chave)
{
    Celula *celulaAtual = lista->Prim;
    Aluno *aluno;
    Celula *celulaAnterior = NULL;

    //faz a busca
    while (celulaAtual != NULL && strcmp(RetornaNome(celulaAtual->aluno), chave))
    {
        celulaAnterior = celulaAtual;
        celulaAtual = celulaAtual->proxima;
    }

    //Lista Vazia/ Aluno não encontrado
    if (celulaAtual == NULL)
    {
        return NULL;
    }

    aluno = celulaAtual->aluno;

    //Uma célula
    if (lista->Prim == celulaAtual && lista->Ult == celulaAtual)
    {
        lista->Prim = NULL;
        lista->Ult = NULL;
    }

    //Primeiro
    else if (lista->Prim == celulaAtual)
    {
        lista->Prim = celulaAtual->proxima;
    }

    //Ultimo
    else if (lista->Ult == celulaAtual)
    {
        lista->Ult = celulaAnterior;
        lista->Ult->proxima = NULL;
    }

    else
    {
        celulaAnterior->proxima = celulaAtual->proxima;
    }

    free(celulaAtual);

    return aluno;
}

Aluno *RetiraPosicao(Lista *lista, int posicao)
{
    Celula *celulaAtual = lista->Prim;
    Aluno *aluno;
    Celula *celulaAnterior = NULL;

    int i = 0;

    while (i < posicao && celulaAtual != NULL)
    {
        celulaAnterior = celulaAtual;
        celulaAtual = celulaAtual->proxima;
        i++;
    }

    //Lista Vazia/ Aluno não encontrado
    if (celulaAtual == NULL)
        return NULL;

    aluno = celulaAtual->aluno;

    //Uma Célula
    if (lista->Prim == celulaAtual && lista->Ult == celulaAtual)
    {
        lista->Prim = NULL;
        lista->Ult = NULL;
    }

    //Primeiro
    else if (lista->Prim == celulaAtual)
    {
        lista->Prim = celulaAtual->proxima;
    }

    //Ultimo
    else if (lista->Ult == celulaAtual)
    {
        lista->Ult = celulaAnterior;
        lista->Ult->proxima = NULL;
    }

    else
    {
        celulaAnterior->proxima = celulaAtual->proxima;
    }

    free(celulaAtual);

    return aluno;
}

void DestroiLista(Lista *lista)
{
    Celula *celulaAtual = lista->Prim;
    Celula *celulaAnterior = NULL;

    while (celulaAtual != NULL)
    {
        celulaAnterior = celulaAtual->proxima;
        if (celulaAtual->aluno != NULL)
        {

            free(celulaAtual);
        }
        celulaAtual = celulaAnterior;
    }

    free(lista);
}