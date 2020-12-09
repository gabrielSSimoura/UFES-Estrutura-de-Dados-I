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

//Imprime árvore
void imprimeArvore(Arvore *arvore)
{
    if (!vaziaArvore(arvore))
    {
        imprimeArvore(arvore->esquerda);
        ImprimeAluno(arvore->aluno);
        imprimeArvore(arvore->direita);
    }
}

//Busca elemento na árvore; //retorna o nó que contem o Elemento;
Arvore *buscaArvore(Arvore *arvore, int chave)
{
    if (arvore == NULL)
    {
        return NULL;
    }
    else if (RetornaMatricula(arvore->aluno) > chave)
    {
        return buscaArvore(arvore->esquerda, chave);
    }
    else if (RetornaMatricula(arvore->aluno) < chave)
    {
        return buscaArvore(arvore->direita, chave);
    }
    else
        return arvore;
}

//Cria uma árvore com a informação do nome do elemento e com a sub-árvore da esquerda e da direita;
Arvore *insereArvore(Arvore *arvore, Aluno *aluno)
{
    if (arvore == NULL)
    {
        //alocar o nó
        arvore = (Arvore *)malloc(sizeof(Arvore));
        arvore->aluno = aluno;
        arvore->esquerda = arvore->direita = NULL;
    }

    //Busca o nó que deve inserir
    else if (RetornaMatricula(aluno) < RetornaMatricula(arvore->aluno))
    {
        arvore->esquerda = insereArvore(arvore->esquerda, aluno);
    }
    else
        arvore->direita = insereArvore(arvore->direita, aluno);

    return arvore;
}

//Retira Elemento da arvore
Arvore *retiraArvore(Arvore *arvore, int chave)
{
    if (vaziaArvore(arvore))
    {
        return NULL;
    }
    else if (RetornaMatricula(arvore->aluno) > chave)
    {
        arvore->esquerda = retiraArvore(arvore->esquerda, chave);
    }
    else if (RetornaMatricula(arvore->aluno) < chave)
    {
        arvore->direita = retiraArvore(arvore->direita, chave);
    }

    //Encontrou
    else
    {
        // Nó é a folha
        if (arvore->esquerda == NULL && arvore->direita == NULL)
        {
            free(arvore);
            arvore = NULL;
        }

        //Nó com filho somente pra direita
        else if (arvore->esquerda == NULL)
        {
            Arvore *arvoreAuxiliar = arvore;
            arvore = arvore->direita;
            free(arvoreAuxiliar);
        }

        //Nó com filho somente pra esquerda
        else if (arvore->direita == NULL)
        {
            Arvore *arvoreAuxiliar = arvore;
            arvore = arvore->esquerda;
            free(arvoreAuxiliar);
        }
        //Nó com dois filhos
        else
        {
            //Busca o anterior
            Arvore *arvoreAuxiliar = arvore->esquerda;
            while (arvoreAuxiliar->direita != NULL)
            {
                arvoreAuxiliar = arvore->direita;
            }

            //Troca das informações;
            Aluno *alunoAuxiliar = arvore->aluno;
            arvore->aluno = arvoreAuxiliar->aluno;
            arvoreAuxiliar->aluno = alunoAuxiliar;

            //Chama a função novamente;
            arvore->esquerda = retiraArvore(arvore->esquerda, chave);
        }
    }
    return arvore;
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

//Retorna o maior numero;
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