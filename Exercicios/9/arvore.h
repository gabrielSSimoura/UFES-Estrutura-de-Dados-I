#ifndef ARVORE_H_
#define ARVORE_H_

#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"

typedef struct arvore Arvore;

//Cria uma árvore vazia;
Arvore *inicializaArvore(void);

//Cria uma árvore com a informação do nome do elemento e com a sub-árvore da esquerda e da direita;
Arvore *criaArvore(Aluno *aluno, Arvore *esquerda, Arvore *direita);

//Retorna um pai de um dado nó
Arvore *arvorePai(Arvore *arvore, char *nome);

//Retorna a informação de um elemento de um nó
Aluno *informacaoNoArvore(Arvore *arvore);

//Retorna o número de folhas da árvore
int folhas(Arvore *arvore);

//Retorna o número de vezes que o elemento aparece na árvore
int ocorrencias(Arvore *arvore, char *nome);

//Retorna a altura da árvore
int altura(Arvore *arvore);

//Retorna o status da árvore, se está vazia ou não
int vaziaArvore(Arvore *arvore);

//Retorna o status se o elemento pertence à essa árvore;
int pertenceArvore(Arvore *arvore, char *nome);

//Imprime árvore
void imprimeArvore(Arvore *arvore);

//Libera o espaço de memória ocupado pela árvore
Arvore *liberaArvore(Arvore *arvore);

#endif /*ARVORE_H_*/
