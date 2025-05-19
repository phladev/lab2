#include <stdio.h>
#include "MatrizEspersa.h"

int main() {
  int opcao;
  MEsparsaCSR* ms = NULL;

  do {
    printf("Escolha uma opcao:\n");
    printf("1 - Criar matriz esparsa\n");
    printf("2 - Inserir elemento\n");
    printf("3 - Remover elemento\n");
    printf("4 - Imprimir matriz esparsa\n");
    printf("5 - Consultar elemento\n");
    printf("0 - Sair\n");
    scanf("%d", &opcao);

    switch(opcao) {
      case 1:
        int l, c, qnn;
        printf("Digite o numero de linhas, colunas e elementos nao nulos: ");
        scanf("%d %d %d", &l, &c, &qnn);
        ms = criaMatrizEsparsa(l, c, qnn);
        if(ms == NULL) {
          printf("Erro ao criar a matriz esparsa.\n");
        } else {
          printf("Matriz esparsa criada com sucesso.\n");
        }
        break;
      case 2:
        if(ms == NULL) {
          printf("Crie a matriz esparsa primeiro.\n");
        } else {
          int i, j, valor;
          printf("Digite a linha, coluna e o valor a ser inserido: ");
          scanf("%d %d %d", &i, &j, &valor);
          if(insereElemEsparsa(ms, valor, i, j) == 1) {
            printf("Elemento inserido com sucesso.\n");
          } else {
            printf("Erro ao inserir elemento.\n");
          }
        }
        break;
      case 3:
        if(ms == NULL) {
          printf("Crie a matriz esparsa primeiro.\n");
        } else {
          int i, j;
          printf("Digite a linha e coluna do elemento a ser removido: ");
          scanf("%d %d", &i, &j);
          if(removeElemEsparsa(ms, i, j) == 1) {
            printf("Elemento removido com sucesso.\n");
          } else {
            printf("Erro ao remover elemento.\n");
          }
        }
        break;
      case 4:
        if(ms == NULL) {
          printf("Crie a matriz esparsa primeiro.\n");
        } else {
          imprimeEsparsa(ms);
        }
        break;
      case 5:
        if(ms == NULL) {
          printf("Crie a matriz esparsa primeiro.\n");
        } else {
          int i, j;
          printf("Digite a linha e coluna do elemento a ser consultado: ");
          scanf("%d %d", &i, &j);
          int valor = consultaElemEsparsa(ms, i, j);
          if(valor != 0) {
            printf("Elemento na posicao [%d][%d]: %d\n", i, j, valor);
          } else {
            printf("Elemento inexistente na posicao [%d][%d].\n", i, j);
          }
        }
        break;
    }
  } while(opcao != 0);

  destroiMatrizEsparsa(ms);
  return 0;
}