#include "listaMat.h"
#include <stdlib.h>
#include <stdio.h>

struct lista
{

    Matriz *mat;
    Lista *proxima;
    Lista *anterior;
};

Lista *IniciaLista(void)
{
    return NULL;
};

//Insere no Inicio da Lista
Lista *InsereLista(Lista *lista, Matriz *mat)
{
    Lista *nova = (Lista *)malloc(sizeof(Lista));
    nova->mat = mat;
    nova->anterior = NULL;
    nova->proxima = lista;

    if (lista != NULL)
    {
        lista->anterior = nova;
    }
    return nova;
};

static Lista *busca(Lista *lista, int posicao)
{
    Lista *p = lista;
    Lista *ant = NULL;

    int i = 0;

    //realiza a busca
    while (p != NULL && i != posicao)
    {
        ant = p;
        p = p->proxima;
        i++;
    }

    return p;
}
Lista *RetiraLista(Lista *lista, int posicao)
{

    //busca
    Lista *p = busca(lista, posicao);

    if (p == NULL)
    {
        return lista;
    };
    if (p->anterior == NULL && p->proxima == NULL)
    {

        lista = IniciaLista();
        return lista;
    };

    if (p->anterior != NULL)

        p->anterior->proxima = p->proxima;

    else
    {
        lista = p->proxima;
        lista->anterior = NULL;
    }

    if (p->proxima != NULL)

        p->proxima->anterior = p->anterior;

    else
    {
        p->anterior->anterior = NULL;
    }
    free(p);
    return lista;
};

void ImprimeLista(Lista *lista)
{
    Lista *p;

    for (p = lista; p != NULL; p = p->proxima)
    {
        imprimeMatriz(p->mat);
        printf("\n");
    };
};

void DestroiLista(Lista *lista)
{
    Lista *p = lista;
    Lista *t;

    while (p != NULL)
    {
        t = p->proxima;
        free(p);
        p = t;
    }
};