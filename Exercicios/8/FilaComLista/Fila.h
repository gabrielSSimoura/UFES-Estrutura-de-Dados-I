#ifndef FILA_H
#define FILA_H

#include <stdio.h>
#include <stdlib.h>

#include "aluno.h"

typedef struct fila Fila;

Fila *InicializaFila(void);

Aluno *RetiraFila(Fila *fila);

void InsereFila(Fila *fila, Aluno *aluno);

void ImprimeFila(Fila *fila);

void DestroiFila(Fila *fila);

#endif /* FILA_H */
