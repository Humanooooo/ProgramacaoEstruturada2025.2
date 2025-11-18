#include <stdio.h>
#include <string.h>

#define TAM 100

struct Categoria {
    int codigo;
    char nome[50];
};

struct Produto {
    int codigo;
    char titulo[100];
    char descricao[256];
    int categoria; 
    int preco; 
};

//QUESTÃO 1

void cadastrarCategoria(struct Categoria v[], int *qtd) {
    if (*qtd == TAM) {
        printf("Vetor cheio. Nao e possivel cadastrar.\n");
        return;
    }

    int cod;
    printf("Codigo da categoria: ");
    scanf("%d", &cod);

    for (int i = 0; i < *qtd; i++) {
        if (v[i].codigo == cod) {
            printf("Erro: codigo repetido.\n");
            return;
        }
    }

    v[*qtd].codigo = cod;
    getchar();
    printf("Nome da categoria: ");
    fgets(v[*qtd].nome, 50, stdin);
    v[*qtd].nome[strcspn(v[*qtd].nome, "\n")] = '\0';

    (*qtd)++;
}

// QUESTÃO 2

void imprimirCategorias(struct Categoria v[], int qtd) {
    for (int i = 0; i < qtd; i++) {
        printf("Codigo: %d | Nome: %s\n", v[i].codigo, v[i].nome);
    }
}

// QUESTÃO 3

void imprimirProdutos(struct Produto vp[], int qtdProdutos,
                      struct Categoria vc[], int qtdCategorias) {

    for (int i = 0; i < qtdProdutos; i++) {

        char nomeCategoria[50] = "Categoria NAO encontrada";

        for (int j = 0; j < qtdCategorias; j++) {
            if (vc[j].codigo == vp[i].categoria) {
                strcpy(nomeCategoria, vc[j].nome);
                break;
            }
        }

        double preco = vp[i].preco / 100.0;

        printf("Codigo: %d\n", vp[i].codigo);
        printf("Titulo: %s\n", vp[i].titulo);
        printf("Descricao: %s\n", vp[i].descricao);
        printf("Categoria: %s\n", nomeCategoria);
        printf("Preco: R$ %.2lf\n", preco);
        printf("-----------------------------\n");
    }
}

//QUESTÃO 4

void selectionSortPorDescricao(struct Produto v[], int qtd) {
    for (int i = 0; i < qtd - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < qtd; j++) {
            if (strcmp(v[j].descricao, v[menor].descricao) < 0) {
                menor = j;
            }
        }
        if (menor != i) {
            struct Produto aux = v[i];
            v[i] = v[menor];
            v[menor] = aux;
        }
    }
}

//QUESTÃO 5

void buscaBinariaPorDescricao(struct Produto v[], int qtd, char *x) {
    int ini = 0, fim = qtd - 1;

    while (ini <= fim) {
        int meio = (ini + fim) / 2;
        int cmp = strcmp(x, v[meio].descricao);

        if (cmp == 0) {
            printf("Produto encontrado:\n");
            printf("Codigo: %d | Titulo: %s\n", v[meio].codigo, v[meio].titulo);
            return;
        }

        if (cmp < 0) fim = meio - 1;
        else ini = meio + 1;
    }

    printf("Produto nao encontrado.\n");
}