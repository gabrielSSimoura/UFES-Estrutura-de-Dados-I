#ifndef LISTAMAT_H_
#define LISTAMAT_H_

#include "matriz.h"
#include <stdio.h>

typedef struct lista Lista;

Lista *IniciaLista();

Lista *InsereLista(Lista *lista, Matriz *mat);

static Lista *busca(Lista *lista, int posicao);

void ImprimeLista(Lista *lista);

Lista *RetiraLista(Lista *lista, int posicao);

void DestroiLista(Lista *lista);

#endif
