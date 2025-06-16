#include <stdio.h>
#include <stdlib.h>

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
      while (j > h - 1 && v[j - h] < atual) {
        v[j] = v[j - h];
        j -= h;
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
    if(v[i] > v[j]) {
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
    while(v[i] > pivo) {
      i++;
    }
    while(v[j] < pivo) {
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
    if(filho < fim && v[filho] > v[filho + 1]) {
      filho++;
    }
    if(aux > v[filho]) {
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
  int n;
  scanf("%d", &n);
  int v[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }

  int v2[n];
  copia(v, n, v2);
  int v3[n];
  copia(v, n, v3);
  int v4[n];
  copia(v, n, v4);
  int v5[n];
  copia(v, n, v5);

  printf("Shell Sort:\n");
  shellSort(v2, n);
  imprime(v2, n);

  printf("Merge Sort:\n");
  mergeSort(v3, 0, n - 1);
  imprime(v3, n);

  printf("Quick Sort:\n");
  quickSort(v4, 0, n - 1);
  imprime(v4, n);

  printf("Heap Sort:\n");
  heapSort(v5, n);
  imprime(v5, n);

  return 0;
}