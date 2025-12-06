#include <stdio.h>
#include <stdlib.h>
#include "list_inv.h"

void inicializar(lista *l){
    l->inicio = NULL;
}

void inserirfim(lista *l, int valor){
    no *novo = malloc(sizeof(no));
    if (!novo){
        printf("Erro na alocação de memoria\n");
        return;
    }

    novo->valor = valor;
    novo->prox = NULL;

    if(l->inicio == NULL){
        l->inicio = novo;  
        return;
    }

    no *aux = l->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = novo;
}

void imprimir(lista *l){
    if(l->inicio == NULL){
        printf("Lista vazia\n");
        return;
    }

    no *aux = l->inicio;
    printf("Lista: ");
    while(aux != NULL){
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
}

void imprimir_inv(lista *l){
    if(l->inicio == NULL){
        printf("Lista vazia\n");
        return;
    }

    no *aux = l->inicio;  
    int tamanho = 0;

    while (aux != NULL){
        tamanho++;
        aux = aux->prox;
    }

    int *pilha = malloc(tamanho * sizeof(int));
    int topo = 0;

    aux = l->inicio;

    while (aux != NULL){
        pilha[topo++] = aux->valor;
        aux = aux->prox;
    }

    while(topo > 0){
        printf("%d ", pilha[--topo]); 
    }
    printf("\n");

    free(pilha);
}

void liberar(lista *l){
    no *aux;
    while(l->inicio != NULL){
        aux = l->inicio;
        l->inicio = l->inicio->prox;
        free(aux);
    }
}
