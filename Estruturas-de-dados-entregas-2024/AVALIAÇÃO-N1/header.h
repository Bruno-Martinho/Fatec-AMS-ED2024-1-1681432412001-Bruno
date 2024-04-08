#ifndef HEADER_H
#define HEADER_H

struct Produto {
  int id;
  char nome[50];
  int quantidade;
  struct Produto *prox;
};

typedef struct Produto Produto;

Produto *buscarProduto(Produto *estoque, int id);
void cadastrarProduto(Produto **estoque, int id, char nome[], int quantidade);
void fazerBaixaProduto(Produto **estoque, int id, int quantidade);
void liberarEstoque(Produto *estoque);

#endif