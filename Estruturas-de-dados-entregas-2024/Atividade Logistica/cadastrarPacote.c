#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void cadastrarPacote(pacote **head, int id, char *CIDORIG, char *CIDDEST, char *CONTEUDO, char *STATUS) {
    if (buscarPacote(*head, id) != NULL) {
        printf("Erro: Produto com ID %d já cadastrado.\n", id);
        return;
    }

    pacote *novoPacote = (pacote *)malloc(sizeof(pacote));
    if (novoPacote == NULL) {
        printf("Erro: Falha ao alocar memória para o novo pacote.\n");
        return;
    }

    novoPacote->chave_acesso = id;
    strcpy(novoPacote->cidade_orig, CIDORIG);
    strcpy(novoPacote->cidade_dest, CIDDEST);
    strcpy(novoPacote->conteudo_pacote, CONTEUDO);
    strcpy(novoPacote->status_pacote, STATUS);
    novoPacote->prox = NULL;

    if (*head == NULL) {
        *head = novoPacote;
    } else {
        pacote *atual = *head;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoPacote;
    }

    printf("Pacote cadastrado com sucesso!\n");
}
