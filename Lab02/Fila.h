#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

#ifndef FILABST_H
#define FILABST_H

typedef struct fila Fila;
Fila *criaFila(int tamanho);
void insereFila(BST *inserido, Fila *Fila);
BST *popFila(Fila *Fila);
void liberaFila(Fila *Fila);

#endif