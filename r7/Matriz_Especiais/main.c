#include <stdio.h>
#include "MatrizFaixa.h"

int main() {
  int opcao;
  MFaixa* mf;

  do {
    printf("Escolha uma opcao:\n");
    printf("1 - Criar matriz\n");
    printf("2 - Preencher matriz com valores aleatorios\n");
    printf("3 - Inserir elemento\n");
    printf("4 - Imprimir matriz\n");
    printf("5 - Consultar elemento\n");
    printf("0 - Sair\n");
    scanf("%d", &opcao);

    switch(opcao) {
      case 1:
        int tam;
        printf("Digite o tamanho da matriz: ");
        scanf("%d", &tam);
        mf = criaMatriz(tam);
        if(mf == NULL) {
          printf("Erro ao criar a matriz.\n");
        } else {
          printf("Matriz criada com sucesso.\n");
        }
        break;
      case 2:
        if(mf == NULL) {
          printf("Crie a matriz primeiro.\n");
        } else {
          int ini, fim;
          printf("Digite o valor inicial e final para preencher a matriz: ");
          scanf("%d %d", &ini, &fim);
          preencheAleatorio(mf, ini, fim);
          printf("Matriz preenchida com sucesso.\n");
        }
        break;
      case 3:
        if(mf == NULL) {
          printf("Crie a matriz primeiro.\n");
        } else {
          int i, j, valor;
          printf("Digite a linha, coluna e o valor a ser inserido: ");
          scanf("%d %d %d", &i, &j, &valor);
          if(insereElem(mf, valor, i, j) == 1) {
            printf("Elemento inserido com sucesso.\n");
          } else {
            printf("Erro ao inserir elemento.\n");
          }
        }
        break;
      case 4:
        if(mf == NULL) {
          printf("Crie a matriz primeiro.\n");
        } else {
          imprimeFaixa(mf);
        }
        break;
      case 5:
        if(mf == NULL) {
          printf("Crie a matriz primeiro.\n");
        } else {
          int i, j;
          printf("Digite a linha e coluna do elemento a ser consultado: ");
          scanf("%d %d", &i, &j);
          int valor = consultaElem(mf, i, j);
          if(valor != 0) {
            printf("Elemento na posicao [%d][%d]: %d\n", i, j, valor);
          } else {
            printf("Elemento nao encontrado.\n");
          }
        }
        break;
      case 0:
        destroiMatriz(mf);
        break;
      default:
        printf("Opcao invalida. Tente novamente.\n");
    }
  } while(opcao != 0);

  return 0;
}
