#ifndef LISTA_ESTATICA_H
#define LISTA_ESTATICA_H

#include <stdio.h>
#include <stdlib.h>

# define MAX 10
typedef struct {
  int dados[MAX];
  int qtd;
} Lista;

Lista* criaLista(){
  Lista* li;
  li = (Lista*)malloc(sizeof(Lista));
  if(li != NULL)
    li->qtd = 0;
  return li;
}

void destroiLista(Lista *li){
  if(li != NULL)
    free(li);
}

int tamanhoLista(Lista *li){
  if(li == NULL)
    return -1;
  return li->qtd;
}

int listaCheia(Lista *li){
  if(li == NULL)
    return -1;
  return (li->qtd == MAX);
}

int listaVazia(Lista *li){
  if(li == NULL)
    return -1;
  return (li->qtd == 0);
}

int insereFim(Lista* li, int elem){
  if(li == NULL) return 0;
  if(!listaCheia(li)){
    li->dados[li->qtd] = elem;
    li->qtd++;
    return 1;
  }else{
    return 0;
  }
}

int insereIni(Lista* li, int elem){
  if(li == NULL) return 0;
  if(!listaCheia(li)){
    int i;
    for(i=li->qtd; i>0; i--){
        li->dados[i] = li->dados[i-1];
    }
    li->dados[0] = elem;
    li->qtd++;
    return 1;
  }else{
    return 0;
  }
}

int imprimeLista(Lista *li){
  if(li == NULL) return 0;
  int i;
  printf("Elementos:\n");
  for(i=0; i<li->qtd; i++){
    printf("%d ", li->dados[i]);
  }
  printf("\n");
  return 1;
}

int removeFim(Lista* li){
  if(li == NULL) return 0;
  if(!listaVazia(li)){
    li->qtd--;
    return 1;
  }else return 0;
}

int removeIni(Lista *li){
  if(li == NULL ) return 0;
  if(!listaVazia(li)){
    int i;
    for(i=0; i<li->qtd-1; i++)
        li->dados[i] = li->dados[i+1];
    li->qtd--;
    return 1;
  } else{
    return 0;
  }
}

int ordenaLista(Lista *li) {
  if(li == NULL) return -1;
  if(!listaVazia(li)){
    for (int i = 0; i < li->qtd - 1; i++) {
      for (int j = i + 1; j < li->qtd; j++) {
        if (li->dados[i] > li->dados[j]) {
          int temp = li->dados[i];
          li->dados[i] = li->dados[j];
          li->dados[j] = temp;
        }
      }
    }
    return 1;
  } else {
    return 0;
  }
}

int insereOrdenado(Lista *li, int x) {
  if(li == NULL || li->qtd == MAX) return -1;
  if(!listaCheia(li)){
    ordenaLista(li);
    int i = 0;
    while(i < li->qtd && li->dados[i] < x) {
      i++;
    }
    for(int j = li->qtd; j > i; j--) {
      li->dados[j] = li->dados[j - 1];
    }
    li->dados[i] = x;
    li->qtd++;
    return 1;
  } else {
    return 0;
  } 
  return -1;
}

int procura(Lista *li, int x) {
  if(li == NULL) return -1;
  if(!listaVazia(li)) {
    for (int i = 0; i < li->qtd; i++) {
      if (li->dados[i] == x) {
        return i;
      }
    }    
    return 0;
  }
  return -1;
}

int removeElemento(Lista *li, int x) {
  if(li == NULL) return -1;
  if(!listaVazia(li)){
    int i = procura(li, x);
    if (i != -1) {
      for (int j = i; j < li->qtd - 1; j++) {
        li->dados[j] = li->dados[j + 1];
      }
      li->qtd--;
    }
    return 1;
  }
  return -1;
}

#endif