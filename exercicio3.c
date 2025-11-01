#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int qtd_itens = 2;                 
    char entrada[50];                 
    char (*compras)[50] = malloc(qtd_itens * sizeof(*compras)); 

    if (compras == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("Digite os 2 primeiros produtos da sua lista de compras:\n");
    for (int i = 0; i < qtd_itens; i++) {
        printf("Produto %d: ", i + 1);
        scanf("%s", compras[i]);
    }

    while (1) {
        printf("Digite outro produto (ou 'fim' para encerrar): ");
        scanf("%s", entrada);

        if (strcmp(entrada, "fim") == 0) {
            break;
        }

        qtd_itens++;
        compras = realloc(compras, qtd_itens * sizeof(*compras));

        if (compras == NULL) {
            printf("Erro ao realocar memória.\n");
            return 1;
        }

        strcpy(compras[qtd_itens - 1], entrada);
    }

    printf("\nLista final de compras:\n");
    for (int i = 0; i < qtd_itens; i++) {
        printf("%s\n", compras[i]);
    }

    free(compras);
    return 0;
}

