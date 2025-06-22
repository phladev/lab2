#include <stdio.h>
#include <string.h>

typedef struct{
  char nome[50];
  int idade;
} Pessoa;


void copiar(Pessoa v[], Pessoa v2[], int n) {
  for(int i = 0; i < n; i++) {
    v2[i] = v[i];
  }
}

void trocaPos(Pessoa* a, Pessoa *b){
	Pessoa aux = *a;
	*a = *b;
	*b = aux;
}

void BubbleSortCrescente(Pessoa *v, int n){
  int j, aux, fim = n;
  do{
    aux = 0;
    for(j=0;j < fim-1;j++){
      int cmp = strcmp(v[j].nome, v[j+1].nome);
      if (cmp > 0) {
        trocaPos(&v[j], &v[j+1]);
        aux = j;
      } else if (cmp == 0) {
        if (v[j].idade > v[j+1].idade) {
          trocaPos(&v[j], &v[j+1]);
          aux = j;
        }
      }
    }
    fim--;
  }while(aux != 0);
}

void InsertionSortCrescente(Pessoa *v, int n){
  int i, j;
  Pessoa atual;
  for(i = 1;i < n;i++){
    atual = v[i];
    for(j = i;j > 0;j--){
      int cmp = strcmp(atual.nome, v[j-1].nome);
      if (cmp < 0) {
        v[j] = v[j-1];
      } else if (cmp == 0 && atual.idade < v[j-1].idade) {
        v[j] = v[j-1];
      } else {
        break;
      }
    }
    v[j] = atual;
  }
}

void SelectionSortCrescente(Pessoa *v, int n){
  int i, j, menor;
  for(i = 0;i < n-1;i++){
    menor = i;
    for(j = i+1;j < n;j++){
      int cmp = strcmp(v[j].nome, v[menor].nome);
      if (cmp < 0) {
        menor = j;
      } else if (cmp == 0 && v[j].idade < v[menor].idade) {
        menor = j;
      }
    }
    if(i != menor){
      trocaPos(&v[i], &v[menor]);
    }
  }
}

void BubbleSortDecrescente(Pessoa *v, int n){
  int j, aux, fim = n;
  do{
    aux = 0;
    for(j = 0;j < fim-1;j++){
      int cmp = strcmp(v[j].nome, v[j+1].nome);
      if (cmp < 0) {
        trocaPos(&v[j], &v[j+1]);
        aux = j;
      } else if (cmp == 0) {
        if (v[j].idade < v[j+1].idade) {
          trocaPos(&v[j], &v[j+1]);
          aux = j;
        }
      }
    }
    fim--;
  }while(aux != 0);
}

void InsertionSortDecrescente(Pessoa *v, int n){
  int i, j;
  Pessoa atual;
  for(i = 1;i < n;i++){
    atual = v[i];
    for(j = i;j > 0;j--){
      int cmp = strcmp(atual.nome, v[j-1].nome);
      if (cmp > 0) {
        v[j] = v[j-1];
      } else if (cmp == 0 && atual.idade > v[j-1].idade) {
        v[j] = v[j-1];
      } else {
        break;
      }
    }
    v[j] = atual;
  }
}

void SelectionSortDecrescente(Pessoa *v, int n){
  int i, j, maior;
  for(i = 0;i < n-1;i++){
    maior = i;
    for(j = i+1;j < n;j++){
      int cmp = strcmp(v[j].nome, v[maior].nome);
      if (cmp > 0) {
        maior = j;
      } else if (cmp == 0 && v[j].idade > v[maior].idade) {
        maior = j;
      }
    }
    if(i != maior){
      trocaPos(&v[i], &v[maior]);
    }
  }
}

void imprime(Pessoa v[], int n) {
  for(int i = 0; i < n; i++) {
    printf("%s %d\n", v[i].nome, v[i].idade);
  }
  printf("\n");
}

int main() {
  Pessoa pessoas[5] = {
    {"Alice", 30},
    {"Bob", 25},
    {"Charlie", 35},
    {"Alice", 28},
    {"Bob", 22}
  };
  
  Pessoa copia[5];
  Pessoa copia2[5];
  Pessoa copia3[5];
  Pessoa copia4[5];
  Pessoa copia5[5];
  Pessoa copia6[5];

  copiar(pessoas, copia, 5);
  copiar(pessoas, copia2, 5);
  copiar(pessoas, copia3, 5);
  copiar(pessoas, copia4, 5);
  copiar(pessoas, copia5, 5);
  copiar(pessoas, copia6, 5);
  
  printf("Original:\n");
  imprime(pessoas, 5);
  
  BubbleSortCrescente(copia, 5);
  printf("\nBubble Sort Crescente:\n");
  imprime(copia, 5);
  
  InsertionSortCrescente(copia2, 5);
  printf("\nInsertion Sort Crescente:\n");
  imprime(copia2, 5);

  SelectionSortCrescente(copia3, 5);
  printf("\nSelection Sort Crescente:\n");
  imprime(copia3, 5);

  BubbleSortDecrescente(copia4, 5);
  printf("\nBubble Sort Decrescente:\n");
  imprime(copia4, 5);

  InsertionSortDecrescente(copia5, 5);
  printf("\nInsertion Sort Decrescente:\n");
  imprime(copia5, 5);

  SelectionSortDecrescente(copia6, 5);
  printf("\nSelection Sort Decrescente:\n");
  imprime(copia6, 5);

  return 0;
}