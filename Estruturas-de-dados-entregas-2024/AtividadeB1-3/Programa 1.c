#include <stdio.h>

//maior número do array
void maiornumArray(int *array, int tamanho){
  int maior = array[0];

  for (int i = 1; i < tamanho; i++){
    if (array[i] > maior){
      maior = array[i];
    }
  }
  printf("A maior nota é: %d", maior);
}



int main(void) {
  int notas[5];
  int tamanho = sizeof(notas) / sizeof(notas[0]);

  for (int i = 0; i < 5; i++){
    printf("Nota %d: \n", i + 1);
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

  maiornumArray(notas, tamanho);
  
  return 0;
}