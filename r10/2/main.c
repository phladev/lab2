#include <stdio.h>

void copiar(int v[], int v2[], int n) {
  for(int i = 0; i < n; i++) {
    v2[i] = v[i];
  }
}

void trocaPos(int* a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
}

void BubbleSort(int *v, int n){
  int j, aux, fim = n;
  do{
    aux = 0;
    for(j=0;j < fim-1;j++){
      if (v[j] < v[j+1]) {
        trocaPos(&v[j], &v[j+1]);
        aux = j;
      }
    }
    fim--;
  }while(aux != 0);
}

void InsertionSort(int *v, int n){
  int i, j, atual;
  for(i=1; i < n; i++){
    atual = v[i];
    for(j=i;(j>0) && (atual > v[j-1]);j--){
      v[j] = v[j-1];
    }
    v[j] = atual;
  }
}

void SelectionSort(int *v, int n){
  int i, j, maior;
  for(i=0; i < n-1; i++){
    maior = i;
    for(j=i+1; j < n; j++){
      if (v[j] > v[maior]) {
        maior = j;
      }
    }
    if(i != maior){
      trocaPos(&v[i], &v[maior]);
    }
  }
}

void imprime(int v[], int n) {
  for(int i = 0; i < n; i++) {
    printf("%d ", v[i]);
  }
  printf("\n");
}

int main() {
  int n;
  printf("Escolha a quantidade de elementos do vetor: ");
  scanf("%d", &n);
  int v[n];
  for(int i = 0; i < n; i++) {
    printf("Digite o elemento: ");
    scanf("%d", &v[i]);
  }

  int v2[n];
  int v3[n];
  int v4[n];
  copiar(v, v2, n);
  copiar(v, v3, n);
  copiar(v, v4, n);

  printf("Vetor original: \n");
  imprime(v, n);
  BubbleSort(v2, n);
  printf("BubbleSort: \n");
  imprime(v2, n);
  InsertionSort(v3, n);
  printf("InsertionSort: \n");
  imprime(v3, n);
  SelectionSort(v4, n);
  printf("SelectionSort: \n");
  imprime(v4, n);

  return 0;
}