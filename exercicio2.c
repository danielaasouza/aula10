#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1, n2, i;
    int *v1, *v2, *v3;

    printf("Tamanho do primeiro vetor: ");
    scanf("%d", &n1);
    printf("Tamanho do segundo vetor: ");
    scanf("%d", &n2);

    v1 = (int*) malloc(n1 * sizeof(int));
    v2 = (int*) malloc(n2 * sizeof(int));

    if (v1 == NULL || v2 == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    printf("\nPreenchendo o primeiro vetor:\n");
    for (i = 0; i < n1; i++) {
        printf("v1[%d] = ", i);
        scanf("%d", &v1[i]);
    }

    printf("\nPreenchendo o segundo vetor:\n");
    for (i = 0; i < n2; i++) {
        printf("v2[%d] = ", i);
        scanf("%d", &v2[i]);
    }

    v3 = (int*) malloc((n1 + n2) * sizeof(int));
    if (v3 == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    for (i = 0; i < n1; i++) v3[i] = v1[i];
    for (i = 0; i < n2; i++) v3[n1 + i] = v2[i];

    printf("\nVetor concatenado:\n");
    for (i = 0; i < n1 + n2; i++) {
        printf("%d ", v3[i]);
    }

    free(v1);
    free(v2);
    free(v3);

    return 0;
}

