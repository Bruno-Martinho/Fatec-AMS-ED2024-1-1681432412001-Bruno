# Projeto de Verificação Criptográfica - Benchmark

## Equipe
- Bianca Soares
- Bruno Martinho
- Giovanni Cicero
- Ruan Godoi

## Descrição do Negócio

A empresa de segurança cibernética Cyrus necessita monitorar e analisar grandes quantidades de dados criptográficos, garantindo a integridade e segurança das transmissões de dados. Muitos algoritmos de criptografia dependem de números primos para assegurar a robustez dos sistemas. A verificação contínua de números primos nas transmissões de dados é essencial para identificar possíveis falhas ou tentativas de invasão. 

Portanto, este software visa implementar uma solução que verifique a primalidade de números, garantindo que os dados transmitidos permaneçam seguros e confiáveis.

## Macro Solução

A solução proposta é composta por um algoritmo que verifica a integridade dos dados transmitidos, assegurando que os números primos envolvidos na criptografia sejam válidos. A verificação envolve o uso de loops de repetição e recursividade.

### Laços de Repetição

1. **Laço para percorrer os dados transmitidos:**
    - O software irá percorrer grandes quantidades de dados, verificando a presença de possíveis números primos em cada transmissão. Esse loop será implementado com um laço `for`, que passa por cada transmissão de dados.

    ```python
    for data_packet in data_stream:
        # Verificar se o pacote contém números primos
    ```

2. **Laço para verificar os divisores de um número:**
    - Dentro de cada transmissão, será realizado um teste de primalidade para verificar se os números são primos. Um laço `for` será utilizado para dividir o número por todos os valores possíveis até sua raiz quadrada.

    ```python
    def is_prime(num):
        if num < 2:
            return False
        for i in range(2, int(num ** 0.5) + 1):
            if num % i == 0:
                return False
        return True
    ```

3. **Laço para analisar múltiplas sessões de transmissão:**
    - Além de verificar os números primos dentro de uma transmissão específica, será necessário repetir esse processo para múltiplas sessões de transmissão. Isso será feito com um laço `while` para garantir que todas as transmissões sejam processadas.

    ```python
    while has_next_session():
        session = get_next_session()
        for data_packet in session:
            # Processa o pacote de dados
    ```

### Recursividade

A função que verifica a primalidade de um número também pode ser implementada de maneira recursiva. Abaixo está um exemplo de uma função recursiva que verifica se um número é primo:

```python
def is_prime_recursive(num, divisor=2):
    if num < 2:
        return False
    if divisor > int(num ** 0.5):
        return True
    if num % divisor == 0:
        return False
    return is_prime_recursive(num, divisor + 1)
```

## Ferramentas e Linguagens Utilizadas
As seguintes ferramentas e linguagens serão utilizadas para a implementação desta solução:

- Linguagem de Programação: Python
- Ferramentas de Desenvolvimento: Replit e Github
