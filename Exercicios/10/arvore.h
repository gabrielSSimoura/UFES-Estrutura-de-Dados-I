#ifndef ARVORE_H_
#define ARVORE_H_

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

typedef struct arvore Arvore;

//Cria uma árvore vazia;
Arvore *inicializaArvore(void);

//Imprime árvore
void imprimeArvore(Arvore *arvore);

//Busca elemento na árvore;
Arvore *buscaArvore(Arvore *arvore, int chave);

//Cria uma árvore com a informação do nome do elemento e com a sub-árvore da esquerda e da direita;
Arvore *insereArvore(Arvore *arvore, Aluno *aluno);

//Retira Elemento da arvore
Arvore *retiraArvore(Arvore *arvore, int chave);

//Retorna a informação de um elemento de um nó
Aluno *informacaoNoArvore(Arvore *arvore);

//Retorna o número de folhas da árvore
int folhas(Arvore *arvore);

//Retorna a altura da árvore
int altura(Arvore *arvore);

//Retorna o status da árvore, se está vazia ou não
int vaziaArvore(Arvore *arvore);

//Libera o espaço de memória ocupado pela árvore
Arvore *liberaArvore(Arvore *arvore);

#endif /*ARVORE_H_*/
