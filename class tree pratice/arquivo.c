#include <stdio.h>
#include "arquivo.h"

struct no{
    struct no *esq;
    struct no *dir;
    struct aluno dados;
};
typedef struct no No;

arvore* criar(){
    arvore *ab;
    ab = (arvore*)malloc(sizeof(arvore));
    if(ab != NULL){
        ab = NULL;
    }
    return ab;
}

int inserir(arvore *ab, struct aluno novosdados){
    if(ab == NULL){ //  ab-> ab* -> (restante da arvore)
        return 0;   // ab == NULL (nao existe arvore);
    }               // ab* == NULL (arvore vazia)
    No* novo = (No*)malloc(sizeof(No));
    if(novo == NULL){
        return 0;
    }
    novo->dados = novosdados;
    novo->esq = NULL;
    novo->dir = NULL;
    if (*ab == NULL){
        *ab = novo;
    }
    else{
        No *aux = *ab;
        No *pai;
        while(aux!= NULL){
            pai = aux;
            if(novosdados.matricula < pai->dados.matricula){
                aux = aux->esq;
            }
            else if(novosdados.matricula > pai->dados.matricula){
                aux= aux->dir;
            }
            else{
                printf("Aluno '%d' ja existe na arvre\n", novosdados.matricula);
                free(novo);
                return 0;
            }
        }
        if(novosdados.matricula < pai->dados.matricula){
            pai->esq = novo;
        }
        else{
            pai->dir = novo;
        }
    }
    printf("O aluno de matricula '%d' foi adicionado com sucesso!\n", novosdados.matricula);
    return 1;
}

void preordem(No *x){
    printf("%d", x->dados.matricula);
    preordem(x->esq);
    preordem(x->dir);
}

void acessar(arvore *ab, int matricula){
    if(ab == NULL){
        return; //arvore inexistente
    }
                                                                                                                                                //eu sou gay
    No *aux = *ab;
    while(aux != NULL){
        if(matricula < aux->dados.matricula){
            aux = aux->esq;
        }
        else if( matricula > aux->dados.matricula){
            aux = aux->esq;
        }
        else{
            printf("Este estudante esta na arvore\n");
            return;
        }
    }
    printf("O estudante nao esta na arvore\n");
    return;
}

