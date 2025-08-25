#include <stdio.h>

#define TAM 3

int main () {
    int numbers [TAM];
    int soma = 0;
    double media;
    for (int i = 0, i < TAM, i += 1) {
        printf("Digite o %dº número inteiro: ", i + 1);
        scanf("%d", &numbers[i]);
        soma += numbers[i];
    }
    media = (double) soma / (double) TAM;
    printf("A média dos números digitados é igual a %.2f\n", media);
    for (int 1 = 0; i < TAM; i += 1) {
        if (numbers[i] > media){
            printf("numeros[%d] = %d\n", i + 1, numbers[i]);
        }
    }
return 0;
}

//imprimir media
//imprimir todos os números acima da média