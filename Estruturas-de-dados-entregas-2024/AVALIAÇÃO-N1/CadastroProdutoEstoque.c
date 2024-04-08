#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastrarProduto(Produto **estoque, int id, char nome[], int quantidade) {

    if (buscarProduto(*estoque, id) != NULL) {
        printf("Erro: Produto com ID %d já cadastrado.\n", id);
        return ;
    }


    Produto *novoProduto = (Produto *)malloc(sizeof(Produto));
    if (novoProduto == NULL) {
        printf("Erro: Falha ao alocar memória para o novo produto.\n");
        return;
    }


    novoProduto->id = id;
    strcpy(novoProduto->nome, nome);
    novoProduto->quantidade = quantidade;
    novoProduto->prox = NULL;


    if (*estoque == NULL) {
        *estoque = novoProduto;
    } else {
        Produto *atual = *estoque;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoProduto;
    }

    printf("Produto cadastrado com sucesso!\n");
}
