#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
    float cr;
    char *nome;
    int matricula;
};

#include "aluno.h"

Aluno *IniciaAluno(int matricula, char *nome, float cr)
{
    Aluno *novoAluno = (Aluno *)malloc(sizeof(Aluno));
    novoAluno->matricula = matricula;
    novoAluno->cr = cr;
    novoAluno->nome = strdup(nome);

    return novoAluno;
}

int RetornaMatriculaAluno(Aluno *aluno)
{
    return aluno->matricula;
}

char *RetornaNomeAluno(Aluno *aluno)
{
    return aluno->nome;
}

float RetornaCrAluno(Aluno *aluno)
{
    return aluno->cr;
}

void ImprimeAluno(Aluno *aluno)
{
    printf("%s\n", aluno->nome);
    printf("%d\n", aluno->matricula);
    printf("%.2f\n", aluno->cr);
}

void ApagaAluno(Aluno *aluno)
{
    if (aluno)
    {
        free(aluno->nome);
        free(aluno);
    }
}