#include <stdio.h>
#include <string.h>
#include "ContaBancaria.h"

int main() {
  ContaBancaria conta;
  printf("Número da conta: ");
  scanf("%d", &conta.numeroDaConta);
  getchar();
  printf("Seu nome: ");
  fgets(conta.nomeDoTitular, sizeof(conta.nomeDoTitular), stdin);
  conta.nomeDoTitular[strlen(conta.nomeDoTitular) - 1] = '\0';

  criarConta(&conta , conta.numeroDaConta, conta.nomeDoTitular);
  depositar(&conta, 1000);
  printf("Saldo: %.2lf\n",consultarSaldo(&conta));
  sacar(&conta, 500);
  printf("Saldo: %.2lf\n",consultarSaldo(&conta));

  imprimirInfo(&conta);
  return 0;
}