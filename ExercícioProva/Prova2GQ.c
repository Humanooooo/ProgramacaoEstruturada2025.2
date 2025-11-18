//QUESTÃO 4

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
int categoria; // código da categoria que está no vetor categorias
int preco; // representa um valor numérico com 2 casas decimais
};

void lerStr(char str[], int tam);
void preencherCategoria(struct Categoria *c);
void preencherProduto(struct Produto *p, struct Categoria categorias[], int qtdCategorias);
void selectionSortPorDescricao(struct Produto v[], int qtd);

selectionSortPorDescricao(struct Produto v[], int qtd) {
    int i, j, min_idx;
    struct Produto temp;
    for (i = 0; i < qtd-1; i++) {
        min_idx = i;
        for (j = i+1; j < qtd; j++) {
            if (strcmp(v[j].descricao, v[min_idx].descricao) < 0) {
                min_idx = j;
            }
        }
        temp = v[min_idx];
        v[min_idx] = v[i];
        v[i] = temp;
    }
}

bubbleSortPorPreco(struct Produto v[], int qtd) {
    int i, j;
    struct Produto temp;
    for (i = 0; i < qtd-1; i++) {
        for (j = 0; j < qtd-i-1; j++) {
            if (v[j].preco > v[j+1].preco) {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

bubblesortpornome(struct Produto v[], int qtd) {
    int i, j;
    struct Produto temp;
    for (i = 0; i < qtd-1; i++) {
        for (j = 0; j < qtd-i-1; j++) {
            if (strcmp(v[j].titulo, v[j+1].titulo) > 0) {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            }
        }
    }
}

bubbleSortPorPrecoeNome(struct Produto v[], int qtd) {
    int i, j;
    struct Produto temp;
    for (i = 0; i < qtd-1; i++) {
        for (j = 0; j < qtd-i-1; j++) {
            if (v[j].preco > v[j+1].preco) {
                temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;
            } else if (v[j].preco == v[j+1].preco) {
                if (bubblesortpornome(v, qtd) > 0) {
                    temp = v[j];
                    v[j] = v[j+1];
                    v[j+1] = temp;
                }
            }
        }
    }
}
