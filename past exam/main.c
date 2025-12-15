#include <stdio.h>
#include "arquivo.h"

void menu() {
    printf("\n====== MENU ======\n");
    printf("1 - Criar lista (primeiro ponto)\n");
    printf("2 - Inserir ponto (sem repetir)\n");
    printf("3 - Exibir pontos\n");
    printf("4 - Distancia entre dois pontos\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
}

int main() {
    lista *li = NULL;
    int opcao;
    float x, y;
    int i, j;

    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                if (li != NULL) {
                    printf("Lista ja criada!\n");
                    break;
                }
                printf("Digite x e y: ");
                scanf("%f %f", &x, &y);
                li = criar(x, y);
                if (li == NULL)
                    printf("Erro ao criar a lista\n");
                else
                    printf("Lista criada com sucesso!\n");
                break;

            case 2:
                if (li == NULL) {
                    printf("Crie a lista primeiro!\n");
                    break;
                }
                printf("Digite x e y: ");
                scanf("%f %f", &x, &y);
                if (inserirsemrepetir(li, x, y))
                    printf("Ponto inserido!\n");
                else
                    printf("Ponto repetido ou erro!\n");
                break;

            case 3:
                if (li == NULL) {
                    printf("Lista nao criada!\n");
                } else {
                    exibir(li);
                }
                break;

            case 4:
                if (li == NULL) {
                    printf("Lista nao criada!\n");
                    break;
                }
                printf("Digite os indices i e j: ");
                scanf("%d %d", &i, &j);
                float d = distancia(li, i, j);
                if (d < 0)
                    printf("Erro no calculo da distancia\n");
                else
                    printf("Distancia = %.2f\n", d);
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    return 0;
}
