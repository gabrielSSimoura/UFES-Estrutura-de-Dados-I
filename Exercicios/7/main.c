#include <stdio.h>
#include <stdlib.h>

#include "TadPilhasDuplas.h"

int main(int argc, char const *argv[])
{
    TipoItem *item1 = InicializaTipoItem(3);
    TipoItem *item2 = InicializaTipoItem(5);
    TipoItem *item3 = InicializaTipoItem(145);
    TipoItem *item4 = InicializaTipoItem(12);
    TipoItem *item5 = InicializaTipoItem(24);
    TipoItem *item6 = InicializaTipoItem(1235);
    TipoItem *item7 = InicializaTipoItem(1543);
    TipoItem *item8 = InicializaTipoItem(156);

    TipoPilhaDupla *pilhaDupla = InicializaPilha();

    Empilha(item4, pilhaDupla, 2);
    Empilha(item5, pilhaDupla, 1);
    Empilha(item5, pilhaDupla, 1);
    Empilha(item4, pilhaDupla, 1);
    Empilha(item5, pilhaDupla, 1);
    Empilha(item4, pilhaDupla, 1);
    Empilha(item2, pilhaDupla, 2);
    Empilha(item6, pilhaDupla, 1);
    Empilha(item7, pilhaDupla, 2);
    Empilha(item8, pilhaDupla, 1);
    Empilha(item2, pilhaDupla, 2);
    Empilha(item6, pilhaDupla, 1);
    Empilha(item7, pilhaDupla, 2);
    Empilha(item8, pilhaDupla, 1);
    Empilha(item2, pilhaDupla, 2);
    Empilha(item5, pilhaDupla, 1);
    Empilha(item5, pilhaDupla, 1);
    Empilha(item4, pilhaDupla, 1);
    Empilha(item2, pilhaDupla, 2);
    Empilha(item6, pilhaDupla, 1);
    Empilha(item7, pilhaDupla, 2);
    Empilha(item8, pilhaDupla, 1);

    ImprimePilha(pilhaDupla, 1);
    ImprimePilha(pilhaDupla, 2);
    printf("-------------------------\n");

    Desempilha(item1, pilhaDupla, 1);
    Desempilha(item2, pilhaDupla, 2);
    Desempilha(item1, pilhaDupla, 1);
    Desempilha(item2, pilhaDupla, 2);
    Desempilha(item1, pilhaDupla, 1);
    Desempilha(item2, pilhaDupla, 2);
    Desempilha(item2, pilhaDupla, 2);
    Desempilha(item2, pilhaDupla, 2);
    Desempilha(item1, pilhaDupla, 1);

    printf("-------------------------\n");

    ImprimePilha(pilhaDupla, 1);
    ImprimePilha(pilhaDupla, 2);

    free(item1);
    free(item2);
    free(item3);
    free(item4);
    free(item5);
    free(item6);
    free(item7);
    free(item8);

    free(pilhaDupla);

    return 0;
}
