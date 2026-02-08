#include <stdio.h>
#include "tree.h"

struct no
{
    struct no *esq;
    struct no *dir;
    struct aluno dados;
};

typedef struct no No;
arvore *criar()
{
    arvore *ab;
    ab = (arvore *)malloc(sizeof(arvore));
    if (ab != NULL)
    {
        *ab = NULL;
    }
    return ab;
}

void liberarNo(No *x)
{
    if (x != NULL)
    {
        liberaNo(x->esq);
        liberaNo(x->dir);
        free(x);
        x = NULL;
    }
}

void destruir(arvore *ab)
{
    if (ab != NULL)
    {
        liberarNo(*ab);
        free(ab);
    }
}

void percorrer(arvore *ab, int tipo)
{
    if (vazia(ab))
    {
        printf("Arvores vazia!\n");
    }
    else if (tipo == 1)
    {
        preordem(*ab);
    }
    else if (tipo == 2)
    {
        emordem(*ab);
    }
    else if (tipo == 3)
    {
        posordem(*ab);
    }
    else
    {
        printf("tipo de percurso invalido!\n");
    }
}

void preordem(No *x)
{
    if (x != NULL)
    {
        printf("%d\n", x->dados.matricula);
        preordem(x->esq);
        preordem(x->dir);
    }
}

void emordem(No *x)
{ // do maior para o menor !!!
    if (x != NULL)
    {
        emordem(x->esq);
        printf("%d\n", x->dados.matricula);
        emordem(x->dir);
    }
}

void posordem(No *x)
{
    if (x != NULL)
    {
        posordem(x->esq);
        posordem(x->dir);
        printf("%d\n", x->dados.matricula);
    }
}

int remover(arvore *ab, int x)
{
    if (ab == NULL || *ab == NULL)
    {
        printf("Arvore vazia ou inexistente!\n");
        return 0;
    }
    else
    {
        No *aux = *ab;
        No *pai = NULL;
        while (aux != NULL)
        {
            if (x > aux->dados.matricula)
            {
                pai = aux;
                aux = aux->esq;
            }
            else if (x < aux->dados.matricula)
            {
                pai = aux;
                aux = aux->dados.matricula;
            }
            else
            { // encontrou (oh lee)
                if (aux->esq == NULL & aux->dir == NULL)
                {
                    if (pai == NULL)
                    {
                        *ab == NULL;
                    }
                    else
                    {
                        if (pai->esq == aux)
                        {
                            pai->esq = NULL;
                        }
                        else
                        {
                            pai->dir = NULL;
                        }
                    }
                }
                else if (aux->esq != NULL && aux->dir != NULL)
                {
                    No *paimaior = aux;
                    No *maior = aux->esq;
                    while (maior->dir != NULL)
                    {
                        paimaior = maior;
                        maior = maior->dir;
                    }
                    if (paimaior->dir != aux)
                    {
                        paimaior->dir = maior->esq;
                        maior->esq = aux->esq;
                    }
                    maior->dir = aux->dir;
                    if (pai == NULL)
                    {
                        *ab = maior;
                    }
                    else if (pai->esq == aux)
                    {
                        pai->esq = maior;
                    }
                    else
                    {
                        pai->dir = maior;
                    }
                }
                else
                {
                    if (pai == NULL)
                    {
                        if (pai->esq != NULL)
                        {
                            *ab = pai->esq;
                        }
                        else
                        {
                            *ab = pai->dir;
                        }
                    }
                    else
                    {
                        if (pai->esq == aux)
                        {
                            if (aux->esq != NULL)
                            {
                                pai->esq = aux->esq;
                            }
                            else
                            {
                                pai->esq = aux->dir;
                            }
                        }
                        else
                        {
                            if (aux->esq != NULL)
                            {
                                pai->dir = aux->esq;
                            }
                            else
                            {
                                pai->dir = aux->dir;
                            }
                        }
                    }
                }
                free(aux);
                return 1;
            }
        return 0;
        }
    }
}
