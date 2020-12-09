#include <stdio.h>
#include "professor.h"
#include "aluno.h"
#include "lista.h"

int main(int argc, const char *argv[])
{
    // Criar os Alunos
    Aluno *Gabriel = IniciaAluno(248, "Gabriel", 10);
    Aluno *Andre = IniciaAluno(208, "Andre", 10);
    Aluno *Maria = IniciaAluno(28, "Maria", 10);
    Aluno *Emerson = IniciaAluno(234, "Emerson", 10);

    // Criar os Professor
    Professor *p1 = IniciaProfessor(3456, "P1", 4566.20);
    Professor *p2 = IniciaProfessor(36, "P2", 456446.20);
    Professor *p3 = IniciaProfessor(134, "P3", 4564326.20);

    // Criar Lista
    Lista *lista = IniciaLista();

    // Insere Aluno e Professor
    InsereAluno(lista, Gabriel);
    InsereProfessor(lista, p1);
    InsereAluno(lista, Andre);
    InsereProfessor(lista, p2);
    InsereAluno(lista, Maria);
    InsereAluno(lista, Emerson);
    InsereProfessor(lista, p3);

    // Retira da Lista
    RetiraLista(lista, RetornaNomeAluno(Gabriel));
    RetiraLista(lista, RetornaNomeProfessor(p3));
    RetiraLista(lista, RetornaNomeProfessor(p3));
    RetiraLista(lista, RetornaNomeAluno(Emerson));

    // Imprimir a lista
    printf("Imprimindo a lista: \n");
    ImprimeLista(lista);

    // Valor do Churrasco
    printf("Valor do Churrasco: %.2f\n", ValorChurrasco(lista));

    // Liberando Memoria da Lista
    ApagaLista(lista);

    // Liberando Memoria Alunos
    ApagaAluno(Gabriel);
    ApagaAluno(Andre);
    ApagaAluno(Maria);
    ApagaAluno(Emerson);

    // Liberando Memoria Professor
    ApagaProfessor(p1);
    ApagaProfessor(p2);
    ApagaProfessor(p3);

    return 0;
}