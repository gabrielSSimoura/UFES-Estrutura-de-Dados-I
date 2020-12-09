#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct professor
{
    int siape;
    char *nome;
    float salario;
};

#include "professor.h"

Professor *IniciaProfessor(int siape, char *nome, float salario)
{
    Professor *novoProfessor = (Professor *)malloc(sizeof(Professor));
    novoProfessor->nome = strdup(nome);
    novoProfessor->salario = salario;
    novoProfessor->siape = siape;

    return novoProfessor;
}

int RetornaSiapeProfessor(Professor *professor)
{
    return professor->siape;
}

char *RetornaNomeProfessor(Professor *professor)
{
    return professor->nome;
}

float RetornaSalarioProfessor(Professor *professor)
{
    return professor->salario;
}

void ImprimeProfessor(Professor *professor)
{
    printf("Siape: %d , ", professor->siape);
    printf("Nome: %s, ", professor->nome);
    printf("Salario: %.2f\n", professor->salario);
}

void ApagaProfessor(Professor *professor)
{
    if (professor)
    {
        free(professor->nome);
        free(professor);
    }
}