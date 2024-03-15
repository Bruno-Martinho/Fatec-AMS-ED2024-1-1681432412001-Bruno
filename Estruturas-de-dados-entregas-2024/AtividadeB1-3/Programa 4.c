#include <stdio.h>

void multiplicarValores(int *array, int tamanho){
  int result = 1;

  for (int i = 0; i < tamanho; i++){
    result *= array[i];
  }
  printf("Este é o resultado da multiplicação é: %d", result);
}

int main(void) {
  int notas[5];
  int tamanho = sizeof(notas) / sizeof(notas[0]);

  for (int i = 0; i < 5; i++){
    printf("Digite o numero %d: \n", i + 1);
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

  multiplicarValores(notas, tamanho);
  
  return 0;
}