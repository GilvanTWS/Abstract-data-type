#ifndef LISTA_H
#define LISTA_H

typedef struct no {
    int valor;
    struct no *prox;
};

typedef struct lista{
    no *inicio;
};

void incializarlista(lista *l);
int inserirfim(lista *l, int valor);
int imprimirlista(lista *l);
void liberar(lista *l);
#endif