#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

pacote *buscarPacote(pacote *head, int id) {
    for (pacote *atual = head; atual != NULL; atual = atual->prox) {
        if (atual->chave_acesso == id) {
            return atual;
        }
    }
    return NULL;
}
