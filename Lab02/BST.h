#include <stdio.h>
#include <stdlib.h>

#ifndef BST_H
#define BST_H

typedef struct bst BST;

BST *CriaArvBin(int chave);
void InsereArvBin(int chave, BST *Arvore);
int getAlturaArvBin(BST *Arvore);
void ImprimeNo(BST *Arvore);
//Varredura
void rec_preOrder(BST *t, void (*visit)(BST*));
void rec_inOrder(BST *t, void (*visit)(BST*));
void rec_postOrder(BST *t, void (*visit)(BST*));

void LiberaArvBin(BST *liberada);

#endif