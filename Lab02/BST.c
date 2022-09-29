#include "BST.h"
#include "Fila.h"

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

int getAlturaArvBin(BST *arvore)
{
    if (arvore)
        if (arvore->esq || arvore->dir)
        {
            int esq = getAlturaArvBin(arvore->esq);
            int dir = getAlturaArvBin(arvore->dir);
            if (esq > dir)
                return esq + 1;
            else
                return dir + 1;
        }
        else
            return 0;
    else
        return -1;
}

void ImprimeNo(BST *Arvore)
{
    if (Arvore)
        printf("%i ", Arvore->chave);
}
// Varredura
void rec_preOrder(BST *t, void (*visit)(BST *))
{
    visit(t);
    if (t->esq)
        rec_preOrder(t->esq, visit);
    if (t->dir)
        rec_preOrder(t->dir, visit);
}
void rec_inOrder(BST *t, void (*visit)(BST *))
{
    if (t->esq)
        rec_inOrder(t->esq, visit);
    visit(t);
    if (t->dir)
        rec_inOrder(t->dir, visit);
}
void rec_postOrder(BST *t, void (*visit)(BST *))
{
    if (t->esq)
        rec_postOrder(t->esq, visit);
    if (t->dir)
        rec_postOrder(t->dir, visit);
    visit(t);
}

void rec_levelOrder(BST *t, void (*visit)(BST *))
{
    Fila *filaexec = criaFila(9999);
    BST *temp = t;
    while (temp)
    {
        visit(temp);
        if (temp->esq)
            insereFila(temp->esq, filaexec);
        if (temp->dir)
            insereFila(temp->dir, filaexec);

        temp = popFila(filaexec);
    }

    liberaFila(filaexec);
}

void LiberaArvBin(BST *liberada)
{
    if (liberada)
    {
        if (liberada->dir || liberada->esq) // Eh no no meio da arvore
        {
            LiberaArvBin(liberada->dir);
            LiberaArvBin(liberada->esq);
            free(liberada);
        }
        else // Eh folha
        {
            free(liberada);
        }
    }
}
