#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROF 0
#define ALU 1

typedef struct celula Celula;

struct celula
{
    int tipo;
    void *item;
    Celula *proxima;
};

struct lista
{
    Celula *Primeira;
    Celula *Ultima;
};

#include "lista.h"

Lista *IniciaLista(void)
{
    Lista *novaLista = (Lista *)malloc(sizeof(Lista));
    novaLista->Primeira = NULL;
    novaLista->Ultima = NULL;

    return novaLista;
}

void InsereAluno(Lista *lista, Aluno *aluno)
{
    Celula *novaCelula = (Celula *)malloc(sizeof(Celula));
    novaCelula->tipo = ALU;
    novaCelula->item = aluno;
    novaCelula->proxima = lista->Primeira;

    lista->Primeira = novaCelula;
    if (lista->Ultima == NULL)
    {
        lista->Ultima = novaCelula;
    }
}

void InsereProfessor(Lista *lista, Professor *professor)
{
    Celula *novaCelula = (Celula *)malloc(sizeof(Celula));
    novaCelula->tipo = PROF;
    novaCelula->item = professor;
    novaCelula->proxima = lista->Primeira;

    lista->Primeira = novaCelula;

    if (lista->Ultima == NULL)
    {
        lista->Ultima = novaCelula;
    }
}

void ImprimeLista(Lista *lista)
{
    Celula *celula;

    for (celula = lista->Primeira; celula != NULL; celula = celula->proxima)
    {
        if (celula->tipo == ALU)
        {
            printf("Aluno: ");
            ImprimeAluno(celula->item);
        }

        if (celula->tipo == PROF)
        {
            printf("Professor: ");
            ImprimeProfessor(celula->item);
        }
    }
}

float ValorChurrasco(Lista *lista)
{
    Celula *celula = lista->Primeira;

    float valor = 0.0;

    while (celula != NULL)
    {
        if (celula->tipo == PROF)
        {
            valor = valor + 0.02 * RetornaSalarioProfessor(celula->item);
        }
        if (celula->tipo == ALU)
        {
            valor = valor + 30.0;
        }
        celula = celula->proxima;
    }
    return valor;
}
void RetiraLista(Lista *lista, char *nome)
{
    Celula *celulaAtual;
    Celula *celulaAnterior = NULL;

    //faz a busca

    for (celulaAtual = lista->Primeira; celulaAtual != NULL; celulaAtual = celulaAtual->proxima)
    {
        if (celulaAtual->tipo == ALU)
        {
            if (strcmp(RetornaNomeAluno(celulaAtual->item), nome) == 0)
            {
                break;
            }
        }
        else if (celulaAtual->tipo == PROF)
        {
            if (strcmp(RetornaNomeProfessor(celulaAtual->item), nome) == 0)
            {
                break;
            }
        }

        celulaAnterior = celulaAtual;
    }

    //Não encontrou, lista vazia
    if (celulaAtual == NULL)
    {
        return;
    }

    // Caso for o único elemento da lista;
    if (celulaAtual == lista->Primeira && celulaAtual == lista->Ultima)
    {
        lista->Primeira = lista->Ultima = NULL;
    }

    else if (celulaAtual == lista->Primeira)
    {
        lista->Primeira = celulaAtual->proxima;
    }

    else if (celulaAtual == lista->Ultima)
    {
        lista->Ultima = celulaAnterior;
        lista->Ultima->proxima = NULL;
    }
    else
    {
        celulaAnterior->proxima = celulaAtual->proxima;
    }

    free(celulaAtual);
};

void ApagaLista(Lista *lista)
{
    Celula *celula = lista->Primeira;
    Celula *auxiliar;

    if (lista)
    {
        while (celula != NULL)
        {
            auxiliar = celula->proxima;
            free(celula);
            celula = auxiliar;
        }
        free(lista);
    }
}