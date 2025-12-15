#ifndef lista_h
#define lista_h

typedef struct Lista lista;

void criar(lista *li);
void inserirfim(lista *li, int x);
void inserircomeco(lista *li, int c);
void imprimirlista(lista *li);
void liberar(lista *li);

#endif
