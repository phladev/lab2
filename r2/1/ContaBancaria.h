#ifndef CONTA_BANCARIA_H
#define CONTA_BANCARIA_H

#include <stdio.h>
#include <string.h>

typedef struct ContaBancaria {
    int numeroDaConta;
    double saldo;
    char nomeDoTitular[50];
} ContaBancaria;

void criarConta(ContaBancaria *c, int numero, char *titular)  {
  c->numeroDaConta = numero;
  strcpy(c->nomeDoTitular, titular);
  c->saldo = 0.0;
}

void depositar(ContaBancaria *c, double valor) {
  if (valor > 0) {
    c->saldo += valor;
  } else {
    printf("Digite um valor positivo.\n");
  }
}

void sacar(ContaBancaria *c, double valor) {
  if (valor > 0 && valor <= c->saldo) {
    c->saldo -= valor;
  } else {
    printf("Saldo insuficiente.\n");
  }
}

double consultarSaldo(ContaBancaria *c) {
  return c->saldo;
}

void imprimirInfo(ContaBancaria *c) {
  printf("Número da Conta: %d\n", c->numeroDaConta);
  printf("Nome do Titular: %s\n", c->nomeDoTitular);
  printf("Saldo: %.2f\n", c->saldo);
}

#endif