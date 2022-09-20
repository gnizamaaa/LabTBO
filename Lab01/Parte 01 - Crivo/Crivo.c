#include "Crivo.h"

struct crivo
{
    int *vetInterno;
    int QtdPrimos;
    int tamanhoVet;
};

Crivo *CriInit(int tam)
{
    Crivo *nouveau = malloc(sizeof(Crivo));
    nouveau->vetInterno = calloc(tam + 1, sizeof(int));

    nouveau->vetInterno[0] = 1;
    nouveau->vetInterno[1] = 1;

    nouveau->tamanhoVet = tam;
    nouveau->QtdPrimos = 0;
    return nouveau;
}

int *VetorPrimo(Crivo *base, int *tatata)
{
    for (int i = 0; i <= base->tamanhoVet; i++)
    {
        // Se nao eh multiplo de nenhum anterior
        if (base->vetInterno[i] == 0)
        {
            // Tira todos os multiplos
            for (int j = 2 * i; j <= base->tamanhoVet; j += i)
            {
                base->vetInterno[j] = 1;
            }
            base->QtdPrimos++;
        }
    }

    int *vet = calloc((base->QtdPrimos), sizeof(int));

    for (int i = 0, j = 0; i <= base->tamanhoVet; i++)
    {
        if (base->vetInterno[i] == 0)
        {
            vet[j] = i;
            j++;
        }
    }
    (*tatata) = base->QtdPrimos;
    return vet;
}
void LiberaCri(Crivo *base)
{
    free(base->vetInterno);
    free(base);
}
