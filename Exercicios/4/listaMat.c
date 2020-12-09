#include "listaMat.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct cel Celula;

struct cel
{
    Matriz *mat;
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
};

void InsereLista(Lista *lista, Matriz *mat)
{
    Celula *nova = (Celula *)malloc(sizeof(Celula));
    nova->mat = mat;
    nova->proxima = lista->Prim;

    lista->Prim = nova;

    if (lista->Ult == NULL)
    {
        lista->Ult = nova;
    }
};

void ImprimeLista(Lista *lista)
{
    Celula *p;

    for (p = lista->Prim; p != NULL; p = p->proxima)
    {
        imprimeMatriz(p->mat);
        printf("\n");
    };
};

void RetiraLista(Lista *lista, int posicao)
{
    Celula *p = lista->Prim;
    Celula *ant = NULL;
    int i = 0;

    //busca
    while (p != NULL && i != posicao)
    {
        ant = p;
        p = p->proxima;
        i++;
    }

    if (p == NULL)
    {
        return;
    }

    if (p == lista->Prim && p == lista->Ult)
    {
        lista->Prim = lista->Ult = NULL;
    }
    else if (p == lista->Prim)
    {
        lista->Prim = p->proxima;
    }

    else if (p == lista->Ult)
    {
        lista->Ult = ant;
        lista->Ult->proxima = NULL;
    }
    else
    {
        ant->proxima = p->proxima;
    }
    free(p);
};

void DestroiLista(Lista *lista)
{
    Celula *p = lista->Prim;
    Celula *t;

    while (p != NULL)
    {
        t = p->proxima;
        free(p);
        p = t;
    }

    free(lista);
};