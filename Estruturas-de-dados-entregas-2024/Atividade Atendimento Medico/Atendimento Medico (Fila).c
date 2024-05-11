/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                         Bruno Leonardo Martinho                        */
/*                                                                        */
/*                              Data:13/05/2024                           */
/*------------------------------------------------------------------------*/

//ATENÇÃO -- O horário que é mostrado de início e de fim de consulta, acabam aparecendo os mesmos, por conta que quando se atende um paciente, ele sai da fila, entra na consulta e logo sai... Sem ter um tempo de consulta determinado. - Bruno Martinho.

//Quando se "Atende um paciente", o primeiro paciente será o primeiro da fila a ser atendido (seguindo a lógica).

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>


typedef struct {
    char nome[50];
    int idade;
    char motivo[100];
    time_t hora_chegada;
    time_t hora_atendimento_inicio;
    time_t hora_atendimento_fim;
} Paciente;


typedef struct No {
    Paciente paciente;
    struct No* proximo;
} No;


typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} Fila;


void inicializarFila(Fila* fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}


bool filaVazia(Fila* fila) {
    return fila->inicio == NULL;
}


void adicionarPaciente(Fila* fila, Paciente paciente) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->paciente = paciente;
    novoNo->proximo = NULL;

    if (filaVazia(fila)) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }

    fila->tamanho++;
}


Paciente removerPaciente(Fila* fila) {
    if (filaVazia(fila)) {
        printf("Erro: a fila está vazia\n");
        exit(1);
    }

    No* temp = fila->inicio;
    Paciente paciente = temp->paciente;

    fila->inicio = fila->inicio->proximo;
    free(temp);

    fila->tamanho--;

    return paciente;
}


void exibirPaciente(Paciente paciente) {
    printf("Nome: %s\n", paciente.nome);
    printf("Idade: %d\n", paciente.idade);
    printf("Motivo da consulta: %s\n", paciente.motivo);
    printf("Hora de chegada: %s\n", ctime(&paciente.hora_chegada));
}


void visualizarFila(Fila* fila) {
    if (filaVazia(fila)) {
        printf("A fila está vazia.\n");
        return;
    }

    No* atual = fila->inicio;
    int i = 1;
    while (atual != NULL) {
        printf("Paciente %d:\n", i);
        exibirPaciente(atual->paciente);
        printf("\n");
        atual = atual->proximo;
        i++;
    }
}

int main() {
    Fila filaNormal;
    Fila filaPrioritaria;
    Fila filaUrgente;
    Fila filaHistorico;

    inicializarFila(&filaNormal);
    inicializarFila(&filaPrioritaria);
    inicializarFila(&filaUrgente);
    inicializarFila(&filaHistorico);

    int opcao;
    do {
        printf("Escolha uma opção:\n");
        printf("1. Adicionar paciente\n");
        printf("2. Atender paciente\n");
        printf("3. Visualizar filas\n");
        printf("4. Visualizar histórico de atendimentos\n");
        printf("0. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                Paciente paciente;
                printf("Digite o nome do paciente: ");
                scanf("%s", paciente.nome);
                printf("Digite a idade do paciente: ");
                scanf("%d", &paciente.idade);
                printf("Digite o motivo da consulta do paciente: ");
                scanf(" %[^\n]s", paciente.motivo);
                time(&paciente.hora_chegada);

                while(getchar() != '\n');

                if (paciente.idade >= 60 || strcmp(paciente.motivo, "Gestante") == 0) {
                    adicionarPaciente(&filaPrioritaria, paciente);
                } else {
                    char urgente;
                    printf("O paciente tem uma emergência (s/n)? ");
                    scanf(" %c", &urgente);

                    if (urgente == 's' || urgente == 'S') {
                        adicionarPaciente(&filaUrgente, paciente);
                    } else {
                        adicionarPaciente(&filaNormal, paciente);
                    }
                }
                break;
            }
            case 2: {
                printf("Digite o tipo de fila que deseja atender (n/p/u):");

                char filaEscolhida;
                scanf(" %c", &filaEscolhida);

                Paciente pacienteAtendido;

                if (filaEscolhida == 'n' || filaEscolhida == 'N')
                {
                    pacienteAtendido = removerPaciente(&filaNormal);

   
                    time(&pacienteAtendido.hora_atendimento_inicio);
                }

                if (filaEscolhida == 'p' || filaEscolhida == 'P')
                {
                    pacienteAtendido = removerPaciente(&filaPrioritaria);

                   
                    time(&pacienteAtendido.hora_atendimento_inicio);
                }

                if (filaEscolhida == 'u' || filaEscolhida == 'U')
                {
                    pacienteAtendido = removerPaciente(&filaUrgente);

                  
                    time(&pacienteAtendido.hora_atendimento_inicio);
                }

              
                time(&pacienteAtendido.hora_atendimento_fim);


                adicionarPaciente(&filaHistorico, pacienteAtendido);

                printf("Paciente atendido:\n");
                exibirPaciente(pacienteAtendido);

                break;
            }
            case 3: {
                printf("\n--Fila Normal:\n");
                visualizarFila(&filaNormal);
                printf("\n--Fila Prioritaria:\n");
                visualizarFila(&filaPrioritaria);
                printf("\n--Fila Urgente:\n");
                visualizarFila(&filaUrgente);
                break;
            }
            case 4: {
                printf("\nHistórico de atendimentos:\n");
                visualizarFila(&filaHistorico);
                break;
            }
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}
