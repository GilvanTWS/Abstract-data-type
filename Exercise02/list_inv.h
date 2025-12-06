#ifndef LISTA_INV_H
#define LISTA_INV_H

typedef struct no {
    int valor;
    struct no *prox;
} no;

typedef struct lista {
    no *inicio;
} lista;

void inicializar(lista *l);
void inserirfim(lista *l, int valor);
void imprimir(lista *l);
void imprimir_inv(lista *l);
void liberar(lista *l);

#endif
