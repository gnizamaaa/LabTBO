#include "item.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern void sort(Item *a, int lo, int hi);

int main(int argc, char *argv[])
{
    // int tam = (argv[1]);
    int tam = 5;

    Item *array = (Item *)malloc(sizeof(Item));

    for (int i = 0; i < tam; i++)
    {
        scanf("%i", &array[i]);
    }

    clock_t start = clock();
    // Algoritmo

    sort(array, 0, tam);

    clock_t end = clock();

    double seconds = ((double)end - start) / CLOCKS_PER_SEC;
    printf("%lf \n ", seconds);

    for (int i = 0; i < tam; i++)
    {
        printf("%i ", array[i]);
    }

    free(array);

    return 0;
}