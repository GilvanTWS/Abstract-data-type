#include <stdio.h>
#include "arquivo.h"
#include <math.h>
#include <stdlib.h>

struct No {
    float x;
    float y;
    struct No *prox;
};
typedef struct No no;

struct Lista {
    no *inicio;
};

lista* criar (float x, float y){
    lista *li= malloc(sizeof(lista));
    if(!li){
        printf("Erro na alocação de memoria\n");
        return NULL;
    }
    no *primeiro = malloc(sizeof(no));
    if(!primeiro){
        printf("Erro na alocação de memoria\n");
        return NULL;
    }

    primeiro->x = x;
    primeiro->y = y;
    primeiro->prox = NULL;
    li->inicio = primeiro;

    return li;
}

int exibir (lista *li){
    if(li == NULL){
        return 0;
    }
    no *aux = li->inicio;
    while(aux != NULL){
        printf("(%f, %f) ", aux->x, aux->y);
        aux = aux->prox;
    }
    printf("\n");
    return 1;
}

int inserirsemrepetir (lista *li, float x, float y){
    if(li == NULL){
        return 0;
    }
    no *aux = li->inicio;
    while(aux != NULL){
        if(aux->x == x && aux->y == y){
            return 0;
        }
        if(aux->prox == NULL) break;
        aux = aux->prox;
    }
    no *novo = malloc(sizeof(no));
    if (novo == NULL){
        return 0;
    }
    novo->x = x;
    novo->y = y;
    novo->prox = NULL;
    if (li->inicio == NULL){
        li->inicio = novo;
        return 1;
    }
    aux->prox = novo;
    return 1;
}
float distancia (lista *li, int i, int j){
    if (li == NULL){
        return -1;
    }
    no *aux1 = li->inicio;
    int count = 0;
    while (count < i){
        if(aux1==NULL){
            printf("Nao existe ponto de indice %d\n", i);
            return -1;
        }
        aux1 = aux1->prox;
        count++;
    }
    no *aux2 = li->inicio;
    count = 0;
    while (count < j){
        if(aux2==NULL){
            printf("Nao existe ponto de indice %d\n", j);
            return -1;
        }
        aux2 = aux2->prox;
        count++;
    }
    float distancia = sqrt(
    (aux2->x - aux1->x) * (aux2->x - aux1->x) +
    (aux2->y - aux1->y) * (aux2->y - aux1->y)
);
    return distancia;
}

int eliminePerto(lista *li, int i, float d) {
    if (li == NULL || li->inicio == NULL || i < 0) {
        return 0;
    }

    if (distancia(li, i, i) < 0) {
        return 0;
    }

    no *atual = li->inicio;
    no *ant = NULL;
    int idx = 0;

    while (atual != NULL) {
        float dist = distancia(li, i, idx);

        if (dist >= 0 && dist <= d) {
            if (ant == NULL) {
                li->inicio = atual->prox;
                free(atual);
                atual = li->inicio;
            } else {
                ant->prox = atual->prox;
                free(atual);
                atual = ant->prox;
            }

        } else {
            ant = atual;
            atual = atual->prox;
            idx++;
        }
    }

    return 1;
}
