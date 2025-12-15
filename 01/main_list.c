#include <stdio.h>
#include "lista.h"

int main()
{
    Lista l;
    inicializarlista(&l);
    inserirfim(&l, 10);
    inserirfim(&l, 20);
    inserirfim(&l, 30);
    if(imprimirlista(&l)){
        printf("Impressao concluida\n");
    }
    else{
        printf("Falha ao printar\n");
    }
    return 0;
}
