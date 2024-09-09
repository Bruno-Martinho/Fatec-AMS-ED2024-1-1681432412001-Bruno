/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                           Bruno Martinho                               */
/*             Objetivo: Busca Binária                                    */
/*             Paradigama: - programação Estruturada                      */
/*                                                                        */
/*                             Data:08/09/2024                             */
/*-------------------------------------------------------------------------*/

#include <stdio.h>

int buscaBinaria(int arr[], int l, int r, int x) {
    while (l <= r) {
        int meio = l + (r - l) / 2;

        if (arr[meio] == x)
            return meio;

        if (arr[meio] < x)
            l = meio + 1;
        else
            r = meio - 1;
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int x = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    int resultado = buscaBinaria(arr, 0, n - 1, x);
    (resultado == -1) ? printf("Elemento não encontrado") : printf("Elemento encontrado no índice %d", resultado);
    return 0;
}
