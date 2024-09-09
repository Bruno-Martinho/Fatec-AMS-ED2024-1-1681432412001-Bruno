/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                           Bruno Leonardo Martinho                      */
/*             Objetivo: Busca Linear Ordenada                            */
/*             Paradigama: - programação Estruturada                      */
/*                                                                        */
/*                             Data:08/09/2024                            */
/*------------------------------------------------------------------------*/

#include <stdio.h>

int buscaLinearOrdenada(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x)
            return i;
        else if (arr[i] > x)
            return -1;    
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]);
    int resultado = buscaLinearOrdenada(arr, n, x);
    (resultado == -1) ? printf("Elemento não encontrado") : printf("Elemento encontrado no índice %d", resultado);
    return 0;
}
