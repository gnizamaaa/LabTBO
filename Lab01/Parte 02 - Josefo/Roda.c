#include "Roda.h"

typedef struct celula Celula;

struct celula
{
    int num;
    Celula *prox;
};

struct roda
{
    Celula *inicio;
    Celula *fim;
    int tam;
    int atual;
};

Roda *RodaInit(int tam)
{
    Roda *saida = (Roda *)malloc(sizeof(Roda));
    saida->inicio = NULL;
    saida->fim = NULL;
    saida->tam = 0;
    saida->atual = 1;

    //
    for (int i = tam; i > 0; i--)
    {
        Celula *inserida = (Celula *)malloc(sizeof(Celula));
        inserida->num = i;
        inserida->prox = saida->inicio;

        if (!saida->inicio)
        {
            saida->inicio = inserida;
            saida->fim = inserida;
        }
        else
        {
            saida->inicio = inserida;
        }
        saida->tam++;
    }

    return saida;
}
int getTam(Roda *referencia) { return referencia->tam; }
int eliminaPessoa(Roda *josefo, int qtdSaltos)
{
    int reaisSaltos = abs(qtdSaltos % josefo->tam);

    Celula *ant = josefo->fim, *atual = josefo->inicio;

    // Retorna onde estava
    while (atual->num != josefo->atual)
    {
        ant = atual;
        atual = atual->prox;
    }

    // Faz os saltos
    for (int i = 0; i < qtdSaltos - 1; i++)
    {
        if (atual->prox)
        {
            ant = atual;
            atual = atual->prox;
        }
        else
        {
            ant = josefo->fim;
            atual = josefo->inicio;
        }
    }

    if (atual->prox)
        josefo->atual = atual->prox->num;
    else
        josefo->atual =josefo->inicio->num;

    // Libera a pessoa
    int id = atual->num;
    if (josefo->inicio == atual) // Se eh o primeiro el
    {
        josefo->inicio = atual->prox;
        if (atual->prox == NULL) // Se tbm eh o ultimo el
            josefo->fim = NULL;
    }
    else
    {
        if (ant) // Meio da lista
            ant->prox = atual->prox;
        if (!atual->prox) // Ultimo el
            josefo->fim = ant;
    }

    if (atual)
    {
        free(atual);
        josefo->tam--;
    }

    return id;
}
void LiberaRoda(Roda *base)
{
    // Libera celulas
    Celula *prox;
    while (base->inicio)
    {
        prox = base->inicio->prox;
        free(base->inicio);
        base->inicio = prox;
    }

    free(base);
}