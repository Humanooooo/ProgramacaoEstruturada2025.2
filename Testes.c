#include <stdio.h>

double dobro(double x);
int ehPrimo(int x);

int main() {
    double num, result;
    printf("Digite um número real: ");
    scanf ("%lf", &num);
    result = dobro(num);
    printf("O dobro de %f é %f\n", num, result);
    return 0;

    printf("Digite um número inteiro: ")
    scanf("%d", &num2);
    primo = ehPrimo(num2);
    if (primo {
        printf("O número %d é primo.\n", num2);
    } else {
        printf("O número ")
    }
}

double dobro(double x) {
    return 2 * x;
}

int ehPrimo (int x) {
    int qtdDivisores = 0;
    for (int i = 1; i <= x; i += 1) {
        if (x % i == 0) {
            qtdDivisores += 1;
        }
    }

    return qtdDivisores == 2;
}