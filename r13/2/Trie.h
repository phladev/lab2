/*---------------- File: Trie.h  -----------------------+
|TAD: Arvore Trie (Geeks for Geeks)                     |
|					      		                        |
|                                                       |
| Adaptado por Guilherme C. Pena em 04/12/2023          |
+-------------------------------------------------------+ */

#ifndef TRIE_H
#define TRIE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Tamanho do alfabeto (# de símbolos)
#define TAMANHO_ALFABETO (26)

// Converte o caractere atual da chave em indice
// use apenas 'a' a 'z' em minúsculas
#define CHAR_PARA_INDICE(c) ((int)c - (int)'a')

// NO da trie
typedef struct TrieNode{
	struct TrieNode* filhos[TAMANHO_ALFABETO];
	// fimPalavra é verdadeiro se o NO representa
	// o final de uma palavra
	bool fimPalavra;
}NO;

// Retorna um novo NO da trie (inicializado como NULL)
NO* criaNO(){
	NO *p = NULL;
	p = (NO *)malloc(sizeof(NO));
	if (p){
		int i;
		p->fimPalavra = false;
		for (i = 0; i < TAMANHO_ALFABETO; i++)
			p->filhos[i] = NULL;
	}
	return p;
}

// Se não estiver presente, insere a chave na trie
// Se a chave eh um prefixo de um NO da trie, apenas marca o NO folha
void inserir(NO *raiz, const char *chave){
	int nivel;
	int comprimento = strlen(chave);
	int indice;
	NO *aux = raiz;
	for (nivel = 0; nivel < comprimento; nivel++){
		indice = CHAR_PARA_INDICE(chave[nivel]);
		if (!aux->filhos[indice])
			aux->filhos[indice] = criaNO();
		aux = aux->filhos[indice];
	}
	// marca o ultimo NO como folha
	aux->fimPalavra = true;
}

// Retorna verdadeiro se a chave estiver presente na trie, caso contrario, falso
bool buscar(NO *raiz, const char *chave){
	int nivel;
	int comprimento = strlen(chave);
	int indice;
	NO *aux = raiz;
	for (nivel = 0; nivel < comprimento; nivel++){
		indice = CHAR_PARA_INDICE(chave[nivel]);
		if (!aux->filhos[indice]){
			printf("Palavra '%s' nao encontrada.\n", chave);
			return false;
		}
		aux = aux->filhos[indice];
	}
	if (aux->fimPalavra) {
		printf("Palavra '%s' encontrada.\n", chave);
		return true;
	} else {
		printf("Palavra '%s' nao encontrada.\n", chave);
		return false;
	}
}

void pre_ordem(NO* raiz, int nivel){
    if(raiz != NULL){
        int i;
        for(i=0; i<26; i++){
            if(raiz->filhos[i] != NULL){
                printf("Nivel %d: ", nivel);
                printf("%c ", (char) 'a' + i);
                if(raiz->filhos[i]->fimPalavra) printf("*");
                printf("\n");
                pre_ordem(raiz->filhos[i], nivel+1);
            }
        }
        
    }
}

void imprimeTrie(NO* raiz){
    if(raiz == NULL) return;
    pre_ordem(raiz, 0);
    printf("\n");
}

#endif
