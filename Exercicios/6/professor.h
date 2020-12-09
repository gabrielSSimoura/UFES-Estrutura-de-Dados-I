#ifndef PROFESSOR_H_
#define PROFESSOR_H_

#include <stdio.h>

typedef struct professor Professor;

Professor *IniciaProfessor(int siape, char *nome, float salario);

int RetornaSiapeProfessor(Professor *professor);

char *RetornaNomeProfessor(Professor *professor);

float RetornaSalarioProfessor(Professor *professor);

void ImprimeProfessor(Professor *professor);

void ApagaProfessor(Professor *professor);

#endif /*PROFESSOR_H_*/