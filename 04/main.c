#include <stdio.h>
#include "arquivo.h"
int main()
{
    lista *li;
    criar(li);
    inserirfim(li, 1);
    inserirfim(li, 2);
    inserirfim(li, 3);
    inserirfim(li, 4);
    imprimirlista(li);
    inserircomeco(li, 5);
    imprimirlista(li);
    liberar(li);


    
    return 0;
}
