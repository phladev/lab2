#include <stdio.h>
#include "Conjunto.h"

int main () {
  int max = 5;
  Conjunto *conjunto1 = criarConjunto(max);
  Conjunto *conjunto2 = criarConjunto(max);

  printf("Adicionando valores ao conjunto 1:\n");
  for(int i = 0; i < max; i++) {
    int valor;
    scanf("%d", &valor);
    adicionarValor(conjunto1, valor);
  }

  printf("Adicionando valores ao conjunto 2:\n");
  for(int i = 0; i < max; i++) {
    int valor;
    scanf("%d", &valor);
    adicionarValor(conjunto2, valor);
  }
  printf("Conjunto 1:\n");
  imprimeConjunto(conjunto1);
  printf("Conjunto 2:\n");
  imprimeConjunto(conjunto2);

  printf("Tamanho do conjunto 1: %d\n", tamanhoConjunto(conjunto1));
  printf("Tamanho do conjunto 2: %d\n", tamanhoConjunto(conjunto2));
  printf("Maior valor do conjunto 1: %d\n", maiorValor(conjunto1));
  printf("Menor valor do conjunto 1: %d\n", menorValor(conjunto1));
  printf("Maior valor do conjunto 2: %d\n", maiorValor(conjunto2));
  printf("Menor valor do conjunto 2: %d\n", menorValor(conjunto2));
  printf("Os conjuntos sao iguais? %s\n", conjuntosSaoIguais(conjunto1, conjunto2) ? "Sim" : "Nao");

  Conjunto *intersecao = intersecaoConjuntos(conjunto1, conjunto2);
  Conjunto *diferenca = diferencaConjuntos(conjunto1, conjunto2);
  Conjunto *uniao = uniaoConjuntos(conjunto1, conjunto2);
  printf("Intersecao:\n");
  imprimeConjunto(intersecao);
  printf("Diferenca:\n");
  imprimeConjunto(diferenca);
  printf("Uniao:\n");
  imprimeConjunto(uniao);


  removeUltimo(conjunto1);
  printf("Conjunto 1 com remoção do último valor\n");
  imprimeConjunto(conjunto1);
  removeUltimo(conjunto2);
  printf("Conjunto 2 com remoção do último valor\n");
  imprimeConjunto(conjunto2);

  printf("O número 3 está presente no conjunto 1? %s\n", numeroEstaPresente(conjunto1, 3) ? "Sim" : "Nao");
  printf("O número 3 está presente no conjunto 2? %s\n", numeroEstaPresente(conjunto2, 3) ? "Sim" : "Nao");

  printf("O conjunto 1 está vazio? %s\n", conjuntoVazio(conjunto1) ? "Sim" : "Nao");
  printf("O conjunto 2 está vazio? %s\n", conjuntoVazio(conjunto2) ? "Sim" : "Nao");
  
  destruirConjunto(conjunto1);
  destruirConjunto(conjunto2);
  destruirConjunto(intersecao);
  destruirConjunto(diferenca);
  destruirConjunto(uniao);
  return 0;
}
