#include <stdio.h>
#include <stdlib.h>

#ifndef BST_H
#define BST_H

typedef struct bst BST;

BST *CriaArvBin(int chave);
void InsereArvBin(int chave, BST *Arvore);
void LiberaArvBin(BST *liberada);

#endif