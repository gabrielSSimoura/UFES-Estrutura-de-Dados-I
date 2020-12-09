#ifndef LISTAMAT_H_
#define LISTAMAT_H_

#include "matriz.h"
#include <stdio.h>

typedef struct lista Lista;

Lista *IniciaLista();

void InsereLista(Lista *lista, Matriz *mat);

void ImprimeLista(Lista *lista);

void RetiraLista(Lista *lista, int posicao);

void DestroiLista(Lista *lista);

#endif
