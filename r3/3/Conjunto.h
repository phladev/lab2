#ifndef CONJUNTO_H
#define CONJUNTO_H

#include <stdio.h>
#include <stdlib.h>

typedef struct conjunto {
  int *valores;
  int max;
  int tamanho;
} Conjunto;

int conjuntoVazio(Conjunto *conjunto) {
  return (conjunto == NULL || conjunto->tamanho == 0);
}

void imprimeConjunto(Conjunto *conjunto) {
  if(conjunto != NULL && !conjuntoVazio(conjunto)) {
    for(int i = 0; i < conjunto->tamanho; i++) {
      printf("%d ", conjunto->valores[i]);
    }
    printf("\n");
  }
}

Conjunto* criarConjunto(int max) {
  Conjunto *conjunto = (Conjunto*)malloc(sizeof(Conjunto));
  conjunto->max = max;
  conjunto->tamanho = 0;
  conjunto->valores = (int*)malloc(max * sizeof(int));
  return conjunto;
}

int removeUltimo(Conjunto *conjunto) {
  if(conjunto != NULL && !conjuntoVazio(conjunto)) {
    conjunto->tamanho--;
    return 1;
  }
  return -1;
}

void adicionarValor(Conjunto *conjunto, int valor) {
  if(conjunto != NULL && conjunto->tamanho < conjunto->max) {
    conjunto->valores[conjunto->tamanho] = valor;
    conjunto->tamanho++;
  }
}

int numeroEstaPresente(Conjunto *conjunto, int numero) {
  if(conjunto != NULL && !conjuntoVazio(conjunto)) {
    for(int i = 0; i < conjunto->tamanho; i++) {
      if(conjunto->valores[i] == numero) {
        return 1;
      }
    }
  }
  return 0;
}

Conjunto* intersecaoConjuntos(Conjunto *con1, Conjunto *con2) {
  if(con1 == NULL || con2 == NULL) {
    return NULL;
  }
  Conjunto *intersecao = (Conjunto*)malloc(sizeof(Conjunto));
  intersecao->max = con1->max < con2->max ? con1->max : con2->max;
  intersecao->tamanho = 0;
  intersecao->valores = (int*)malloc(intersecao->max * sizeof(int));
  for (int i = 0; i < con1->tamanho; i++) {
    if (numeroEstaPresente(con2, con1->valores[i]) &&
        !numeroEstaPresente(intersecao, con1->valores[i])) {
      intersecao->valores[intersecao->tamanho++] = con1->valores[i];
    }
  }

  return intersecao;
}

Conjunto* diferencaConjuntos(Conjunto *con1, Conjunto *con2) {
  if (con1 == NULL || con2 == NULL) {
    return NULL;
  }
  Conjunto *diferenca = (Conjunto*)malloc(sizeof(Conjunto));
  diferenca->max = con1->max + con2->max;
  diferenca->tamanho = 0;
  diferenca->valores = (int*)malloc(diferenca->max * sizeof(int));

  for (int i = 0; i < con1->tamanho; i++) {
    int encontrado = 0;
    for (int j = 0; j < con2->tamanho; j++) {
      if (con1->valores[i] == con2->valores[j]) {
        encontrado = 1;
        break;
      }
    }
    if (!encontrado && !numeroEstaPresente(diferenca, con1->valores[i])) {
      diferenca->valores[diferenca->tamanho++] = con1->valores[i];
    }
  }

  for (int i = 0; i < con2->tamanho; i++) {
    int encontrado = 0;
    for (int j = 0; j < con1->tamanho; j++) {
      if (con2->valores[i] == con1->valores[j]) {
        encontrado = 1;
        break;
      }
    }
    if (!encontrado && !numeroEstaPresente(diferenca, con2->valores[i])) {
      diferenca->valores[diferenca->tamanho++] = con2->valores[i];
    }
  }

  return diferenca;
}


Conjunto* uniaoConjuntos(Conjunto *con1, Conjunto *con2) {
  if(con1 == NULL || con2 == NULL) {
    return NULL;
  }
  Conjunto *uniao = (Conjunto*)malloc(sizeof(Conjunto));
  uniao->max = con1->max + con2->max;
  uniao->tamanho = 0;
  uniao->valores = (int*)malloc(uniao->max * sizeof(int));
  for(int i = 0; i < con1->tamanho; i++) {
    if(!numeroEstaPresente(uniao, con1->valores[i])) {
      uniao->valores[uniao->tamanho++] = con1->valores[i];
    }
  }
  for(int i = 0; i < con2->tamanho; i++) {
    if(!numeroEstaPresente(uniao, con2->valores[i])) {
      uniao->valores[uniao->tamanho++] = con2->valores[i];
    }
  }

  return uniao;
}


int tamanhoConjunto(Conjunto *conjunto) {
  if(conjunto != NULL && !conjuntoVazio(conjunto)) {
    return conjunto->tamanho;
  }
  return 0;
}

int maiorValor(Conjunto *conjunto) {
  if(conjunto != NULL && !conjuntoVazio(conjunto)) {
    int maior = conjunto->valores[0];
    for(int i = 1; i < conjunto->tamanho; i++) {
      if(conjunto->valores[i] > maior) {
        maior = conjunto->valores[i];
      }
    }
    return maior;
  }
  return -1;
}

int menorValor(Conjunto *conjunto) {
  if(conjunto != NULL && !conjuntoVazio(conjunto)) {
    int menor = conjunto->valores[0];
    for(int i = 1; i < conjunto->tamanho; i++) {
      if(conjunto->valores[i] < menor) {
        menor = conjunto->valores[i];
      }
    }
    return menor;
  }
  return -1;
}

int conjuntosSaoIguais(Conjunto *con1, Conjunto *con2) {
  if(con1 == NULL || con2 == NULL) {
    return 0;
  }
  if(con1->tamanho != con2->tamanho) {
    return 0;
  }
  for(int i = 0; i < con1->tamanho; i++) {
    if(!numeroEstaPresente(con2, con1->valores[i])) {
      return 0;
    }
  }
  return 1;
}

void destruirConjunto(Conjunto *conjunto) {
  free(conjunto->valores);
  free(conjunto);
}

#endif