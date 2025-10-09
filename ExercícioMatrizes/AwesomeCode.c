#include <stdio.h>

#define QTD_LINHAS 5
#define QTD_COLUNAS 4

void preencherMatrizDigitacao(int matriz[][QTD_COLUNAS], int qtdLinhas, int qtdColunas);
void imprimirMatriz(int m[][QTD_COLUNAS], int qtdLinhas, int qtdColunas);
void calcularSomatorioLinhas(int m[][QTD_COLUNAS], int qtdLinhas, int qtdColunas, int vs[]);
void imprimirVetor(int vetor[], int tam);

int main() {
  int matriz[QTD_LINHAS][QTD_COLUNAS];
  int somatorioAnual[QTD_LINHAS];
  printf("Preenchimento da matriz\n");
  preencherMatrizDigitacao(matriz, QTD_LINHAS, QTD_COLUNAS);
  printf("\nImpressão da Matriz\n");
  imprimirMatriz(matriz, QTD_LINHAS, QTD_COLUNAS);
  calcularSomatorioLinhas(matriz, QTD_LINHAS, QTD_COLUNAS, somatorioAnual);
  printf("\nSomatório por linha\n");
  imprimirVetor(somatorioAnual, QTD_LINHAS);
  return 0;
}

void preencherMatrizDigitacao(int m[][QTD_COLUNAS], int qtdLinhas, int qtdColunas) {
  for (int l = 0; l < qtdLinhas; l += 1) {
    for (int c = 0; c < qtdColunas; c += 1) {
      printf("Digite valor da posição (%d, %d): \n", l + 1, c + 1);
      scanf("%d", &m[l][c]);
    }
  }
}

void imprimirMatriz(int m[][QTD_COLUNAS], int qtdLinhas, int qtdColunas) {
  for (int l = 0; l < qtdLinhas; l += 1) {
    for (int c = 0; c < qtdColunas; c += 1) {
      printf("%2d ", m[l][c]);
    }
    printf("\n");
  }
}

void calcularSomatorioLinhas(
  int m[][QTD_COLUNAS], int qtdLinhas, int qtdColunas, int vs[]
) {
  for (int l = 0; l < qtdLinhas; l += 1) {
    vs[l] = 0;
    for (int c = 0; c < qtdColunas; c += 1) {
      vs[l] += m[l][c];
    }
  }
}

void imprimirVetor(int vetor[], int tam) {
  for (int i = 0; i < tam; i += 1) {
    printf("%3d ", vetor[i]);
  }
  printf("\n");
}