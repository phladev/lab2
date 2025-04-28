#include <stdio.h>
#include "DequeEst.h"

int main() {
  int opcao;
  Deque* dq;

  do {
    printf("Escolha uma opção:\n");
    printf("1 - Criar Deque;\n");
    printf("2 - Inserir um item no fim;\n");
    printf("3 - Inserir um item no início;\n");
    printf("4 - Ver o início do Deque;\n");
    printf("5 - Ver o fim do Deque;\n");
    printf("6 - Remover um item do fim;\n");
    printf("7 - Remover um item do início;\n");
    printf("8 - Imprimir o Deque;\n");
    printf("9 - Destruir o Deque;\n");
    printf("10 - Sair.\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        dq = criaDeque();
        break;
      case 2:
        int elemIni;
        printf("Digite o elemento a ser inserido no fim: ");
        scanf("%d", &elemIni);
        if (insereFim(dq, elemIni)) {
          printf("Elemento %d inserido com sucesso!\n", elemIni);
        } else {
          printf("Ocorreu um erro!\n");
        }
        break;
      case 3:
        int elemFim;
        printf("Digite o elemento a ser inserido no início: ");
        scanf("%d", &elemFim);
        if (insereIni(dq, elemFim)) {
          printf("Elemento %d inserido com sucesso!\n", elemFim);
        } else {
          printf("Ocorreu um erro!\n");
        }
        break;
      case 4:
        int valorIni;
        if (verInicio(dq, &valorIni)) {
          printf("O primeiro elemento do Deque é: %d\n", valorIni);
        } else {
          printf("Ocorreu um erro!\n");
        }
        break;
      case 5:
        int valorFim;
        if (verFim(dq, &valorFim)) {
          printf("O último elemento do Deque é: %d\n", valorFim);
        } else {
          printf("Ocorreu um erro!\n");
        }
        break;
      case 6:
        if (removeFim(dq)) {
          printf("Elemento removido do fim com sucesso!\n");
        } else {
          printf("Ocorreu um erro!\n");
        }
        break;
      case 7:
        if (removeIni(dq)) {
          printf("Elemento removido do início com sucesso!\n");
        } else {
          printf("Ocorreu um erro!\n");
        }
        break;
      case 8: 
        imprime(dq);
        break;
      case 9:
        destroiDeque(dq);
        dq = NULL;
        printf("Deque destruído com sucesso!\n");
        break;
      case 10:
        printf("Saindo...\n");
        break;
      default:
        printf("Opção inválida! Tente novamente.\n");
    }
  } while (opcao != 10);

  return 0;
}