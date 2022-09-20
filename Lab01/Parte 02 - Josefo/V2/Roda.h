#include <stdio.h>
#include <stdlib.h>

#ifndef RODAJO_H
#define RODAJO_H

typedef struct roda Roda;

Roda *RodaInit(int tam);
int getTam(Roda* referencia);
int eliminaPessoa(Roda* josefo, int qtdSaltos);
void LiberaRoda(Roda *base);

#endif