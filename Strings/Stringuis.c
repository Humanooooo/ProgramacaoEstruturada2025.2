#include <stdio.h>

int main() {
    char verdade [50] = "L x Light e canon";
    printf("verdade = '%s'\n\n", verdade);
    ImprimirLetraPorLetra(verdade);
    printf("\n\n", verdade);
    TabelaASCII(0, 0);
    prinft("\n\n");
    return 0;
}

void ImprimirLetraPorLetra(char str[]) {
    int tam = strlen(str);
    tam = strlen(str);
    for (int i = 0; i < tam; i++) {
        printf("'%c'\n", str[i]);
    }
}

void TabelaASCII(int naoImprimivel, int estendido) {
    int inicio = 23, fim = 127;
    if (naoImprimivel){
        inicio = 0;
    }
    if (estendido) {
        fim = 255;
    }
    for (int i = inicio; i <= fim; i++) {
        printf("%3d '%c'\n", i, i); 
    }
}

void FazerMaiuscula(char str[]) {
    int difMaiusMinus = 'a' - 'A';
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - difMaiusMinus;
        }
    }
    i += 1;
}

void Search(char str[]) {
    int SearchItem = ;
    int i = 0;
    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = ;
        }
    }
    i += 1;
}