#include <stdio.h>

void preencherVetor(int vet[], int ini, int fim) {
  if (ini > fim) {
    return;
  }
  scanf("%d", &vet[ini]);
  preencherVetor(vet, ini + 1, fim);
}

void maiorValor(int vet[], int ini, int fim, int *maior) {
  if (ini > fim) {
    return;
  }
  if (vet[ini] > *maior) {
    *maior = vet[ini];
  }
  maiorValor(vet, ini + 1, fim, maior);
}

void imprimeDecrescente(int vet[], int ini, int fim) {
  if (ini > fim) {
    return;
  }
  printf("%d ", vet[fim]);
  imprimeDecrescente(vet, ini, fim - 1);
}

void imprimeCrescente(int vet[], int ini, int fim) {
  if (ini > fim) {
    return;
  }
  printf("%d ", vet[ini]);
  imprimeCrescente(vet, ini + 1, fim);
}

int main() {
  int vet[5];
  preencherVetor(vet, 0, 4);

  printf("Vetor preenchido: ");
  for (int i = 0; i < 5; i++) {
    printf("%d ", vet[i]);
  }
  printf("\n");

  printf("Ordem crescente: ");
  imprimeCrescente(vet, 0, 4);
  printf("\n");
  
  printf("Ordem decrescente: ");
  imprimeDecrescente(vet, 0, 4);
  printf("\n");

  printf("Maior valor: ");
  int maior = vet[0];
  maiorValor(vet, 0, 4, &maior);
  printf("Maior valor: %d\n", maior);
  
  return 0;
}