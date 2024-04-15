#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  pacote *pacote_head = NULL;
  int OPT, opcao_status;
  static int ID = 2;
  char CIDORIG[50], CIDDEST[50], STATUS[20], CONTEUDO[50];

  do {
    printf("\n1. Cadastrar Pacote\n2. Alterar Status Pacote\n3. Rastrear "
           "Produtos\n0. Sair\n");
    printf("Escolha uma opção: ");
    scanf("%d", &OPT);

    switch (OPT) {
    case 1:
      printf("Digite a cidade de origem: ");
      scanf("%s", CIDORIG);
      printf("Digite a cidade de destino: ");
      scanf("%s", CIDDEST);
      printf("Digite o conteudo do pacote: ");
      scanf("%s", CONTEUDO);
      printf("Digite o status atual do pacote:\n1. Em processamento\n2. Em "
             "trânsito \n3. Em espera \n4. Entregue \n99. Extraviado \n");
      scanf("%d", &opcao_status);
      switch (opcao_status) {
      case 1:
        strcpy(STATUS, "Em processamento");
        break;
      case 2:
        strcpy(STATUS, "Em trânsito");
        break;
      case 3:
        strcpy(STATUS, "Em espera");
        break;
      case 4:
        strcpy(STATUS, "Entregue");
        break;
      case 99:
        strcpy(STATUS, "Extraviado");
        break;
      }
      cadastrarPacote(&pacote_head, ID, CIDORIG, CIDDEST, CONTEUDO, STATUS);
      printf("Pacote cadastrado com ID %d\n", ID);
      ID += 2;
      break;

    case 2:
      printf("Digite a chave de identificação para alteração: ");
      scanf("%d", &ID);
      printf("Digite o novo status do pacote:\n1. Em processamento\n2. Em "
             "trânsito \n3. Em espera \n4. Entregue \n99. Extraviado \n");
      scanf("%d", &opcao_status);
      alterarPacote(pacote_head, ID, opcao_status);
      break;

    case 3:
      rastrearPacotes(pacote_head);
      break;

    case 0:
      printf("Encerrando programa\n");
      break;

    default:
      printf("Opção inválida.\n");
    }
  } while (OPT != 0);

  return 0;
}
