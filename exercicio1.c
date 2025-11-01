#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int *vetor;

    printf("Quantos números você quer digitar? ");
    scanf("%d", &n);

    vetor = (int*) malloc(n * sizeof(int));

    if (vetor == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Digite o número %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nNúmeros pares:\n");
    for (i = 0; i < n; i++) {
        if (vetor[i] % 2 == 0) {
            printf("%d\n", vetor[i]);
        }
    }

    free(vetor);

    return 0;
}

