#include <stdio.h>
#include <stdlib.h>

#ifndef CRIVO_H
#define CRIVO_H

typedef struct crivo Crivo;

Crivo *CriInit(int tam);
int* VetorPrimo(Crivo *base, int *tatata);
void LiberaCri(Crivo *base);

#endif