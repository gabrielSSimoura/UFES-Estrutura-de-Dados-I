#ifndef FILACOMLISTA_H_
#define FILACOMLISTA_H_

#include <stdio.h>
#include "aluno.h"

typedef struct lista Lista;

Lista *IniciaLista();
Aluno *RetiraPosicao(Lista *lista, int posicao);
Aluno *RetiraLista(Lista *lista, char *chave);
void InsereLista(Lista *lista, Aluno *aluno);
void InsereListaFim(Lista *lista, Aluno *aluno);
void ImprimeLista(Lista *lista);
void DestroiLista(Lista *lista);

#endif /* FILACOMLISTA_H_ */