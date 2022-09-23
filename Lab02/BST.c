#include "BST.h"

struct bst
{
    int chave;
    BST *esq;
    BST *dir;
};

BST *CriaArvBin(int chave)
{
    BST *saida = (BST *)malloc(sizeof(BST));
    saida->chave = chave;
    saida->dir = NULL;
    saida->esq = NULL;
}
void InsereArvBin(int chave, BST *Arvore)
{
    if (Arvore->chave > chave)
    {
        if (Arvore->esq)
            InsereArvBin(chave, Arvore->esq);
        else
            Arvore->esq = CriaArvBin(chave);
    }
    else if (Arvore->chave < chave)
    {
        if (Arvore->dir)
            InsereArvBin(chave, Arvore->dir);
        else
            Arvore->dir = CriaArvBin(chave);
    }
}
void LiberaArvBin(BST *liberada)
{
    if (liberada)
    {
        if (liberada->dir || liberada->esq) //Eh no no meio da arvore
        {
            LiberaArvBin(liberada->dir);
            LiberaArvBin(liberada->esq);
            free(liberada);
        }
        else //Eh folha
        {
            free(liberada);
        }
    }
}
