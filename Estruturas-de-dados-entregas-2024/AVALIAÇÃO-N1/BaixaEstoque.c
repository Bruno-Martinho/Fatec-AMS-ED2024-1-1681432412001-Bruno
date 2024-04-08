#include "header.h"
#include <stdio.h> 

void fazerBaixaProduto(Produto **estoque, int id, int quantidade) {
    Produto *produto = buscarProduto(*estoque, id);
    if (produto == NULL) {
        printf("Produto não encontrado no estoque.\n");
        return;
    }
    if (produto->quantidade < quantidade) {
        printf("Quantidade em estoque insuficiente.\n");
        return;
    }
    produto->quantidade -= quantidade;
    printf("Baixa realizada com sucesso para o produto %s. Nova quantidade em estoque: %d\n", produto->nome, produto->quantidade);
}
