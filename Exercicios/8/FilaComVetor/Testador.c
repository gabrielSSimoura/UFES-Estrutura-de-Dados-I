#include <stdio.h>
#include <stdlib.h>

#include "Fila.h"
#include "aluno.h"

int main(int argc, char **argv)
{
    Aluno *a1 = InicializaAluno(1233, "a1", 9.98);
    Aluno *a2 = InicializaAluno(2434, "a2", 1);
    Aluno *a3 = InicializaAluno(444, "a3", 8.93);
    Aluno *a4 = InicializaAluno(25432, "a4", 7.3);

    Fila *f1 = InicializaFila();
    Fila *f2 = InicializaFila();

    InsereFila(f1, a1);
    InsereFila(f1, a2);
    InsereFila(f1, a3);
    InsereFila(f1, a4);

    printf("Fila 1: \n");
    ImprimeFila(f1);

    InsereFila(f2, RetiraFila(f1));
    InsereFila(f2, RetiraFila(f1));

    printf("Fila 1: \n");
    ImprimeFila(f1);

    printf("Fila 2: \n");
    ImprimeFila(f2);

    ApagaAluno(a1);
    ApagaAluno(a2);
    ApagaAluno(a3);
    ApagaAluno(a4);
    DestroiFila(f1);
    DestroiFila(f2);

    return 0;
}