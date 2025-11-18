#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int numero;
    char nome[50];
    char cpf[15];
    char telefone[20];
    float saldo;
} Conta;

int buscar(Conta c[], int qtd, int num) {
    if (qtd == 0) return -1;
    for (int i = 0; i < qtd; i++)
        if (c[i].numero == num) return i;
    return -2;
}

void cadastrarConta(Conta c[], int *qtd, int num) {
    int p = buscar(c, *qtd, num);
    if (p >= 0 || *qtd == MAX) { printf("Conta invalida.\n"); return; }
    c[*qtd].numero = num;
    getchar();
    printf("Nome: "); fgets(c[*qtd].nome, 50, stdin); c[*qtd].nome[strcspn(c[*qtd].nome, "\n")] = 0;
    printf("CPF: "); fgets(c[*qtd].cpf, 15, stdin); c[*qtd].cpf[strcspn(c[*qtd].cpf, "\n")] = 0;
    printf("Telefone: "); fgets(c[*qtd].telefone, 20, stdin); c[*qtd].telefone[strcspn(c[*qtd].telefone, "\n")] = 0;
    printf("Saldo inicial: "); scanf("%f", &c[*qtd].saldo);
    (*qtd)++;
}

void consultarSaldo(Conta c[], int qtd, int num) {
    int p = buscar(c, qtd, num);
    if (p >= 0) printf("Saldo: %.2f\n", c[p].saldo);
    else printf("Conta nao encontrada.\n");
}

void deposito(Conta c[], int qtd, int num) {
    int p = buscar(c, qtd, num);
    if (p >= 0) {
        float v; printf("Valor: "); scanf("%f", &v);
        c[p].saldo += v;
    } else printf("Conta nao encontrada.\n");
}

void saque(Conta c[], int qtd, int num) {
    int p = buscar(c, qtd, num);
    if (p >= 0) {
        float v; printf("Valor: "); scanf("%f", &v);
        if (v <= c[p].saldo) c[p].saldo -= v;
        else printf("Saldo insuficiente.\n");
    } else printf("Conta nao encontrada.\n");
}

void listar(Conta c[], int qtd) {
    if (qtd == 0) printf("Cadastro vazio.\n");
    else
        for (int i = 0; i < qtd; i++)
            printf("Conta %d | %s | %s\n", c[i].numero, c[i].nome, c[i].telefone);
}

int main() {
    Conta cc[MAX], cp[MAX];
    int qc = 0, qp = 0, op, tipo, num;

    do {
        printf("\n1-Cadastrar  2-Saldo  3-Deposito  4-Saque  5-Listar  0-Sair\nOpcao: ");
        scanf("%d", &op);
        if (op == 0) break;

        printf("1-Corrente 2-Poupanca: ");
        scanf("%d", &tipo);

        Conta *cad = (tipo == 1 ? cc : cp);
        int *qtd = (tipo == 1 ? &qc : &qp);

        if (op == 1) { printf("Numero: "); scanf("%d", &num); cadastrarConta(cad, qtd, num); }
        else if (op == 2) { printf("Numero: "); scanf("%d", &num); consultarSaldo(cad, *qtd, num); }
        else if (op == 3) { printf("Numero: "); scanf("%d", &num); deposito(cad, *qtd, num); }
        else if (op == 4) { printf("Numero: "); scanf("%d", &num); saque(cad, *qtd, num); }
        else if (op == 5) listar(cad, *qtd);
        else printf("Opcao invalida.\n");

    } while (1);

    return 0;
}