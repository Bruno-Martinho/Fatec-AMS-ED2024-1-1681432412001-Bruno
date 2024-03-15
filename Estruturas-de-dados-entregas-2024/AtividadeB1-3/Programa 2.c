#include <stdio.h>

void somarArray(int *array, int tamanho){
  int soma = 0;

  for (int i = 0; i < tamanho; i++){
    soma += array[i];
  }
  printf("Resultado da soma das notas : %d", soma);
}

int main(void) {

  int notas[5];
  int total = 0;
  int tamanho = sizeof(notas) / sizeof(notas[0]);

  for (int i = 0; i < 5; i++){
    printf("Digite a nota %d: \n", i + 1);
    scanf("%d", &notas[i]);
  }

  for (int i = 0; i < tamanho - 1; i++) {
    for (int j = 0; j < tamanho - i - 1; j++) {
      if (notas[j] > notas[j + 1]) {
        int temp = notas[j];
        notas[j] = notas[j + 1];
        notas[j + 1] = temp;
      }
    }
  }

  somarArray(notas, tamanho);
  
  return 0;
}