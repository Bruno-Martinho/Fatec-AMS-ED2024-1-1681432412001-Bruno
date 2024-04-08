
#include "header.h"
#include <stdio.h>

Produto *buscarProduto(Produto *estoque, int id) {
  Produto *atual = estoque;
  while (atual != NULL) {
    if (atual->id == id) {
      printf("Produto encontrado: %s\n", atual->nome);
      return atual;
    }
    atual = atual->prox;
  }
  printf("Produto não encontrado.\n");
  return NULL;
}