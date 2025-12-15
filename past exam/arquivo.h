#ifndef lista_h
#define lista_h

typedef struct Lista lista;

lista* criar (float x, float y);
int exibir (lista *l);
int inserirsemrepetir (lista *l, float x, float y);
float distancia (lista *l, int i, int j);
int elimineperto(lista *li, int i, float d);


#endif