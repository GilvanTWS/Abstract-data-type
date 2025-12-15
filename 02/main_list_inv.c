#include <stdio.h>
#include "list_inv.h"
int main(int argc, char const *argv[])
{
    lista l;
    inicializar(&l);
    inserirfim(&l, 50);
    inserirfim(&l, 10);
    inserirfim(&l,70);
    imprimir(&l);
    imprimir_inv(&l);
    liberar(&l);
    return 0;
}
