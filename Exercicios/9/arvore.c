#define _GNU_SOURCE
#include "arvore.h"

struct arvore
{
    Aluno *aluno;
    struct arvore *esquerda;
    struct arvore *direita;
};

//Cria uma árvore vazia;
Arvore *inicializaArvore(void)
{
    return NULL;
}

//Cria uma árvore com a informação do nome do Aluno e com a sub-árvore da esquerda e da direita;
Arvore *criaArvore(Aluno *aluno, Arvore *esquerda, Arvore *direita)
{
    Arvore *novaArvore = (Arvore *)malloc(sizeof(Arvore));
    novaArvore->aluno = aluno;
    novaArvore->esquerda = esquerda;
    novaArvore->direita = direita;

    return novaArvore;
}

//Retorna um pai de um dado nó
Arvore *arvorePai(Arvore *arvore, char *nome)
{
    if (vaziaArvore(arvore))
    {
        return NULL;
    }

    if (((!vaziaArvore(arvore->esquerda)) && (strcmp(RetornaNome(arvore->esquerda->aluno), nome) == 0)) || ((!vaziaArvore(arvore->direita)) && (strcmp(RetornaNome(arvore->direita->aluno), nome) == 0)))
    {
        return arvore;
    }

    Arvore *arvoreAuxiliar = arvorePai(arvore->esquerda, nome);
    if (arvoreAuxiliar == NULL)
    {
        arvoreAuxiliar = arvorePai(arvore->direita, nome);
    }
    return arvoreAuxiliar;
}

//Retorna a informação de um elemento de um nó
Aluno *informacaoNoArvore(Arvore *arvore)
{
    if (!vaziaArvore(arvore))
    {
        return arvore->aluno;
    }
    return NULL;
}

//Retorna o número de folhas da árvore
int folhas(Arvore *arvore)
{
    if (vaziaArvore(arvore->esquerda) && vaziaArvore(arvore->direita))
    {
        return 1;
    }
    else if (!vaziaArvore(arvore->esquerda) && vaziaArvore(arvore->direita))
    {
        return folhas(arvore->esquerda);
    }
    else if (vaziaArvore(arvore->esquerda) && !vaziaArvore(arvore->direita))
    {
        return folhas(arvore->direita);
    }
    return folhas(arvore->esquerda) + folhas(arvore->direita);
}

//Retorna o número de vezes que o aluno aparece na árvore
int ocorrencias(Arvore *arvore, char *nome)
{
    if (vaziaArvore(arvore))
    {
        return 0;
    }
    if (strcmp(RetornaNome(arvore->aluno), nome) == 0)
    {
        return (1 + ocorrencias(arvore->esquerda, nome) + ocorrencias(arvore->direita, nome));
    }
    return (ocorrencias(arvore->esquerda, nome) + ocorrencias(arvore->direita, nome));
}

static int maiorNumero(int a, int b)
{
    return (a > b) ? a : b;
}

//Retorna a altura da árvore
int altura(Arvore *arvore)
{
    if (vaziaArvore(arvore))
    {
        return -1;
    }
    else
        return 1 + maiorNumero(altura(arvore->esquerda), altura(arvore->direita));
}

//Retorna o status da árvore, se está vazia ou não
int vaziaArvore(Arvore *arvore)
{
    if (arvore == NULL)
    {
        return 1;
    }

    return 0;
}

//Retorna o status se o aluno pertence à essa árvore;
int pertenceArvore(Arvore *arvore, char *nome)
{
    if (vaziaArvore(arvore))
    {
        return 0; //Arvore Vazia ou não encontrou
    }

    return !strcmp(RetornaNome(arvore->aluno), nome) ||
           pertenceArvore(arvore->esquerda, nome) ||
           pertenceArvore(arvore->direita, nome);
}

//Imprime árvore
void imprimeArvore(Arvore *arvore)
{
    printf("<");
    if (!vaziaArvore(arvore))
    {
        printf("%s", RetornaNome(arvore->aluno));
        imprimeArvore(arvore->esquerda);
        imprimeArvore(arvore->direita);
    }
    printf(">");
}

//Libera o espaço de memória ocupado pela árvore
Arvore *liberaArvore(Arvore *arvore)
{
    if (!vaziaArvore(arvore))
    {
        liberaArvore(arvore->esquerda);
        liberaArvore(arvore->direita);
        free(arvore);
    }
    return NULL;
}