#define _GNU_SOURCE

#include <stdio.h>
#include "listaalunos.h"

int main(int argc, char const *argv[])
{
    ListaGen *lista = criaLista();

    Aluno *a1 = InicializaAluno(1, "gabriel", 9.0);
    lista = insereLista(lista, a1);
    Aluno *a2 = InicializaAluno(13, "emerson", 9.0);
    lista = insereLista(lista, a2);

    Aluno *a3 = InicializaAluno(132, "maria", 9.0);
    lista = insereLista(lista, a3);

    Aluno *a4 = InicializaAluno(144, "henriques", 10.0);
    lista = insereLista(lista, a4);

    Aluno *a5 = InicializaAluno(15, "andre", 10.0);
    lista = insereLista(lista, a5);

    Aluno *a6 = InicializaAluno(167, "baiano", 10.0);
    lista = insereLista(lista, a6);

    Aluno *a7 = InicializaAluno(172, "Bruno", 10.0);
    lista = insereLista(lista, a7);

    imprimeListaAlunos(lista);

    lista = retiraAluno(lista, 167);

    printf("\n---------------------------------\n\n");
    imprimeListaAlunos(lista);

    //Verificar se aluno esta na lista
    int i = pertenceAluno(lista, 1);
    if (i == 0)
    {
        printf("\nAluno esta na lista!\n");
    }
    else
    {
        printf("Aluno NAO esta na lista!\n");
    }

    //Retorna a media
    printf("\nA media da Turma é: %.2f\n", mediaTurma(lista)); // -->^Problema Valgrind

    liberaLista(lista);

    ApagaAluno(a1);
    ApagaAluno(a2);
    ApagaAluno(a3);
    ApagaAluno(a4);
    ApagaAluno(a5);
    ApagaAluno(a6);
    ApagaAluno(a7);

    return 0;
}
