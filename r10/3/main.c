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

void trocaPos(int* a, int *b){
	int aux = *a;
	*a = *b;
	*b = aux;
}

void BubbleSort(int *v, int n){
  int j, aux, fim = n;
  do{
    aux = 0;
    for(j=0; j < fim-1; j++){
      comp++;
      if (v[j]>v[j+1]) {
        trocaPos(&v[j], &v[j+1]);
        aux = j;
        mov++; 
      }
    }
    fim--;
  }while(aux != 0);
}

void InsertionSort(int *v, int n){
  int i, j, atual;
  for(i=1; i < n; i++){
    atual = v[i];
    comp++;
    for(j=i; (j>0) && (atual < v[j-1]); j--){
      v[j] = v[j-1];
      mov++;
      comp++;
    }
    v[j] = atual;
  }
}

void SelectionSort(int *v, int n){
  int i, j, menor;
  for(i=0; i < n-1; i++){
    menor = i;
    for(j=i+1; j < n; j++){
      comp++;
      if (v[j] < v[menor]) {
        menor = j;
      }
    }
    if(i != menor){
      trocaPos(&v[i], &v[menor]);
      mov++;
    }
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
  copiar(v, v2, n);
  copiar(v, v3, n);
  copiar(v, v4, n);

  t = clock();
  BubbleSort(v2, n);
  t = clock() - t;
  printf("BubbleSort: \n");
  printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
  printf("Comparacoes: %d\n", comp);
  printf("Movimentacoes: %d\n", mov);

  comp = 0; mov = 0;
  t = clock();
  InsertionSort(v3, n);
  t = clock() - t;
  printf("InsertionSort: \n");
  printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
  printf("Comparacoes: %d\n", comp);
  printf("Movimentacoes: %d\n", mov);

  comp = 0; mov = 0;
  t = clock();
  SelectionSort(v4, n);
  t = clock() - t;
  printf("SelectionSort: \n");
  printf("Tempo Execucao:  %f seconds.\n", ((float)t)/CLOCKS_PER_SEC);
  printf("Comparacoes: %d\n", comp);
  printf("Movimentacoes: %d\n", mov);

  return 0;
}