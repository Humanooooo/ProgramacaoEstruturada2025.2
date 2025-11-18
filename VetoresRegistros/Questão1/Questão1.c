#include <stdio.h>
#include <string.h>

#define TAM_ESTADOS 26

typedef struct {
    char nome[30];
    int veiculos;
    int acidentes;
} Estado;

void coletarDados(Estado vet[]) {
    int i;
    for (i = 0; i < TAM_ESTADOS; i++) {
        printf("\n--- Estado %d ---\n", i + 1);

        printf("Nome do estado: ");
        fflush(stdin); 
        fgets(vet[i].nome, 30, stdin);

        vet[i].nome[strcspn(vet[i].nome, "\n")] = '\0';

        printf("Numero de veiculos (2007): ");
        scanf("%d", &vet[i].veiculos);

        printf("Numero de acidentes (2007): ");
        scanf("%d", &vet[i].acidentes);

        getchar(); 
    }
}

void maiorMenorAcidentes(Estado vet[], int *indMenor, int *indMaior) {
    int i;

    *indMenor = 0;
    *indMaior = 0;

    for (i = 1; i < TAM_ESTADOS; i++) {
        if (vet[i].acidentes < vet[*indMenor].acidentes) {
            *indMenor = i;
        }
        if (vet[i].acidentes > vet[*indMaior].acidentes) {
            *indMaior = i;
        }
    }
}

float percentual(Estado vet[], int i) {
    if (vet[i].veiculos == 0) return 0;
    return ( (float)vet[i].acidentes / vet[i].veiculos ) * 100.0;
}

float mediaAcidentes(Estado vet[]) {
    int i;
    int soma = 0;

    for (i = 0; i < TAM_ESTADOS; i++) {
        soma += vet[i].acidentes;
    }

    return (float)soma / TAM_ESTADOS;
}

void acimaDaMedia(Estado vet[], float media) {
    int i;

    printf("\nEstados acima da media nacional de acidentes:\n");

    for (i = 0; i < TAM_ESTADOS; i++) {
        if (vet[i].acidentes > media) {
            printf("- %s (%d acidentes)\n", vet[i].nome, vet[i].acidentes);
        }
    }
}

int main() {

    Estado cad[TAM_ESTADOS];
    int indMenor, indMaior;
    int i;
    float media;

    coletarDados(cad);

    maiorMenorAcidentes(cad, &indMenor, &indMaior);

    printf("\n\n--- MAIOR E MENOR NUMERO DE ACIDENTES ---\n");
    printf("Menor numero de acidentes: %d (Estado: %s)\n",
           cad[indMenor].acidentes, cad[indMenor].nome);

    printf("Maior numero de acidentes: %d (Estado: %s)\n",
           cad[indMaior].acidentes, cad[indMaior].nome);

    printf("\n\n--- PERCENTUAL DE VEICULOS EM ACIDENTES ---\n");
    for (i = 0; i < TAM_ESTADOS; i++) {
        printf("%s: %.2f%%\n", cad[i].nome, percentual(cad, i));
    }

    media = mediaAcidentes(cad);

    printf("\nMedia de acidentes no pais: %.2f\n", media);

    acimaDaMedia(cad, media);

    return 0;
}
