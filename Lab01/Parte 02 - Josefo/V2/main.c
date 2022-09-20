#include "Roda.h"

int main()
{
    int n = 9, m = 5;

    Roda *Josephus = RodaInit(n);

    while (getTam(Josephus))
    {
        printf("%d, ", eliminaPessoa(Josephus, m));
    }

    LiberaRoda(Josephus);

    return 0;
}