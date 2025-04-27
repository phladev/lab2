#include <stdio.h>
#include "Fila.h"

int main() {
  int opcao;
  Fila* fi;

  do {
    printf("Escolha uma opção:\n");
    printf("1 - Criar fila;\n");
    printf("2 - Enfileirar um item;\n");
    printf("3 - Ver o início da fila;\n");
    printf("4 - Desenfileirar um item;\n");
    printf("5 - Imprimir a fila;\n");
    printf("6 - Destruir fila;\n");
    printf("7 - Sair.\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        fi = criaFila();
        break;
      case 2:
        int elem;
        printf("Digite o elemento a ser enfileirado: ");
        scanf("%d", &elem);
        if (enfileirar(fi, elem)) {
          printf("Elemento %d enfileirado com sucesso!\n", elem);
        } else {
          printf("Ocorreu um erro!\n");
        }
        break;
      case 3:
        int valor;
        if (verInicio(fi, &valor)) {
          printf("O primeiro elemento da fila é: %d\n", valor);
        } else {
          printf("Não foi possível acessar o início da fila.\n");
        }
        break;
      case 4:
        if (desenfileirar(fi)) {
          printf("Elemento desenfileirado com sucesso!\n");
        } else {
          printf("Erro ao desenfileirar!\n");
        }
        break;
      case 5:
        imprime(fi);
        break;
      case 6:
        destroiFila(fi);
        fi = NULL;
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