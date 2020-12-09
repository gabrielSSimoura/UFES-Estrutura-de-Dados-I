#include <stdio.h>
#include <stdlib.h>
#include "TadPilhasDuplas.h"

#define MaxTam 1000

struct tipoitem
{
    int valor;
};

struct indicePilha
{
    int Topo;
    int Base;
};

struct tipopilhaDupla
{
    TipoItem *Item[MaxTam];
    IndicePilha Pilha1;
    IndicePilha Pilha2;
};

TipoPilhaDupla *InicializaPilha()
{
    TipoPilhaDupla *novaPilhaDupla = (TipoPilhaDupla *)malloc(sizeof(TipoPilhaDupla));

    novaPilhaDupla->Pilha1.Topo = -1; //Cresce para a direita;
    novaPilhaDupla->Pilha1.Base = 0;

    novaPilhaDupla->Pilha2.Topo = MaxTam;
    novaPilhaDupla->Pilha2.Base = MaxTam - 1; //Cresce para a esquerda

    return novaPilhaDupla;
}

int PilhaVazia(TipoPilhaDupla *pilhaDupla, int pilha)
{
    if (pilha < 1 || pilha > 2)
    {
        printf("Pilha não encontrada\n");
        return -1;
    }
    if (pilha == 1)
    {
        if (pilhaDupla->Pilha1.Topo == -1)
        {
            return 0; //Vazia
        }
        return 1;
    }
    else if (pilha == 2)
    {
        if (pilhaDupla->Pilha2.Topo == MaxTam)
        {
            return 0; //Vazia
        }
        return 1;
    }
}

void Empilha(TipoItem *Item, TipoPilhaDupla *pilhaDupla, int pilha)
{

    if (pilha < 1 || pilha > 2)
    {
        printf("Pilha não encontrada\n");
        return;
    }
    else if (pilhaDupla->Pilha1.Topo + 1 == pilhaDupla->Pilha2.Topo)
    {
        printf("Pilhas cheias, não é possível adicionar mais elementos\n");
        return;
    }

    if (pilha == 1)
    {
        pilhaDupla->Pilha1.Topo++;
        pilhaDupla->Item[pilhaDupla->Pilha1.Topo] = Item;
    }
    else if (pilha == 2)
    {
        pilhaDupla->Pilha2.Topo--;
        pilhaDupla->Item[pilhaDupla->Pilha2.Topo] = Item;
    }
}

void Desempilha(TipoItem *Item, TipoPilhaDupla *pilhaDupla, int pilha)
{
    if ((PilhaVazia(pilhaDupla, pilha)) == 0)
        printf("Erro: pilha esta vazia\n");
    else
    {
        if (pilha == 1)
        {
            Item = pilhaDupla->Item[pilhaDupla->Pilha1.Topo];
            pilhaDupla->Pilha1.Topo--;
        }
        else if (pilha == 2)
        {
            Item = pilhaDupla->Item[pilhaDupla->Pilha2.Topo];
            pilhaDupla->Pilha2.Topo++;
        }
    }
}

int RetornaTamanhoPilha(TipoPilhaDupla *pilhaDupla, int pilha)
{
    if (pilha < 1 || pilha > 2)
    {
        printf("Pilha não encontrada\n");
        return -1;
    }
    if (pilha == 1)
    {
        return (pilhaDupla->Pilha1.Topo + 1);
    }
    else if (pilha == 2)
    {
        return (MaxTam - pilhaDupla->Pilha2.Topo);
    }
}

int RetornaTamanhoPilhaDupla(TipoPilhaDupla *pilhaDupla)
{
    return (pilhaDupla->Pilha1.Topo + 1 + MaxTam - pilhaDupla->Pilha2.Topo);
}

TipoItem *InicializaTipoItem(int n)
{
    TipoItem *item = (TipoItem *)malloc(sizeof(TipoItem));
    item->valor = n;
    return item;
}

/*Imprime os itens da pilha */
void ImprimePilha(TipoPilhaDupla *pilhaDupla, int pilha)
{

    if (pilha < 1 || pilha > 2)
    {
        printf("Pilha não encontrada\n");
        return;
    }

    if (pilha == 1)
    {
        printf("Pilha 01 = ");
        for (int i = pilhaDupla->Pilha1.Topo; i >= 0; i--)
        {
            printf("%d ", pilhaDupla->Item[i]->valor);
        }
        printf("\n");
    }
    else if (pilha == 2)
    {
        printf("Pilha 02 = ");
        for (int i = pilhaDupla->Pilha2.Topo; i < MaxTam; i++)
        {
            printf("%d ", pilhaDupla->Item[i]->valor);
        }
        printf("\n");
    }
}

void DestroiPilhaDupla(TipoPilhaDupla *pilhaDupla)
{
    if (pilhaDupla)
    {
        free(pilhaDupla);
    }
}