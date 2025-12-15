#include <stdio.h>
#include "invert.h"
int main()
{
    lista *l;
    inicializarlista(l);
    inserirfim(l, 20);
    inserirfim(l, 13);
    inserirfim(l, 1);
    inserirfim(l, 3);
    imprimirlista(l);
    inverterlista(l);
    imprimirlista(l);
    liberar(l);
    return 0;
}
