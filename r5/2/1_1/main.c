#include <stdio.h>
#include "Pilha.h"

int main() {
  int opcao;
  Pilha* pi;

  do {
    printf("Escolha uma opção:\n");
    printf("1 - Criar pilha;\n");
    printf("2 - Empilhar um item;\n");
    printf("3 - Ver o topo da pilha;\n");
    printf("4 - Desempilhar um item;\n");
    printf("5 - Imprimir a pilha;\n");
    printf("6 - Destruir a pilha;\n");
    printf("7 - Sair.\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        pi = criaPilha();
        break;
      case 2:
        int elem;
        printf("Digite o elemento a ser empilhado: ");
        scanf("%d", &elem);
        if (empilhar(pi, elem)) {
          printf("Elemento %d empilhado com sucesso!\n", elem);
        } else {
          printf("Ocorreu um erro!\n");
        }
        break;
      case 3:
        int valor;
        if (verTopo(pi, &valor)) {
          printf("O elemento do topo da fila é: %d\n", valor);
        } else {
          printf("Não foi possível acessar o topo da fila.\n");
        }
        break;
      case 4:
        if (desempilhar(pi)) {
          printf("Elemento desempilhado com sucesso!\n");
        } else {
          printf("Erro ao desimpilhar!\n");
        }
        break;
      case 5:
        imprime(pi);
        break;
      case 6:
        destroiPilha(pi);
        pi = NULL;
        break;
      case 7:
        printf("Saindo...\n");
        break;
      default:
        printf("Opção inválida! Tente novamente.\n");
    }
  } while (opcao != 7);

  return 0;
}