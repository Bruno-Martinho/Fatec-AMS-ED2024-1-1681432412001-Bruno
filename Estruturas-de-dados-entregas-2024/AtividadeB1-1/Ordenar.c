#include <stdio.h>

void sortTest(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


int main(void) {

  int numeroInteiros[5];
  int tamanho = sizeof(numeroInteiros) / sizeof(numeroInteiros[0]);

  for (int i = 0; i < 5; i++){
    printf("Coloque números de ordem aleatória: \n" );
    scanf("%d", &numeroInteiros[i]);
  }

  sortTest(numeroInteiros, tamanho);

  printf("Array em ordem Crescente: \n");
  for (int i = 0; i < tamanho; i++){
    printf("%d ", numeroInteiros[i]);
  }
  printf("\n");

  return 0;
}
