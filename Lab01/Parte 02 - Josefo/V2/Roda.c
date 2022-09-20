#include "Roda.h"

struct roda
{
    char *vetor;
    int tam;
    int qntElem;
    int atual;
};

Roda *RodaInit(int tam)
{
    Roda *saida = (Roda *)malloc(sizeof(Roda));
    saida->vetor = (char *)calloc(tam, sizeof(char));
    saida->tam = tam;
    saida->qntElem = tam;
    saida->atual = 0;
}
int getTam(Roda *referencia) { return referencia->qntElem; }
int eliminaPessoa(Roda *josefo, int qtdSaltos)
{
    int eliminado = josefo->atual;
    int saltosReais = -1;

    while (qtdSaltos)
    {
        saltosReais++;
        while (josefo->vetor[(josefo->atual + saltosReais) % josefo->tam])
        {
            saltosReais++;
        }
        qtdSaltos--;
    }

    josefo->vetor[(josefo->atual + saltosReais) % josefo->tam] = 1;
    josefo->qntElem--;
    eliminado = (josefo->atual + saltosReais) % josefo->tam + 1;

    josefo->atual = ((josefo->atual + saltosReais) % josefo->tam) + 1;
    while (josefo->qntElem && josefo->vetor[josefo->atual] == 1)
    {
        josefo->atual = (josefo->atual + 1) % josefo->tam;
    }

    return eliminado;
}
void LiberaRoda(Roda *base)
{
    free(base->vetor);
    free(base);
}