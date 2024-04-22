#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// MODO DE INSERÇÃO
// expressão (5 + 10) * (2 + 3)
// deve ser inserido como:  5 10 + 2 3 + *

#define TAMANHO_MAXIMO 100

typedef struct {
  double itens[TAMANHO_MAXIMO];
  int topo;
} Pilha;

void empilhar(Pilha *p, double valor) { p->itens[++(p->topo)] = valor; }

double desempilhar(Pilha *p) { return p->itens[(p->topo)--]; }

double calcularRPN(char *expressao) {
  Pilha pilha;
  pilha.topo = -1;

  double operando1, operando2;
  char *token = strtok(expressao, " ");

  while (token != NULL) {
    if (isdigit(*token)) {
      empilhar(&pilha, atof(token));
    } else {
      operando2 = desempilhar(&pilha);
      operando1 = desempilhar(&pilha);

      switch (*token) {
      case '+':
        empilhar(&pilha, operando1 + operando2);
        break;
      case '-':
        empilhar(&pilha, operando1 - operando2);
        break;
      case '*':
        empilhar(&pilha, operando1 * operando2);
        break;
      case '/':
        if (operando2 == 0) {
          printf("Erro: Divisão por zero\n");
          exit(EXIT_FAILURE);
        }
        empilhar(&pilha, operando1 / operando2);
        break;
      default:
        printf("Erro: Operador inválido\n");
        exit(EXIT_FAILURE);
      }
    }
    token = strtok(NULL, " ");
  }

  return desempilhar(&pilha);
}

int main() {
  Pilha pilha;
  pilha.topo = -1;

  char expressao[TAMANHO_MAXIMO];
  char continuar;

  do {
    printf("Digite a expressão RPN: ");
    fgets(expressao, TAMANHO_MAXIMO, stdin);
    expressao[strcspn(expressao, "\n")] = '\0';

    printf("Fórmula Algébrica: ");
    for (int i = 0; expressao[i] != '\0'; i++) {
      if ((expressao[i] >= '0' && expressao[i] <= '9') || expressao[i] == ' ' ||
          expressao[i] == '.') {
        printf("%c", expressao[i]);
      } else {
        printf(" %c", expressao[i]);
      }
    }
    printf("\n");

    double resultado = calcularRPN(expressao);
    printf("Resultado: %.2f\n", resultado);

    printf("Deseja continuar (S/N)? ");
    scanf(" %c", &continuar);
    while (getchar() != '\n')
      ;
  } while (continuar == 'S' || continuar == 's');

  return 0;
}
