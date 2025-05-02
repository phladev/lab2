#include <stdio.h>
#include "Heap.h"

int main() {
  int opcao;
  FilaP *fp;

  do {
    printf("Escolha uma opção:\n");
    printf("1 - Criar Fila;\n");
    printf("2 - Inserir um item pela prioridade;\n");
    printf("3 - Ver o início da Fila;\n");
    printf("4 - Remover um item;\n");
    printf("5 - Imprimir a Fila;\n");
    printf("6 - Mostrar o tamanho da Fila;\n");
    printf("7 - Destruir a Fila;\n");
    printf("8 - Sair;\n");
    printf("Opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
      case 1:
        fp = criaFila();
        break;
      case 2:
        int x, prio;
        printf("Digite o elemento a ser inserido com sua prioridade: ");
        scanf("%d %d", &x, &prio);
        if (inserirPrio(fp, x, prio)) {
          printf("Elemento %d de prioridade %d inserido com sucesso!\n", x, prio);
        } else {
          printf("Ocorreu um erro!\n");
        }
        break;
      case 3:
        int ini, prioIni;
        if (verIni(fp, &ini, &prioIni)) {
          printf("O primeiro elemento da Fila é: %d\n", ini);
        } else {
          printf("Ocorreu um erro!\n");
        }
        break;
      case 4:
        if(removeIni(fp)) {
          printf("Elemento removido com sucesso!\n");
        } else {
          printf("Ocorreu um erro!\n");
        }
        break;
      case 5:
        imprime(fp);
        break;
      case 6:
        printf("O tamanho da Fila é: %d\n", tamanhoFila(fp));
        break;
      case 7:
        destroiFila(fp);
        break;
      case 8: 
        printf("Saindo...\n");
        break;
      default:
        printf("Opção inválida! Tente novamente.\n");
    }
  } while (opcao != 8);

  return 0;
}