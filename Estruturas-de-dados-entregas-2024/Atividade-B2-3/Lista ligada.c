#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definição da estrutura do nó da lista ligada
struct No {
    int data;
    struct No* prox;
};

// Função para imprimir a lista ligada
void percorreLista(struct No* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->prox;
    }
    printf("\n");
}

// Função para criar um novo nó na lista ligada
struct No* criarNo(int valor) {
    struct No* novoNo = (struct No*)malloc(sizeof(struct No));
    novoNo->data = valor;
    novoNo->prox = NULL;
    return novoNo;
}

// Função para inserir um valor no meio da lista ligada
void inserirNovoNo(struct No** headRef, int valor) {
    // Criar novo Nó
    struct No* novoNo = criarNo(valor);

    if (*headRef == NULL) { // Se a Lista for vazia
        *headRef = novoNo;
    } else {
        struct No* atual = *headRef;
        struct No* prev = NULL;

        // Encontrar o ponto médio da lista
        int contar = 0;
        while (atual != NULL) {
            contar++;
            atual = atual->prox;
        }

        int meio = contar / 2;

        // Reiniciar o ponteiro atual
        atual = *headRef;

        // Percorrer a lista até o ponto médio
        for (int i = 0; i < meio; i++) {
            prev = atual;
            atual = atual->prox;
        }

        // Inserir o novo nó no meio
        novoNo->prox = atual;
        if (prev != NULL) {
            prev->prox = novoNo;
        } else { // Se o ponto médio for o primeiro nó
            *headRef = novoNo;
        }
    }
}

int main() {
    clock_t comeca = clock();
    int valor = 35;

    // Lista ligada inicial
    struct No* head = NULL;
    head = criarNo(10);
    head->prox = criarNo(25);
    head->prox->prox = criarNo(40);
    head->prox->prox->prox = criarNo(80);

    // Inserir no meio da lista ligada
    inserirNovoNo(&head, valor);
    printf("Lista ligada após inserção: ");
    percorreLista(head);
    clock_t termina = clock();
    double time = (double)(termina - comeca) / CLOCKS_PER_SEC;
    printf("Tempo de processamento (Lista ligada): %f segundos\n", time);

    return 0;
}
