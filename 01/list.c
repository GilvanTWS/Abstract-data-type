#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void incializarlista(lista *l){
    l->inicio = NULL;
}

int inserirfim(lista *l, int valor){
    no *novo = malloc(sizeof(no));
    if(!novo){
        printf("Erro na alocação de memoria!\n");
        return 0;
    }
    novo->valor = valor;
    novo->prox = NULL;
    if(l->incicio == NULL){
        l->inicio = novo;
        return 1;
    }
    no *aux = l->inicio;
    while (aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox = novo;
    return 1;
}

int imprimirlista(lista *l){
    if (l->inicio == NULL){
        return 0;
    }
    no *aux = l->inicio;
    printf("Lista: \n");
    while (aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
    return 1;
}