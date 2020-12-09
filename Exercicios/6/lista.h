#ifndef LISTA_H_
#define LISTA_H_

#include <stdio.h>
#include "aluno.h"
#include "professor.h"

typedef struct lista Lista;

Lista *IniciaLista(void);

void InsereAluno(Lista *lista, Aluno *aluno);

void InsereProfessor(Lista *lista, Professor *professor);

void ImprimeLista(Lista *lista);

float ValorChurrasco(Lista *lista);

void RetiraLista(Lista *lista, char *nome);

void ApagaLista(Lista *lista);

#endif /*LISTA_H_*/