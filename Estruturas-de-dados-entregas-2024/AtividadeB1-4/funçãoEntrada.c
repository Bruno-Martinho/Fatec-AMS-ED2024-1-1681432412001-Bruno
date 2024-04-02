#include <stdio.h>
#include <stdlib.h> // Para a função malloc

struct lista {
    int info;
    struct lista* prox;
};
typedef struct lista Lista;

// Função de criação: retorna uma lista vazia
Lista* lst_cria(void) {
    return NULL;
}

// Inserção no início: retorna a lista atualizada
Lista* lst_insere(Lista* l, int i) {
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;     
}

// Função imprime: Imprime valores dos elementos
void lst_imprime(Lista* l) {
    Lista* p;

    for (p = l; p != NULL; p = p->prox)
        printf("%d\n", p->info);
}

// Função vazia: retorna 1 se vazia; 0 se não vazia
int lst_vazia(Lista* l) {
    if (l == NULL)
        printf("Lista V A Z I A\n");
    else
        printf("Lista Nao Vazia\n");
}

// Função busca: Busca um elemento na lista
int lst_busca(Lista* l, int v) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->info == v) {
            printf("Encontrou: %d\n", v);
            return 1;
        }
    }
    printf("Nao encontrou: %d\n", v);
    return 0;
}

// Função deleta: deleta elemento da lista
int lst_deleta(Lista* l, int v) {
    Lista* ant = NULL; // ponteiro para elemento anterior  
    Lista* p = l;      // ponteiro para percorrer a lista

    // procura elemento na lista, guardando anterior
    while (p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
    }

    // Verifica se achou elemento
    if (p == NULL) {
        printf("Nao encontrou elemento para DELETAR :  %d\n", v);
        return 1; // não achou, retorna lista original
    }

    // Retira elemento
    if (ant == NULL) {
        // retira elemento do início
        l = p->prox;
    } else {
        // retira elemento do meio da lista
        ant->prox = p->prox;
    }

    free(p); // Utilizada para limpar o número da memória...
    return 0;
}

// Função libera: "Destroi" a lista da memória
// Função libera: "Destroi" a lista da memória
void lst_libera(Lista* l) {
    Lista* p = l;
    Lista* t;

    while (p != NULL) {
        t = p;
        p = p->prox;
        free(t);
    }
}

// Função para exibir o menu de opções
int exibir_menu() {
    int opcao;
    printf("Escolha uma opcao:\n");
    printf("0. Sair\n");
    printf("1. Incluir elemento\n");
    printf("2. Consultar elemento\n");
    printf("3. Deletar elemento\n");
    printf("4. Listar elementos\n");
    printf("5. Liberar lista\n"); //Pensava que era necessário, mas não foi...
    printf("Opcao: ");
    scanf("%d", &opcao);
    return opcao;
}

int main(void) {
    Lista* l = lst_cria(); // Declara uma lista não inicializada
    int opcao;

    do {
        opcao = exibir_menu();

        switch (opcao) {
            case 1: {
                int valor;
                printf("Digite o valor a ser incluido: ");
                scanf("%d", &valor);
                l = lst_insere(l, valor);
                break;
            }
            case 2: {
                int valor;
                printf("Digite o valor a ser consultado: ");
                scanf("%d", &valor);
                lst_busca(l, valor);
                break;
            }
            case 3: {
                int valor;
                printf("Digite o valor a ser deletado: ");
                scanf("%d", &valor);
                lst_deleta(l, valor);
                break;
            }
            case 4: {
              lst_imprime(l);
              break;
            }
            case 5: {
                lst_libera(l);
                printf("Lista liberada da memoria.\n");
                l = lst_cria();
                break;
            }
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
