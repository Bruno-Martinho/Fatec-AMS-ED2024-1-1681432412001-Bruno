# PROJETO DE VERIFICAÇÃO CRIPTOGRÁFICA - BENCHMARK

- Bianca Soares
- Bruno Leonardo
- Giovanni Cícero
- Ruan Defavari

---

## Descrição do Negócio

A empresa Cyrus precisa monitorar e analisar grandes volumes de dados criptográficos para garantir a integridade e segurança das transmissões. A verificação constante de números primos é essencial para assegurar a robustez dos algoritmos de criptografia e detectar falhas ou tentativas de invasão.

Este software visa implementar uma solução que verifique a primalidade de números, garantindo que os dados transmitidos permaneçam seguros e confiáveis.

---

## Recursividade vs Iteração

### Recursividade:

- Uma função que se chama a si mesma para resolver subproblemas.
- Boa para problemas recursivos, mas consome mais memória e pode causar stack overflow.

### Iteração:

- Usa estruturas de repetição para executar um bloco de código várias vezes.
- É mais eficiente em termos de memória e performance, mas pode ser mais difícil de entender para problemas naturalmente recursivos.

---

## Solução - Iteração

```c
//Verificar se um número é primo
int is_prime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}
```

### Verificação Inicial:

- Números menores que 2 não são primos. Se `num < 2`, a função retorna 0.

### Loop de Verificação:

- O loop itera de 2 até `sqrt(num)`.
- Se `num` for divisível por qualquer valor `i` nesse intervalo, retorna 0 (não é primo).

### Retorno Final:

- Se nenhum divisor for encontrado, retorna 1 (o número é primo).

---

```c
int main() {
    int data_stream[] = {2, 3, 4, 5, 16, 17, 18, 19, 20};
    int size = sizeof(data_stream) / sizeof(data_stream[0]);
    int primes[size], non_primes[size];
    int prime_count, non_prime_count;

    // Processamento dos dados
    for (int i = 0; i < size; i++) {
        int data_packet = data_stream[i];

        // Verifica se o número é primo ou não e armazena nos arrays correspondentes
        if (is_prime(data_packet)) {
            primes[prime_count] = data_packet;
            prime_count++;
            printf(ANSI_COLOR_GREEN "O número %d é primo.\n" ANSI_COLOR_RESET, data_packet);
        } else {
            non_primes[non_prime_count] = data_packet;
            non_prime_count++;
            printf(ANSI_COLOR_RED "O número %d não é primo.\n" ANSI_COLOR_RESET, data_packet);
        }
    }

    printf("\nTodos os pacotes de dados foram processados.\n");
    return 0;
}
```

### O que a solução faz:

- Verifica se os números do fluxo de dados são primos ou não, armazena-os em arrays separados e exibe o resultado com cores.

### Como funciona:

- Itera sobre um array de números, verifica se são primos com a função `is_prime()`, imprime o resultado colorido e os separa em dois arrays: primos e não primos.

---

## Análise Assintótica - Iteração

### Função `is_prime` (iterativa):

- A função verifica se um número é primo iterando de 2 até a raiz quadrada do número.
- A complexidade dessa função depende do número de iterações do laço, que é \( O(\\sqrt{n}) \), onde \( n \) é o número a ser verificado.
- Como o laço percorre de 2 até \( \\sqrt{n} \), a cada verificação de primalidade de um número o algoritmo faz, no pior caso, \( O(\\sqrt{n}) \) comparações.

### Função `main`:

- A função principal processa um array de tamanho \( m \) (o número de elementos no fluxo de dados), onde cada elemento é verificado se é primo ou não usando a função iterativa.
- A complexidade da função `main` é \( O(m \cdot \\sqrt{n}) \), onde \( m \) é o número de elementos no array e \( n \) é o valor máximo no array.

---

## Solução - Recursividade

```c
int main() {
    // Exemplo de fluxo de dados
    int data_stream[] = {2, 3, 4, 5, 16, 17, 18, 19, 20};
    int size = sizeof(data_stream) / sizeof(data_stream[0]);

    // Processa o fluxo de dados
    process_data_stream(data_stream, size);

    return 0;
}
```

### Função `main`:

- Define um array de números.
- Calcula o tamanho do array.
- Chama `process_data_stream` para verificar a primalidade dos números e imprimir os resultados.

---

```c
//processa uma transmissão de dados
void process_data_stream(int data_stream[], int size) {
    for (int i = 0; i < size; i++) {
        int number = data_stream[i];
        if (is_prime(number)) {
            printf("%d é primo.\n", number);
        } else {
            printf("%d não é primo.\n", number);
        }
    }
}
```

### Função `process_data_stream`:

- Recebe um array de inteiros (`data_stream`) e seu tamanho (`size`).
- Itera por cada número no array e verifica se é primo usando `is_prime`.
- Imprime se o número é primo ou não.

---

```C
//verifica a primalidade de um número
bool is_prime(int num) {
    return is_prime_recursive(num, 2);
}
```

### Função `is_prime`:

- Inicializa a verificação chamando `is_prime_recursive` com o `divisor` começando em 2.

---

```C
//verificar se um número é primo
bool is_prime_recursive(int num, int divisor) {
    if (num < 2) {
        return false;
    }
    if (divisor > sqrt(num)) {
        return true;
    }
    if (num % divisor == 0) {
        return false;
    }
    return is_prime_recursive(num, divisor + 1);
}
```

### Função Recursiva `is_prime_recursive`:

- Verifica se um número (`num`) é primo usando um divisor (`divisor`).
- Retorna `false` se `num` for menor que 2.
- Se o `divisor` é maior que a raiz quadrada de `num`, retorna `true`.
- Se `num` é divisível por `divisor`, retorna `false`.
- Caso contrário, chama-se recursivamente com `divisor` incrementado.

---

## Análise Assintótica - Recursividade

### Fatores de Complexidade:

- Tamanho do fluxo de dados (`size`): O(px)
- Verificação de primalidade para cada número (`n`): O(√n) (máximo de divisores testados)

### Complexidade Total:

- O(px \* √n)

---

## Qual é a Melhor Solução?

Do ponto de vista da análise assintótica, ambos os códigos têm a mesma complexidade O(m \* √n). Contudo, o código **iterativo** tende a ser mais eficiente na prática, especialmente em termos de uso de memória e desempenho, tornando-o uma escolha melhor para a maioria dos casos.

---
