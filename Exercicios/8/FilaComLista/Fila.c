#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FilaComLista.h"
#include "Fila.h"

#define TAM 10

struct fila
{
    Lista *lista;
};

Fila *InicializaFila(void)
{
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->lista = IniciaLista();
    return fila;
}

void InsereFila(Fila *fila, Aluno *aluno)
{
    InsereListaFim(fila->lista, aluno);
}

void ImprimeFila(Fila *fila)
{
    ImprimeLista(fila->lista);
}

Aluno *RetiraFila(Fila *fila)
{
    return RetiraPosicao(fila->lista, 0);
}

void DestroiFila(Fila *fila)
{
    DestroiLista(fila->lista);
    free(fila);
}