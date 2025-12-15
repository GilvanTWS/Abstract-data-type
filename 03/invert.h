#ifndef lista_h
#define lista_h



typedef struct Lista lista;

void inicializarlista(lista *l);

void inserirfim(lista *l, int valor);

void imprimirlista(lista *l);

void inverterlista(lista *l);

int verificarvazia(lista *l);

void liberar(lista *l);

#endif
/*
no *anterior = NULL;
    no *atual = l->inicio;
    no *proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;  // salva o próximo nó
        atual->prox = anterior; // inverte o ponteiro
        anterior = atual;       // avança o "anterior"
        atual = proximo;        // avança o "atual"
    }
*/