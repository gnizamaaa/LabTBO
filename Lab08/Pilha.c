#include "PIlha.h"
#include "BST.h"

struct pilha
{
    BST **vetor;
    int MAX;
    int tamAtual;
};

Pilha *criaPilha(int tamanho)
{
    Pilha *saida = (Pilha *)malloc(sizeof(Pilha));
    saida->vetor = malloc(sizeof(BST *) * tamanho);
    saida->tamAtual = 0;
    saida->MAX = tamanho;
    return saida;
}
void inserePilha(BST *inserido, Pilha *pilha)
{
    if (pilha->tamAtual < pilha->MAX)
    {
        pilha->vetor[pilha->tamAtual] = inserido;
        pilha->tamAtual++;
    }
}
BST *popPilha(Pilha *pilha)
{
    if (pilha->tamAtual > 0)
    {
        BST *saida = pilha->vetor[pilha->tamAtual - 1];
        pilha->tamAtual--;
        return saida;
    }
    else
        return NULL;
}
void liberaPilha(Pilha *pilha)
{
    free(pilha->vetor);
    free(pilha);
}
