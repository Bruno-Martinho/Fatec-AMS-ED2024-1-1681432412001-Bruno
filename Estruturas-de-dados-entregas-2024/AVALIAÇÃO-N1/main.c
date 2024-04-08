#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  Produto *estoque = NULL;
  int opcao, id, quantidade;
  char nome[50];

  do {
    printf("\n1. Cadastrar Produto\n2. Buscar Produto\n3. Fazer Baixa de "
           "Produto\n0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &opcao);

    switch (opcao) {
    case 1:
      printf("Informe o ID do produto: ");
      scanf("%d", &id);
      printf("Informe o nome do produto: ");
      scanf("%s", nome);
      printf("Informe a quantidade em estoque: ");
      scanf("%d", &quantidade);
      cadastrarProduto(&estoque, id, nome, quantidade);
      break;
    case 2:
      printf("Informe o ID do produto a ser buscado: ");
      scanf("%d", &id);
      buscarProduto(estoque, id);
      break;
    case 3:
      printf("Informe o ID do produto para fazer a baixa: ");
      scanf("%d", &id);
      printf("Informe a quantidade a ser retirada do estoque: ");
      scanf("%d", &quantidade);
      fazerBaixaProduto(&estoque, id, quantidade);
      break;
    case 0:
      printf("Encerrando o programa.\n");
      break;
    default:
      printf("Opção inválida. Tente novamente.\n");
    }
  } while (opcao != 0);

  liberarEstoque(estoque);
  estoque = NULL;
  return 0;
}
