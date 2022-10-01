#include "item.h"

extern void sort(Item *a, int lo, int hi)
{
    while (1)
    {
        int trocoudentro = 0;
        for (int j = 1; j < hi; j++)
        {
            if (less(a[j], a[j - 1]))
            {
                exch(a[j], a[j - 1]);
                trocoudentro++;
            }
        }
        if (!trocoudentro)
            break;
    }
}