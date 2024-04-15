#include "header.h"
#include <stdio.h>
#include <string.h>

void alterarPacote(pacote *head, int id, int statusOpcao) {
    pacote *atual = buscarPacote(head, id);
    if (atual == NULL) {
        printf("Pacote com ID %d não encontrado.\n", id);
        return;
    }

    char novoStatus[20];
    switch (statusOpcao) {
    case 1:
        strcpy(novoStatus, "Em processamento");
        break;
    case 2:
        strcpy(novoStatus, "Em trânsito");
        break;
    case 3:
        strcpy(novoStatus, "Em espera");
        break;
    case 4:
        strcpy(novoStatus, "Entregue");
        break;
    case 99:
        strcpy(novoStatus, "Extraviado");
        break;
    default:
        printf("Opção de status inválida.\n");
        return;
    }

    strcpy(atual->status_pacote, novoStatus);
    printf("Status do pacote com ID %d alterado para %s.\n", id, novoStatus);
}
