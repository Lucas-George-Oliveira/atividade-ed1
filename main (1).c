
#include <stdio.h>
#include "duplalista.h"

int main() {
    Lista *lista = criarLista();
    int opcao, valor, pos;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Inserir elemento\n");
        printf("2. Remover elemento\n");
        printf("3. Encontrar por valor\n");
        printf("4. Encontrar por posição\n");
        printf("5. Mostrar lista\n");
        printf("6. Destruir lista\n");
        printf("7. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        if (opcao == 7) break;

        switch (opcao) {
            case 1:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                printf("Posição (0=início, meio=%d, fim=%d): ", lista->tamanho/2, lista->tamanho);
                scanf("%d", &pos);
                inserirPosicao(lista, valor, pos);
                break;

            case 2:
                printf("Posição para remover (0=início, meio=%d, fim=%d): ", lista->tamanho/2, lista->tamanho-1);
                scanf("%d", &pos);
                removerPosicao(lista, pos);
                break;

            case 3:
                printf("Digite o valor: ");
                scanf("%d", &valor);
                encontrarPorValor(lista, valor);
                break;

            case 4:
                printf("Digite a posição: ");
                scanf("%d", &pos);
                encontrarPorPosicao(lista, pos);
                break;

            case 5:
                mostrarLista(lista);
                break;

            case 6:
                destruirLista(lista);
                lista = criarLista();
                break;

            default:
                printf("Opção inválida.\n");
        }
    }

    destruirLista(lista);
    return 0;
}
