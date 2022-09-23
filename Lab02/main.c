#include "BST.h"
#include <time.h>
#include <stdlib.h>

int main()
{
    BST *arv;

    // InsereArvBin(5, arv);
    // InsereArvBin(6, arv);
    // InsereArvBin(11, arv);
    // InsereArvBin(4, arv);
    // InsereArvBin(5, arv);

    // printf("%i", getAlturaArvBin(arv));

    srand(time(NULL)); // should only be called once

    // for (int j = 0; j < 10; j++)
    // {
    //     arv = CriaArvBin(rand());
    //     for (int i = 0; i < 1000000; i++)
    //     {
    //         int r = rand(); // returns a pseudo-random integer between 0 and RAND_MAX
    //         InsereArvBin(r, arv);
    //     }
    //     printf("%i ", getAlturaArvBin(arv));
    //     LiberaArvBin(arv);
    // }

    arv = CriaArvBin(rand());
    for (int i = 0; i < 10; i++)
    {
        int r = rand(); // returns a pseudo-random integer between 0 and RAND_MAX
        InsereArvBin(r, arv);
    }
    printf("\n%i\n", getAlturaArvBin(arv));

    rec_preOrder(arv, ImprimeNo);
    printf("\n");
    rec_inOrder(arv, ImprimeNo);
    printf("\n");
    rec_postOrder(arv, ImprimeNo);
    printf("\n");

    LiberaArvBin(arv);

    return 0;
}