#include "Crivo.h"

int main()
{
    int numero;
    // scanf("%d", &numero);
    Crivo *sieve = CriInit(9999);
    int tam = 0;
    int *vetor = VetorPrimo(sieve, &tam);

    // for (int i = 0; i < tam; i++, printf(", "))
    // {
    //     printf("%d", vetor[i]);
    // }
    // printf("\n");

    LiberaCri(sieve);
    free(vetor);
    return 0;
}