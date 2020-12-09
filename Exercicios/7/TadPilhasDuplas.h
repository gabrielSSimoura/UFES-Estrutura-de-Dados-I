#ifndef PILHASDUPLAS_H_
#define PILHASDUPLAS_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct tipoitem TipoItem;
typedef struct indicePilha IndicePilha;
typedef struct tipopilhaDupla TipoPilhaDupla;

TipoPilhaDupla *InicializaPilha();

TipoItem *InicializaTipoItem(int n);

int PilhaVazia(TipoPilhaDupla *pilhaDupla, int pilha);

void Empilha(TipoItem *Item, TipoPilhaDupla *pilhaDupla, int pilha);

void Desempilha(TipoItem *Item, TipoPilhaDupla *pilhaDupla, int pilha);

int RetornaTamanhoPilhaDupla(TipoPilhaDupla *pilhaDupla);

int RetornaTamanhoPilha(TipoPilhaDupla *pilhaDupla, int pilha);

void ImprimePilha(TipoPilhaDupla *pilhaDupla, int pilha);

void DestroiPilhaDupla(TipoPilhaDupla *pilhaDupla);

#endif /*PILHASDUPLAS_H_*/