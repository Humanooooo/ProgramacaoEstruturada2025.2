#include <stdio.h>
#include <string.h>

#define TAM 256

void lerStr(char str[], int tam);
void inserirFinalArquivo(char nomeArq[]);
void listarArquivo(char nomeArq[]);
void lerPosicaoEspecifica(char nomeArq[]);
void buscarNumero(char nomeArq[]);
void substituirNumero(char nomeArq[]);
void excluirNumero(char nomeArq[]);

int main() {
  char nomeArq[TAM];
  int opcao;
  printf("Digite o nome do arquivo: ");
  lerStr(nomeArq, TAM);
  while(strlen(nomeArq) == 0) {
    printf("Nome vazio é inválido!\n");
    printf("Digite o nome do arquivo: ");
    lerStr(nomeArq, TAM);
  }
  do {
    printf("\n\nMENU\n");
    printf("1 - Gravar um número no final do arquivo\n");
    printf("2 - Listar o conteúdo do arquivo\n");
    printf("3 - Imprimir valor específico\n");
    printf("4 - Buscar um número\n");
    printf("5 - Substituir um número\n");
    printf("6 - Excluir um número\n");
    printf("Digite a sua opção (0 p/ finalizar): ");
    scanf("%d", &opcao);
    switch (opcao) {
      case 1:
        inserirFinalArquivo(nomeArq);
        break;
      case 2:
        printf("---------------- Listagem ----------------\n");
        listarArquivo(nomeArq);
        printf("------------------------------------------\n");
        break;
      case 3:
        lerPosicaoEspecifica(nomeArq);
        break;
      case 4:
        buscarNumero(nomeArq);
        break;
      case 5:
        substituirNumero(nomeArq);
        break;
      case 6:
        excluirNumero(nomeArq);
        break;
      default:
        if (opcao != 0) {
          printf("Opção inválida!\n");
        }
      }
  } while (opcao != 0);
  return 0;
}

void lerStr(char str[], int tam) {
  fgets(str, tam, stdin);
  int tamDigitado = strlen(str);
  if (str[tamDigitado - 1] == '\n') {
    str[tamDigitado - 1] = '\0';
  }
}

void inserirFinalArquivo(char nomeArq[]) {
  int status;
  double num;
  FILE *arq = fopen(nomeArq, "ab");
  if (arq == NULL) {
    printf("Não pode abrir o arquivo!\n");
    return;
  }
  printf("Digite um número real: ");
  scanf("%lf", &num);
  status = fwrite(&num, sizeof(double), 1, arq);
  if (status == 1) {
    printf("Valor armazenado com sucesso!\n");
  } else {
    printf("Erro ao gravar o valor no arquivo!\n");
  }
  fclose(arq);
}

void listarArquivo(char nomeArq[]) {
  int status;
  double num;
  FILE *arq = fopen(nomeArq, "rb");
  if (arq == NULL) {
    printf("Não pode abrir o arquivo!\n");
    return;
  }
  status = fread(&num, sizeof(double), 1, arq);
  while (!feof(arq)) {
    if (status != 1) {
      printf("Erro na leitura do registro");
    } else {
      printf("%.3f\n", num);
    }
    status = fread(&num, sizeof(double), 1, arq);
  }
  fclose(arq);
}

void lerPosicaoEspecifica(char nomeArq[]) {
  int status, pos;
  double num;
  FILE *arq = fopen(nomeArq, "rb");
  if (arq == NULL) {
    printf("Não pode abrir o arquivo!\n");
    return;
  }

  printf("Você quer mover para que posição: ");
  scanf("%d", &pos);

  status = fseek(arq, (pos - 1) * sizeof(double), SEEK_SET);
  if (status != 0 || feof(arq)) {
    printf("Essa é uma posição inválida!");
    fclose(arq);
    return;
  }

  status = fread(&num, sizeof(double), 1, arq);
  if (status != 1) {
    printf("Erro na leitura do registro");
  } else {
    printf("%.3f\n", num);
  }
  fclose(arq);
}

void buscarNumero(char nomeArq[]) {
  double num, valorBuscado;
  int status, encontrado = 0;
  FILE *arq = fopen(nomeArq, "rb");
  if (arq == NULL) {
    printf("Não pode abrir o arquivo!\n");
    return;
    }

  printf("Digite o número que cê quer buscar: ");
  scanf("%lf", &valorBuscado);

  status = fread(&num, sizeof(double), 1, arq);
  while (!feof(arq)) {
    if (status == 1 && num == valorBuscado) {
      encontrado = 1;
      break;
    }
    status = fread(&num, sizeof(double), 1, arq);
  }

  if (encontrado) {
    printf("O múmero %.3f tá no arquivo\n", valorBuscado);
    } else {
    printf("O múmero %.3f não tá no arquivo\n", valorBuscado);
  }
  fclose(arq);
}

void substituirnumero(char nomeArq[]) {
  double num, valorAntigo, valorNovo;
  int status, encontrado = 0;
  FILE *arq = fopen(nomeArq, "r+b");
  if (arq == NULL) {
    printf("Não pode abrir o arquivo!\n");
    return;
  }

  printf("Digite o número que cê quer substituir: ");
  scanf("%lf", &valorAntigo);
  printf("Digite o novo número: ");
  scanf("%lf", &valorNovo);

  status = fread(&num, sizeof(double), 1, arq);
  while (!feof(arq)) {
    if (status == 1 && num == valorAntigo) {
      encontrado = 1;
      fseek(arq, -sizeof(double), SEEK_CUR);
      fwrite(&valorNovo, sizeof(double), 1, arq);
      break;
    }
    status = fread(&num, sizeof(double), 1, arq);
  }

  if (encontrado) {
    printf("Número substituído com sucesso!\n");
  } else {
    printf("Número não encontrado no arquivo!\n");
  }
  fclose(arq);
}

void excluirNumero(char nomeArq[]) { 
  double num, valorExcluir;
  int encontrado = 0;
  char tmpName[TAM];
  FILE *arq = fopen(nomeArq, "rb");
  if (arq == NULL) {
    printf("Não pode abrir o arquivo!\n");
    return;
  }

  snprintf(tmpName, TAM, "%s.tmp", nomeArq);
  FILE *tmp = fopen(tmpName, "wb");
  if (tmp == NULL) {
    printf("Não foi possível criar arquivo temporário!\n");
    fclose(arq);
    return;
  }

  printf("Digite o número que cê quer excluir: ");
  scanf("%lf", &valorExcluir);

  while (fread(&num, sizeof(double), 1, arq) == 1) {
    if (!encontrado && num == valorExcluir) {
      encontrado = 1;
      continue;
    }
    fwrite(&num, sizeof(double), 1, tmp);
  }

  fclose(arq);
  fclose(tmp);

  if (encontrado) {
    if (remove(nomeArq) != 0) {
      printf("Erro ao apagar o arquivo original!\n");
      remove(tmpName);
      return;
    }
    if (rename(tmpName, nomeArq) != 0) {
      printf("Erro ao renomear arquivo temporário!\n");
      return;
    }
    printf("Número excluído com sucesso!\n");
  } else {
    remove(tmpName);
    printf("Número não encontrado no arquivo!\n");
  }
}