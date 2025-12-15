#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"

struct No{
    int x;
    struct No *prox;
};
typedef struct No no;

struct Lista{
    no *inicio;
};

void criar(lista *li){
    if(!li){
        printf("Lista inexistente\n");
        return;
    }
    li->inicio = NULL;
}

void inserirfim(lista *li, int x){
    if(!li){
        printf("Lista inexistente\n");
        return;
    }
    no *novo = malloc(sizeof(no));
    if (!novo){
        printf("Erro na alocação de memoria\n");
        return;
    }
    novo->x = x;
    novo->prox = NULL;
    if(li->inicio == NULL){
        li->inicio = novo;
        return;
    }

    no *aux = li->inicio;
    while(aux->prox != NULL){
        aux = aux->prox;
    }
    aux->prox= novo;
}
void inserircomeco (lista *li, int x){
    if(!li){
        printf("Lista inexistente\n");
        return;
    }
    no *novo = malloc(sizeof(no));
    if(!novo){
        printf("Erro na alocação de memoria\n");
        return;
    }
    novo->x = x;
    novo->prox = li->inicio;
    li->inicio = novo;
}
void imprimirlista(lista *li){
    if(!li){
        printf("Lista inexistente\n");
        return;
    }
    no *aux = li->inicio;
    while(aux != NULL){
        printf("%d ", aux->x);
        aux = aux->prox;
    }
    printf("\n");
    return;
}
void liberar(lista *li){
    if(!li){
        printf("Lista inexistente\n");
        return;
    }

    no *aux = li->inicio;
    while(aux != NULL){
        no *prox = aux->prox;
        free(aux);
        aux = prox;
    }

    li->inicio = NULL;
}
