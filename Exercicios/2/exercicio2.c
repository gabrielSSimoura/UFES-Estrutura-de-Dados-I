#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
    char *nome;
    int matricula;
    float p1, p2, p3;
};

typedef struct aluno Aluno;

void imprime_aprovados(int n, Aluno **turma);
float media_turma(int n, Aluno **turma);
void imprime_turma(int n, Aluno **turma);
void leNome(char **nome);
void leAluno(Aluno *aluno);
float mediaAluno(Aluno *aluno);

int main()
{
    int tam;
    float media;
    printf("Numero de alunos na turma: ");
    scanf("%d", &tam);

    Aluno **turma = (Aluno **)calloc(tam, sizeof(Aluno *));

    //Alocar os alunos na turma;
    for (int i = 0; i < tam; i++)
    {
        turma[i] = (Aluno *)malloc(sizeof(Aluno));
        leAluno(turma[i]);
        printf("\n");
    }

    media = media_turma(tam, turma);
    imprime_turma(tam, turma);
    imprime_aprovados(tam, turma);
    printf("Media da turma: %.2f\n", media);

    // Liberar Memoria

    for (int i = 0; i < tam; i++)
    {
        free(turma[i]->nome);
        free(turma[i]);
    }
    free(turma);
    return 0;
}

void imprime_aprovados(int n, Aluno **turma)
{
    float media = 0;
    printf("Alunos Aprovados:\n");
    for (int i = 0; i < n; i++)
    {
        if ((media = mediaAluno(turma[i])) >= 5.0)
        {
            printf("Aluno: %s\n", turma[i]->nome);
        }
    }
    printf("\n");
}

float media_turma(int n, Aluno **turma)
{
    float media = 0;
    for (int i = 0; i < n; i++)
    {
        media += mediaAluno(turma[i]);
    }
    media = media / 3;
    return media;
}

float mediaAluno(Aluno *aluno)
{
    float media = 0;
    media += aluno->p1;
    media += aluno->p2;
    media += aluno->p3;
    media = media / 3;
    return media;
}

void imprime_turma(int n, Aluno **turma)
{
    for (int i = 0; i < n; i++)
    {
        printf("Aluno (0%d): ", (i + 1));
        printf("%s, ", turma[i]->nome);
        printf("%.2f, ", turma[i]->p1);
        printf("%.2f, ", turma[i]->p2);
        printf("%.2f\n", turma[i]->p3);
    }
}

void leNome(char **nome)
{
    setbuf(stdin, NULL);
    char *nomeAux = (char *)malloc(150 * sizeof(char));

    printf("Digite o nome do aluno: ");
    scanf("%[^\n]s", nomeAux);
    setbuf(stdin, NULL);

    *nome = strdup(nomeAux);
    free(nomeAux);
}

int leMatricula()
{
    int matricula;
    printf("Numero de matricula: ");
    scanf(" %d", &matricula);
    return matricula;
}

void leProva(Aluno *aluno)
{
    printf("Nota da p1: ");
    scanf("%f", &aluno->p1);

    printf("Nota da p2: ");
    scanf("%f", &aluno->p2);

    printf("Nota da p3: ");
    scanf("%f", &aluno->p3);
}

void leAluno(Aluno *aluno)
{
    leNome(&aluno->nome);
    aluno->matricula = leMatricula();
    leProva(aluno);
}