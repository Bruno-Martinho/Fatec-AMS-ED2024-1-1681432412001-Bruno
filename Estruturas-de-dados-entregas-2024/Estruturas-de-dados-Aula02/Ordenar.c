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

  int tab[5] = {42, 105, 10, 50, 01};
  int tamanho = sizeof(tab) / sizeof(tab[0]);

  sortTest(tab, tamanho);

  printf("Array em ordem Ascendente: \n");
  for (int i = 0; i < tamanho; i++){
    printf("%d ", tab[i]);
  }
  printf("\n");

  return 0;
}