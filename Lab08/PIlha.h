#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

#ifndef PILHABST_H
#define PILHABST_H

typedef struct pilha Pilha;

Pilha *criaPilha(int tamanho);
void inserePilha(BST *inserido, Pilha* pilha);
BST *popPilha(Pilha *pilha);
void liberaPilha(Pilha *pilha);

#endif