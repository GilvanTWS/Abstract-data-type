#include <stdio.h>
#include "tree.h"

struct no{
    struct no *esq;
    struct no *dir;
    struct aluno dados;
};

typedef struct no No;
arvore* criar(){
    arvore *ab;
    ab = (arvore*)malloc(sizeof(arvore));
    if(ab!=NULL){
        *ab =NULL;
    }
    return ab;

}

void liberarNo(No *x){
    if(x != NULL){
        liberaNo(x->esq);
        liberaNo(x->dir);
        free(x);
        x= NULL;
    }
}

void destruir(arvore *ab){
    if(ab != NULL){
        liberarNo(*ab);
        free(ab);
    }
}

void percorrer(arvore *ab, int tipo){
    if(vazia(ab)){
        printf("Arvores bazia!\n");
    }
    else if(tipo == 1){
        preordem(*ab);
    }
    else if(tipo == 2){
        emordem(*ab);
    }
    else if(tipo == 3){
        posordem(*ab);
    }
    else{
        printf("tipo de percurso invalido!\n");
    }
}

void preordem(No *x){
    if( x != NULL){
        printf("%d\n", x->dados.matricula);
        preordem(x->esq);
        preordem(x->dir);
    }
}

void emordem(No *x){
    if(x != NULL){
        emordem(x->esq);
        printf("%d\n", x->dados.matricula);
        emordem(x->dir);
    }
}

void posordem(No *x){
    if (x != NULL){
        posordem(x->esq);
        posordem(x->dir);
        printf("%d\n", x->dados.matricula);
    }
}


