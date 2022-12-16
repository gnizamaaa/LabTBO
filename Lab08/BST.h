#include <stdio.h>
#include <stdlib.h>

#ifndef BST_H
#define BST_H

typedef struct bst BST;

BST *CriaArvBin(int chave);
void InsereArvBin(int chave, BST *Arvore);
BST *InsereArvRot(int chave, BST *Arv);
BST *rotate_left(BST *n);
BST *rotate_right(BST *n);
BST *particionamento(BST *Arv, int chave);

int getAlturaArvBin(BST *Arvore);
void ImprimeNo(BST *Arvore);
// Varredura
void rec_preOrder(BST *t, void (*visit)(BST *));
void rec_inOrder(BST *t, void (*visit)(BST *));
void rec_postOrder(BST *t, void (*visit)(BST *));
void rec_levelOrder(BST *t, void (*visit)(BST *));

void LiberaArvBin(BST *liberada);

#endif