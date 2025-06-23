#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp;

void troca(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int particao(int v[], int ini, int fim) {
  int i = ini, j = fim;
  int pivo = v[(ini + fim) / 2];
  while (1){
    while(v[i] < pivo) {
      i++;
    }

    while(v[j] > pivo) {
      j--;
    }
    if(i < j) {
      troca(&v[i], &v[j]);
      i++;
      j--;
    } else {
      return j;
    }
  }
  
}

void quickSort(int v[], int ini, int fim) {
  if(fim > ini) {
    int pivo = particao(v, ini, fim);
    quickSort(v, ini, pivo);
    quickSort(v, pivo + 1, fim);
  }
}

int buscaSequencial(int vetor[], int tamanho, int valor) {
  for (int i = 0; i < tamanho; i++) {
    comp++;
    if (vetor[i] == valor) {
      return i;
    }
  }
  return -1; 
}

int buscaBinaria(int v[], int ini, int fim, int valor) {
  int meio;
  while (ini <= fim) {
    meio = (ini + fim) / 2;
    if (v[meio] == valor) {
      comp++;
      return meio;
    } else if (v[meio] < valor) {
      comp++;
      ini = meio + 1;
    } else {
      comp++;
      fim = meio - 1;
    }
  }
  return -1; 
}

void imprimeVetor(int vetor[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    printf("%d ", vetor[i]);
  }
  printf("\n");
}

int main() {
  clock_t t;
  int v[10];
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    v[i] = rand() % 10;
  }

  quickSort(v, 0, 9);
  imprimeVetor(v, 10);
  
  int valor;
  printf("Digite o valor a ser buscado: ");
  scanf("%d", &valor);
  comp = 0;
  t = clock();
  int posicaoSeq = buscaSequencial(v, 100, valor);
  t = clock() - t;
  if (posicaoSeq != -1) {
    printf("Valor encontrado na posicao %d (busca sequencial) com %d comparacoes.\n", posicaoSeq, comp);
    printf("Tempo gasto: %lf segundos.\n\n", ((double)t) / CLOCKS_PER_SEC);
  } else {
    printf("Valor nao encontrado (busca sequencial) com %d comparacoes.\n\n", comp);
  }

  comp = 0;
  t = clock();
  int posicaoBin = buscaBinaria(v, 0, 99, valor);
  t = clock() - t;
  if (posicaoBin != -1) {
    printf("Valor encontrado na posicao %d (busca binaria) com %d comparacoes.\n", posicaoBin, comp);
    printf("Tempo gasto: %lf segundos.\n", ((double)t) / CLOCKS_PER_SEC);
  } else {
    printf("Valor nao encontrado (busca binaria) com %d comparacoes.\n", comp);
  }

  return 0;
}