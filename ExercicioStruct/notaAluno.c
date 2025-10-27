#include <stdio.h>
#include <string.h>

struct Aluno{
    char nome[50];
    double nota1;
    double nota2;
};

void lerStr(char str[], int tam);
void imprimirAluno(struct Aluno p);
void preencherAluno(struct Aluno *p);
double calcularMedia(struct Aluno p);

int main () {
    struct Aluno p;
    double media;
    preencherAluno(&p);
    media = calcularMedia(p);
    imprimirALuno(p);
    printf("O Aluno %s teve média = %.2lf\n", p.nome, media);
    return 0;
}

void lerStr(char str[], int tam) {
  fgets(str, tam, stdin);
  int tamDigitado = strlen(str);
  if (str[tamDigitado - 1] == '\n') {
    str[tamDigitado - 1] = '\0';
  }
}

void imprimirALuno(struct Aluno p) {
    printf("Nota 1 = %.2lf, Nota 2 = %.2lf\n", p.nota1, p.nota2);
}

void preencherAluno(struct Aluno *p) {
    printf("Digite o nome do aluno: ");
    lerStr((*p).nome, 50);
    printf("Digite a nota 1: ");
    scanf("%lf", &(*p).nota1);
    printf("Digite a nota 2: ");
    scanf("%lf", &(*p).nota2);
}

double calcularMedia(struct Aluno p) {
    return (2 * p.nota1 + 3 * p.nota2) / 5;
}