#include "header.h"
#include <stdio.h>

void rastrearPacotes(pacote *head) {
    if (head == NULL) {
        printf("Não há pacotes cadastrados.\n");
        return;
    }

    pacote *atual = head;
    printf("Listagem de todos os pacotes:\n");
    while (atual != NULL) {
        printf("ID: %d\n", atual->chave_acesso);
        printf("Cidade de Origem: %s\n", atual->cidade_orig);
        printf("Cidade de Destino: %s\n", atual->cidade_dest);
        printf("Conteúdo: %s\n", atual->conteudo_pacote);
        printf("Status: %s\n\n", atual->status_pacote);
        atual = atual->prox;
    }
}