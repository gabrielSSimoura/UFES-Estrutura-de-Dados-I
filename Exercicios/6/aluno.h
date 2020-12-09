#ifndef ALUNO_H_
#define ALUNO_H_

#include <stdio.h>

typedef struct aluno Aluno;

Aluno *IniciaAluno(int materia, char *nome, float cr);

int RetornaMateriaAluno(Aluno *aluno);

char *RetornaNomeAluno(Aluno *aluno);

float RetornaCrAluno(Aluno *aluno);

void ImprimeAluno(Aluno *aluno);

void ApagaAluno(Aluno *aluno);

#endif /*ALUNO_H_*/