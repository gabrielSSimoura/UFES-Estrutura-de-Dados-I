#define _GNU_SOURCE

#include "arvore.h"

int main(int argc, char const *argv[])
{
    //Cria Arvore de teste
    Arvore *arvore = inicializaArvore();

    //Cria Alunos;
    Aluno *a1 = InicializaAluno(200, "gabriel", 10.0);
    Aluno *a2 = InicializaAluno(23, "patricia", 10.0);
    Aluno *a3 = InicializaAluno(10, "lais", 10.0);
    Aluno *a4 = InicializaAluno(144, "henrique", 10.0);
    Aluno *a5 = InicializaAluno(132, "pedro", 10.0);
    Aluno *a6 = InicializaAluno(100, "luiza", 10.0);

    //Inserindo alunos;
    arvore = insereArvore(arvore, a3);
    arvore = insereArvore(arvore, a1);
    arvore = insereArvore(arvore, a2);
    arvore = insereArvore(arvore, a4);
    arvore = insereArvore(arvore, a5);
    arvore = insereArvore(arvore, a6);

    printf("\nArvore Original: \n\n");
    imprimeArvore(arvore);

    //Retira Alunos;
    arvore = retiraArvore(arvore, 201);
    arvore = retiraArvore(arvore, 144);
    arvore = retiraArvore(arvore, 10);
    arvore = retiraArvore(arvore, 132);
    arvore = retiraArvore(arvore, 23);
    arvore = retiraArvore(arvore, 23);

    printf("\nApós retirar: \n\n");
    imprimeArvore(arvore);

    //Testando Busca nó da arvore
    Arvore *busca = buscaArvore(arvore, 100);

    printf("\nArvore buscada: \n");
    imprimeArvore(busca);
    printf("\n");

    arvore = liberaArvore(arvore);

    ApagaAluno(a1);
    ApagaAluno(a2);
    ApagaAluno(a3);
    ApagaAluno(a4);
    ApagaAluno(a5);
    ApagaAluno(a6);

    return 0;
}
