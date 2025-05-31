#include <stdio.h>
#include <string.h>
#include "AVL_Funcionario.h"


int main() {
  AVL* raiz = NULL;
  int opcao;

  do{
    printf("Escolha uma opcao:\n");
    printf("1 - Criar AVL\n");
    printf("2 - Inserir um Funcionario pelo salario\n");
    printf("3 - Buscar um Funcionario pelo salario e imprimir suas informacoes\n");
    printf("4 - Remover um Funcionario pelo nome\n");
    printf("5 - Imprimir a AVL em ordem\n");
    printf("6 - Imprimir as informacoes do Funcionario com o maior salario\n");
    printf("7 - Imprimir as informacoes do Funcionario com o menor salario\n");
    printf("8 - Destruir a AVL\n");
    printf("9 - Sair\n");
    scanf("%d", &opcao);


    switch(opcao) {
      case 1:
      if (raiz != NULL) {
        printf("A AVL já foi criada.\n");
      } else {
        raiz = criarAVL();
        if (raiz != NULL) {
        printf("AVL criada com sucesso!\n");
        } else {
        printf("Erro ao criar AVL.\n");
        }
      }
      break;
      case 2:
        Funcionario f;
        getchar(); 
        printf("Digite o nome do funcionario: ");
        fgets(f.nome, sizeof(f.nome), stdin);
        f.nome[strlen(f.nome) - 1] = '\0';
        printf("Digite o ano de contratacao do funcionario: ");
        scanf("%d", &f.ano_contratacao);
        printf("Digite o salario do funcionario: ");
        scanf("%lf", &f.salario);
        insereValor(raiz, f);
        printf("Funcionario inserido com sucesso!\n");
        break;
      case 3:
        double salario;
        printf("Digite o salario do funcionario a ser buscado: ");
        scanf("%lf", &salario);
        pesquisa(raiz, salario);
        break;
      case 4: 
        char nome[100];
        printf("Digite o nome do funcionario a ser removido: ");
        fgets(nome, sizeof(nome), stdin);
        nome[strlen(nome) - 1] = '\0';
        removeValor(raiz, nome);
        break;
      case 5:
        imprimeAVL(raiz);
        break;
      case 6: 
        funcionarioMaiorSalario(raiz);
        break;
      case 7:
        funcionarioMenorSalario(raiz);
        break;
      case 8:
        destroiAVL(raiz);
        printf("AVL destruida com sucesso!\n");
        break;
      case 9:
        printf("Saindo...\n");
        break;
      default:
        printf("Opcao invalida. Tente novamente.\n");
    }
   
  } while(opcao != 9);

  return 0;
}
