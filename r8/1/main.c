#include <stdio.h>
#include "ABP.h"

int main() {
  ABP* raiz = NULL;
  int opcao;

  do{
    printf("Escolha uma opcao:\n");
    printf("1 - Criar ABP\n");
    printf("2 - Inserir um elemento\n");
    printf("3 - Buscar um elemento\n");
    printf("4 - Remover um elemento\n");
    printf("5 - Imprimir a ABP em ordem\n");
    printf("6 - Imprimir a ABP em pre-ordem\n");
    printf("7 - Imprimir a ABP em pos-ordem\n");
    printf("8 - Mostrar a quantidade de nos na ABP\n");
    printf("9 - Destruir a ABP\n");
    printf("10 - Sair\n");
    scanf("%d", &opcao);

    switch(opcao) {
      case 1:
        raiz = criaABP();
        if(raiz != NULL) {
          printf("ABP criada com sucesso!\n");
        } else {
          printf("Erro ao criar ABP.\n");
        }
        break;
      case 2: {
        int valor;
        printf("Digite o valor a ser inserido: ");
        scanf("%d", &valor);
        if(insereRec(raiz, valor)) {
          printf("Valor %d inserido com sucesso!\n", valor);
        } else {
          printf("Valor %d ja existe na ABP.\n", valor);
        }
        break;
      }
      case 3: {
        int valor;
        printf("Digite o valor a ser buscado: ");
        scanf("%d", &valor);
        if(pesquisaValor(raiz, valor)) {
          printf("Valor %d encontrado na ABP.\n", valor);
        } else {
          printf("Valor %d nao encontrado na ABP.\n", valor);
        }
        break;
      }
      case 4: {
        int valor;
        printf("Digite o valor a ser removido: ");
        scanf("%d", &valor);
        if(removeValor(raiz, valor)) {
          printf("Valor %d removido com sucesso!\n", valor);
        } else {
          printf("Valor %d nao encontrado para remocao.\n", valor);
        }
        break;
      }
      case 5:
        imprimeEmOrdem(raiz);
        break;
      case 6:
        imprimePreOrdem(raiz);
        break;
      case 7:
        imprimePosOrdem(raiz);
        break;
      case 8:
        printf("Quantidade de nos na ABP: %d\n", numeroNos(raiz));
        break;
      case 9:
        destroiABP(raiz);
        printf("ABP destruida com sucesso!\n");
        break;
      case 10:
        printf("Saindo...\n");
        break;
      default:
        printf("Opcao invalida. Tente novamente.\n");
    }
    
  } while(opcao != 10);
}