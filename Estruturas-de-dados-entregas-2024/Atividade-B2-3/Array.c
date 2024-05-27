/*------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados          */
/*                         Bruno Leonardo Martinho                        */
/*                            Prof Veríssimo                              */
/*                            Atividade-B2-3                              */
/*         Objetivo: Implementar o Numero "30" no meio de outros          */
/*                                 Em um Array.                           */
/*                                                                        */
/*                              Data:27/05/2024                           */
/*------------------------------------------------------------------------*/

#include <stdio.h>
#include <time.h>

int main(void) {
    clock_t start = clock();

    
    int array[5] = {10, 25, 40, 80};
    int array_size = 4;
    int x = 35;
    int middle_index = array_size / 2;

    // Desloca elementos para a direita a partir do meio
    for (int i = array_size; i > middle_index; i--) {
        array[i] = array[i - 1];
    }

    // Insere o novo valor no meio
    array[middle_index] = x;
    array_size++;

    for (int i = 0; i < array_size; i++) {
        printf("%d ", array[i]);
    }

    clock_t end = clock();
    double time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\nTempo de execução: %lf segundos", time);

    return 0;
}
