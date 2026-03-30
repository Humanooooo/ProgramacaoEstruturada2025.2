#include <stdio.h>
#include <stdlib.h>

#define LIN 8
#define COL 8

void preencherMatriz(int m[][COL], int lin, int col);
void preencherMatrizAleatorio(int m[][COL], int lin, int col);
void imprimirMatriz(int m[][COL], int lin, int col);
void maiorValorMatriz(int m[][COL], int lin, int col);
void menorValorMatriz(int m[][COL], int lin, int col);
void zerarAbaixoDigPrincipal(int m[][COL], int lin, int col);
void zerarAbaixoDigPrincipalOtimizada(int m[][COL], int lin, int col);
void somarMatrizes(int m1[][COL], int m2[][COL], int resultado[][COL], int lin, int col);
int multiplicarMatrizes(int matA[][COL], int matB[][COL], int matMult[][COL], int linA, int colA, int linB, int colB, int linMult, int colMult);


int main() {
    int m[LIN][COL];
    srand(3);
    preencherMatrizAleatorio(m, LIN, COL);
    printf("\nMatriz preenchida\n");
    imprimirMatriz(m, LIN, COL);
    multiplicacao(m, m, m, LIN, COL, LIN, COL, LIN, COL);
    printf("\nMatriz multiplicada por ela mesma\n");
    imprimirMatriz(m, LIN, COL);
    return 0;
}

void preencherMatriz(int m[][COL], int lin, int col) {
    for (int i = 0; i < lin; i += 1) {
        for (int j = 0; j < col; j += 1) {
            printf("Digite o valor de m[%d][%d]: ", i + 1, j + 1);
            scanf("%d", &m[i][j]);
        }
    }
}

void preencherMatrizAleatorio(int m[][COL], int lin, int col) {
    for (int i = 0; i < lin; i += 1) {
        for (int j = 0; j < col; j += 1) {
            m[i][j] = rand() % 100 + 1;
        }
    }
}

void imprimirMatriz(int m[][COL], int lin, int col) {
    for (int i = 0; i < lin; i += 1) {
        for (int j = 0; j < col; j += 1) {
            printf("%3d\t", m[i][j]);
        }
        printf("\n");
    }
}

void maiorValorMatriz(int m[][COL], int lin, int col) {
    int iMaior = 0, jMaior = 0;
    for (int i = 0; i < lin; i += 1) {
        for (int j = 0; j < col; j += 1) {
            if (m[i][j] > m[iMaior][jMaior]) {
                iMaior = i;
                jMaior = j;
            }
        }
    }
    printf("O maior valor é %d e ele está na posição (%d, %d)\n",
        m[iMaior][jMaior], iMaior + 1, jMaior + 1);
}

void menorValorMatriz(int m[][COL], int lin, int col) {
    int iMenor = 0, jMenor = 0;
    for (int i = 0; i < lin; i += 1) {
        for (int j = 0; j < col; j += 1) {
            if (m[i][j] < m[iMenor][jMenor]) {
                iMenor = i;
                jMenor = j;
            }
        }
    }
    printf("O menor valor é %d e ele está na posição (%d, %d)\n",
        m[iMenor][jMenor], iMenor + 1, jMenor + 1);
}

void zerarAbaixoDigPrincipalOtimizada(int m[][COL], int lin, int col) {
    if (lin != col) {
        printf("Essa não é uma matriz quadrada!\n");
        return;
    }
     for (int i = 1; i < lin; i += 1) {
        for (int j = 0; j < i; j += 1) {
            m[i][j] = 0;
        }
    }
}

void somarMatrizes(int matA[][COL], int matB[][COL], int matSoma[][COL], int lin, int col) {
    for (int i = 0; i < lin; i += 1) {
        for (int j = 0; j < col; j += 1) {
            matSoma[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

void QuadradaPraTransposta(int m[][COL], int transposta[][COL], int lin, int col) {
    if (lin != col) {
        printf("Essa num é uma matriz quadrada!\n");
        return;
    }
    for (int i = 0; i < lin; i += 1) {
        for (int j = 0; j < col; j += 1) {
            transposta[j][i] = m[i][j];
        }
    }
}

void multiplicacao(
  int matA[][COL], int qtdLinhasA, int qtdColunasA,
  int matB[][COL], int qtdLinhasB, int qtdColunasB,
  int matMult[][COL]
) {
  if (qtdColunasA != qtdLinhasB) {
    printf("Essas duas matrizes não são compatíveis!");
    return;
  }

  for (int i = 0; i < qtdLinhasA; i += 1) {
    for (int j = 0; j < qtdColunasB; j += 1) {
      matMult[i][j] = 0;
      for (int k = 0; k < qtdColunasA; k += 1) {
        matMult[i][j] += matA[i][k] * matB[k][j];
      }
    }
  }
}