#include "Fila.h"
#include "BST.h"

struct fila
{
    BST **vetor;
    int MAX;
    int tamAtual;
    int prim;
    int ult;
};

Fila *criaFila(int tamanho)
{
    Fila *saida = (Fila *)malloc(sizeof(Fila));
    saida->vetor = malloc(sizeof(BST *) * tamanho);
    saida->tamAtual = 0;
    saida->MAX = tamanho;
    saida->prim = 0;
    saida->ult = 0;
    return saida;
}
void insereFila(BST *inserido, Fila *Fila)
{
    // // Se estiver no final do vetor
    // if (Fila->ult == Fila->MAX - 1)
    // {
    //     Fila->ult = -1;
    // }

    Fila->ult = (Fila->ult + 1) % Fila->MAX;
    Fila->vetor[Fila->ult] = inserido;
    Fila->tamAtual++;
}
BST *popFila(Fila *Fila)
{
    if (Fila->tamAtual > 0)
    {
        BST *saida = Fila->vetor[Fila->prim + 1];
        Fila->prim = (Fila->prim + 1) % Fila->MAX;
        Fila->tamAtual--;
        return saida;
    }
    else
        return NULL;
}

int estaVazia(Fila *fila)
{
    return fila->tamAtual == 0;
}
void liberaFila(Fila *Fila)
{
    free(Fila->vetor);
    free(Fila);
}
