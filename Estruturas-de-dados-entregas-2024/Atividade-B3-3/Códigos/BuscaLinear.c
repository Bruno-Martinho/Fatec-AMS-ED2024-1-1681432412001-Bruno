/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                           Bruno Leonardo Martinho                      */
/*                         Objetivo: Busca Linear                         */
/*             Paradigama: - programação Estruturada                      */
/*                                                                        */
/*                           Data:08/09/2024                              */
/*------------------------------------------------------------------------*/

#include <stdio.h>

int buscaLinear(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {2, 4, 3, 101, 20};
    int x = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    int resultado = buscaLinear(arr, n, x);
    (resultado == -1) ? printf("Elemento não encontrado") : printf("Elemento encontrado no índice %d", resultado);
    return 0;
}
