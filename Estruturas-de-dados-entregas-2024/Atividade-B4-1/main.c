/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                         Bruno Leonardo Martinho                        */
/*                       Paradigama: - Programaação Estruturada           */
/*                                                                        */
/*                            Data:15/10/2024                             */
/*------------------------------------------------------------------------*/

// Neste código, a parte de aprimoramento foi a utilização ddad variável "troca", onde ele verifica se houve alguma troca. Se houve,
// ele troca os elementos, na ordem correta!

#include <stdio.h>

// Bubble Sort
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    int troca;
    for (i = 0; i < n-1; i++) {
        troca = 0; // Verifica se houve trocas
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Troca os elementos
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                troca = 1; // Marca que houve troca
            }
        }
        // Se não houve troca, o array já está ordenado
        if (troca == 0) {
            break;
        }
    }
}

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Informe o número de elementos: ");
    scanf("%d", &n);

    int arr[n];
    printf("Digite os %d números:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Exibe o array original
    printf("Array original: \n");
    printArray(arr, n);

    // chamada da função BubbleSort
    bubbleSort(arr, n);

    // Exibe o array ordenado
    printf("Array ordenado: \n");
    printArray(arr, n);

    return 0;
}
