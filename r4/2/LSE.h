#ifndef LISTASE_H
#define LISTASE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
  int info;
  struct NO* prox;    
}NO;

typedef struct NO* Lista;

Lista* criaLista(){
  Lista *li;
  li = (Lista*) malloc (sizeof(Lista));
  if(li != NULL){
    *li = NULL;
  }
  return li;
}

int listaVazia(Lista *li){
  if(li == NULL) return 1;
  if(*li == NULL) return 1;//True - Vazia!
  return 0;//False - tem elemento!
}

NO* alocarNO(){
  return (NO*) malloc (sizeof(NO));
}

void liberarNO(NO* q){
  free(q);
}

int insereIni(Lista* li, int elem){
  if(li == NULL) return 0;
  NO* novo = alocarNO();
  if(novo == NULL) return 0;
  novo->info = elem;
  novo->prox = *li;
  *li = novo;
  return 1;
}

int insereFim(Lista* li, int elem){
  if(li == NULL) return 0;
  NO* novo = alocarNO();
  if(novo == NULL) return 0;
  novo->info = elem;
  novo->prox = NULL;
  if(listaVazia(li)){
    *li = novo;
  }else{
    NO* aux = *li;
    while(aux->prox != NULL)
      aux = aux->prox;
    aux->prox = novo;
  }
  return 1;
}

int removeIni(Lista* li){
  if(li == NULL) return 0;
  if(listaVazia(li)) return 0;
  NO* aux = *li;
  *li = aux->prox;
  liberarNO(aux);
  return 1;
}

int removeFim(Lista* li){
  if(li == NULL) return 0;
  if(listaVazia(li)) return 0;
  NO* ant, *aux = *li;
  while(aux->prox != NULL){
    ant = aux;
    aux = aux->prox;
  }
  if(aux == *li)
    *li = aux->prox;
  else   
    ant->prox = aux->prox;
  liberarNO(aux);
  return 1;
}

void imprimeLista(Lista* li){
  if(li == NULL) return;
  if(listaVazia(li)){
    printf("Lista Vazia!\n");
    return;
  }
  printf("Elementos:\n");
  NO* aux = *li;
  while(aux != NULL){
    printf("%d ", aux->info);
    aux = aux->prox;
  }
  printf("\n");
}

void recComplementar(NO* n){
  if(n == NULL) return;
  recComplementar(n->prox);
  printf("%d ", n->info);
}

void imprimeRevRec(Lista *li){
  if(li == NULL) return;
  if(listaVazia(li)){
    printf("Lista Vazia!\n");
    return;
  }
  printf("Elementos:\n");
  recComplementar(*li);
  printf("\n");

  //imprimeRevRec(&(*li)->prox);
  //printf("%d ", (*li)->info);
}

void imprimeRev(Lista *li){
  if(li == NULL) return;
  if(listaVazia(li)){
    printf("Lista Vazia!\n");
    return;
  }
  printf("Elementos REV:\n");
  NO* ant, *aux;
  NO* fim = NULL;
  do{
    aux = *li;
    while(aux != fim){
      ant = aux;
      aux = aux->prox;
    }
    printf("%d ", ant->info);
    fim = ant;
  }while(fim != *li);
  printf("\n");
}

int tamanho(Lista *li){
  if(li == NULL) return 0;
  if(listaVazia(li)) return 0;
  int qtd = 0;
  NO* aux = *li;
  while(aux != NULL){
    qtd++;
    aux = aux->prox;
  }
  return qtd;
}

int procura(Lista *li, int x){
  if(li == NULL) return 0;
  if(listaVazia(li)) return 0;
  NO* aux = *li;
  while(aux != NULL){
    if(aux->info == x)
      return 1;
    aux = aux->prox;
  }
  return 0;
}

void destroiLista(Lista* li){
  if(li != NULL){
    NO* aux;
    while((*li) != NULL){
      aux = *li;
      *li = (*li)->prox;
      liberarNO(aux);
    }
    free(li);
  }
}

#endif
