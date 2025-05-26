#include <stdio.h>
#include "ABP_Aluno.h"

int main() {
  ABP_ALUNO* raiz = criaABP();
  int opcao;

  do{
    printf("Escolha uma opcao:\n");
    printf("1 - Criar ABP\n");
    printf("2 - Inserir um Aluno\n");
    printf("3 - Buscar um Aluno pelo nome e imprimir suas informacoes\n");
    printf("4 - Remover um Aluno pelo nome\n");
    printf("5 - Imprimir a ABP em ordem\n");
    printf("6 - Imprimir as informacoes do aluno com a maior nota\n");
    printf("7 - Imprimir as informacoes do aluno com a menor nota\n");
    printf("8 - Destruir a ABP\n");
    printf("9 - Sair\n");
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
        Aluno aluno;
        printf("Digite o nome do aluno: ");
        scanf("%s", aluno.nome);
        printf("Digite a matricula do aluno: ");
        scanf("%d", &aluno.matricula);
        printf("Digite a nota do aluno: ");
        scanf("%lf", &aluno.nota);
        
        if(insereRec(raiz, aluno)) {
          printf("Aluno %s inserido com sucesso!\n", aluno.nome);
        } else {
          printf("Aluno %s ja existe na ABP.\n", aluno.nome);
        }
        break;
      }
      case 3: {
        Aluno aluno;
        printf("Digite o nome do aluno a ser buscado: ");
        scanf("%s", aluno.nome);
        if(pesquisaValor(raiz, aluno)) {
          printf("Aluno %s encontrado na ABP.\n", aluno.nome);
        } else {
          printf("Aluno %s nao encontrado na ABP.\n", aluno.nome);
        }
        break;
      }
      case 4: {
        Aluno aluno;
        printf("Digite o nome do aluno a ser removido: ");
        scanf("%s", aluno.nome);
        if(removePorNome(raiz, aluno.nome)) {
          printf("Aluno %s removido com sucesso!\n", aluno.nome);
        } else {
          printf("Aluno %s nao encontrado para remocao.\n", aluno.nome);
        }
        break;
      }
      case 5:
        imprimeEmOrdem(raiz);
        break;
      case 6:
        imprimeAlunoMaiorNota(raiz);
        break;
      case 7:
        imprimeAlunoMenorNota(raiz);
        break;
      case 8:
        destroiABP(raiz);
        printf("ABP destruida com sucesso!\n");
        break;
      case 9:
      printf("Saindo...\n");
        break;
      default:
        printf("Opcao invalida. Tente novamente.\n");
    }
    
  } while(opcao != 9);
}