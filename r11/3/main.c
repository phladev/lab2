#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int comp;
int mov;

void copiar(int v[], int v2[], int n) {
  for(int i = 0; i < n; i++) {
    v2[i] = v[i];
  }
}

void troca(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void copia(int v[], int n, int v2[]) {
  for (int i = 0; i < n; i++) {
    v2[i] = v[i];
  }
}

void shellSort(int v[], int n) {
  int atual, h = 1;
  while(h < n) {
    h = 3 * h + 1;
  }
  while (h > 0) {
    for (int i = h; i < n; i++) {
      atual = v[i];
      int j = i;
      comp++;
      while (j > h - 1 && v[j - h] >= atual) {
        v[j] = v[j - h];
        j -= h;
        mov++;
        comp++;
      }
      v[j] = atual;
    }
    h /= 3;
  }
}

void merge(int v[], int ini, int meio, int fim) {
  int tam = fim - ini + 1;
  int *vtemp = (int *)malloc(tam * sizeof(int));
  int i = ini, j = meio + 1, k = 0;
  while (i <= meio && j <= fim) {
    comp++;
    if(v[i] < v[j]) {
      vtemp[k] = v[i];
      i++;
    } else {
      vtemp[k] = v[j];
      j++;
    }
    k++;
  }
  while (i <= meio) {
    vtemp[k] = v[i];
    i++;
    k++;
  }
  while (j <= fim) {
    vtemp[k] = v[j];
    j++;
    k++;
  }
  for (i = ini, k = 0; i <= fim; i++, k++) {
    v[i] = vtemp[k];
    mov++;
  }
  free(vtemp);
}

void mergeSort(int v[], int ini, int fim) {
  if(fim > ini) {
    int meio = (ini + fim) / 2;
    mergeSort(v, ini, meio);
    mergeSort(v, meio+1, fim);
    merge(v, ini, meio, fim);
  }
}

int particao(int v[], int ini, int fim) {
  int i = ini, j = fim;
  int pivo = v[(ini + fim) / 2];
  while (1){
    comp++;
    while(v[i] < pivo) {
      i++;
      comp++;
    }

    comp++;
    while(v[j] > pivo) {
      j--;
      comp++;
    }
    if(i < j) {
      troca(&v[i], &v[j]);
      mov++;
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

void imprime(int v[], int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

void criaHeap(int v[], int pai, int fim) {
  int aux = v[pai];
  int filho = 2 * pai + 1;
  while(filho <= fim) {
    if(filho < fim && v[filho] < v[filho + 1]) {
      filho++;
    }
    if(aux < v[filho]) {
      v[pai] = v[filho];
      pai = filho;
      filho = 2 * pai + 1;
    } else {
      filho = fim + 1;
    }
  }
  v[pai] = aux;
}

void heapSort(int v[], int n) {
  for(int i = (n -1)/2; i >= 0; i--) {
    criaHeap(v, i, n - 1);
  }
  for(int i = n - 1; i >= 1; i--) {
    troca(&v[0], &v[i]);
    criaHeap(v, 0, i - 1);
  }
}

int main() {
  srand(time(NULL));
  comp = 0; mov = 0;
  clock_t t;
  int n;
  scanf("%d", &n);
  int v[n];
  for(int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }

  int v2[n];
  int v3[n];
  int v4[n];
  int v5[n];
  copiar(v, v2, n);
  copiar(v, v3, n);
  copiar(v, v4, n);
  copiar(v, v5, n);

  t = clock();
  shellSort(v2, n);
  t = clock() - t;
  printf("Shellsort: \n");
  printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
  printf("Comparacoes: %d\n", comp);
  printf("Movimentacoes: %d\n", mov);

  comp = 0; mov = 0;
  t = clock();
  quickSort(v3, 0, n - 1);
  t = clock() - t;
  printf("Quicksort: \n");
  printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
  printf("Comparacoes: %d\n", comp);
  printf("Movimentacoes: %d\n", mov);

  comp = 0; mov = 0;
  t = clock();
  mergeSort(v4, 0, n - 1);
  t = clock() - t;
  printf("Mergesort: \n");
  printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
  printf("Comparacoes: %d\n", comp);
  printf("Movimentacoes: %d\n", mov);

  comp = 0; mov = 0;
  t = clock();
  heapSort(v5, n);
  t = clock() - t;
  printf("Heapsort: \n");
  printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
  printf("Comparacoes: %d\n", comp);
  printf("Movimentacoes: %d\n", mov);

  return 0;
}