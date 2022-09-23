#include "BST.h"

int main()
{
    BST *arv = CriaArvBin(10);

    InsereArvBin(5, arv);
    InsereArvBin(6, arv);
    InsereArvBin(11, arv);
    InsereArvBin(4, arv);
    InsereArvBin(5, arv);

    LiberaArvBin(arv);
    return 0;
}