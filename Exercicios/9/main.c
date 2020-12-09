#define _GNU_SOURCE

#include "arvore.h"

int main(int argc, char const *argv[])
{
    //Cria Arvore de teste
    Arvore *arvore = inicializaArvore();
    Arvore *arvore2 = inicializaArvore();
    Arvore *arvore3 = inicializaArvore();
    Arvore *arvore4 = inicializaArvore();
    Arvore *arvore5 = inicializaArvore();
    Arvore *arvore6 = inicializaArvore();

    Aluno *a1 = InicializaAluno(1, "gabriel", 10.0);
    Aluno *a2 = InicializaAluno(13, "patricia", 10.0);
    Aluno *a3 = InicializaAluno(132, "maria", 10.0);
    Aluno *a4 = InicializaAluno(144, "henrique", 10.0);
    Aluno *a5 = InicializaAluno(15, "gabriel", 10.0);
    Aluno *a6 = InicializaAluno(167, "gabriel", 10.0);

    arvore2 = criaArvore(a6, inicializaArvore(), inicializaArvore());
    arvore3 = criaArvore(a5, inicializaArvore(), inicializaArvore());
    arvore4 = criaArvore(a4, arvore2, arvore3);
    arvore5 = criaArvore(a3, inicializaArvore(), inicializaArvore());
    arvore6 = criaArvore(a2, inicializaArvore(), arvore5);
    arvore = criaArvore(a1, arvore6, arvore4);

    int qtdFolhas = 0, tamAltura = 0, qtdOcorrencias = 0;

    qtdOcorrencias = ocorrencias(arvore, "gabriel");
    printf("Ocorrencias: %d\n", qtdOcorrencias);

    tamAltura = altura(arvore);
    printf("Altura: %d\n", tamAltura);

    qtdFolhas = folhas(arvore);
    printf("Folhas: %d\n", qtdFolhas);

    printf("Vazia arvore2: %d\n", vaziaArvore(arvore2));

    imprimeArvore(arvorePai(arvore6, "patricia"));
    printf("\n");
    imprimeArvore(arvore);
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
