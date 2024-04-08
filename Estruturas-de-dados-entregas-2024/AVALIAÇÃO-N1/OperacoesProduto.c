#include "header.h"
#include <stdlib.h>

void liberarEstoque(Produto *estoque) {
    Produto *atual = estoque;
    Produto *temp;
    while (atual != NULL) {
        temp = atual;
        atual = atual->prox;
        free(temp);
    }
}
