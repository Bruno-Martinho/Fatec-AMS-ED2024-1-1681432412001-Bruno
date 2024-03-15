#include <stdio.h>

void mostrarValores(int *array, int tamanho){
  for (int i = 0; i < tamanho; i++){
    printf("Valor %d: %d\n", i+1, array[i]);
  }
}

int main(void) {
  int notas[5];
  int tamanho = sizeof(notas) / sizeof(notas[0]);

  for (int i = 0; i < 5; i++){
    printf("Digite o valor: \n");
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

  mostrarValores(notas, tamanho);
  
  return 0;
}