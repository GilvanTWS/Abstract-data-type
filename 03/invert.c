#include <stdio.h>
#include "invert.h"
#include <stdlib.h>
struct No {
    int valor;
    struct No *prox;
};

typedef struct No no; 

struct Lista{
    no *inicio;
};

void inicializarlista(lista *l){
    l->inicio = NULL;
}

void inserirfim(lista *l, int valor){
    no *novo = malloc(sizeof(no));
    if(!novo){
        printf("Erro na alocação de memoria\n");
        return;
    }
    novo->valor = valor;
    novo->prox = NULL;
    if(l->inicio == NULL){ //cria uma lista com os inteiros digitados
        l->inicio = novo;
    }
    
}


void imprimirlista(lista *l){
    if (verificarvazia(l)){
        printf("Lista vazia\n");
        return;
    }
    no *aux = l->inicio;
    printf("Lista original: ");
    while(aux!=NULL){
        printf("%d", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
    
}

void liberar(lista *l){
    no *aux;
    while(l->inicio != NULL){
        aux = l->inicio;
        l->inicio = l->inicio->prox;
        free(aux);
    }
}
int verificarvazia (lista *l){
    if (l->inicio == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void inverterlista(lista *l){
    if(verificarvazia(l)){
        printf("Lista vazia\n");
        return;
    }
    no *anterior = NULL;
    no *atual = l->inicio;
    no *proximo = NULL;

    while(atual != NULL){
        proximo = atual->prox;
        atual->prox = anterior;
        anterior =  atual;
        atual = proximo;
        l->inicio = anterior;
    }
    
}


