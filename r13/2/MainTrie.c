#include <stdio.h>
#include "Trie.h"


// Função principal
int main(){
	char chaves[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
	char saida[][32] = {"Nao encontrada na TRIE", "Encontrada na TRIE"};

	NO *raiz = criaNO();
	int i;
	for (i = 0; i < 8; i++) {
		inserir(raiz, chaves[i]);
	}

	printf("Resultado:\n");
	imprimeTrie(raiz);

	return 0;
}
