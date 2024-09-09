# Análise Assintótica dos algorimos

#### Bruno Leonardo Martinho - 1ºADS - Estrutura de Dados

---

## 1º e 2º Requisito: A análise que sempre considera o pior caso e a demonstração da análise de tempo.

O pior caso sempre será quando o elemento não é encontrado no array.

#### - Busca Linear

| Linha | Código       | Tempo |
| ----- | ------------ | ----- |
| 1     | i = 1        | -     |
| 2     | while i <= n | tn    |
| 3     | if A[i] == x | 2tn   |
| 4     | return i     | 0     |
| 5     | i = i + 1    | 2tn   |
| 6     | return -1    | -     |
|       | Resultado    | 5tn   |

#### - Busca Linear Ordenada

| Linha | Código                    | Tempo |
| ----- | ------------------------- | ----- |
| 1     | i = 1                     | -     |
| 2     | while i <= n and x ≥ A[i] | 3tn   |
| 3     | if A[i] == x              | 2tn   |
| 4     | return i                  | 0     |
| 5     | i = i + 1                 | 2tn   |
| 6     | return -1                 | -     |
|       | Resultado                 | 7tn   |

#### - Busca Binária

| Linha | Código                        | Tempo       |
| ----- | ----------------------------- | ----------- |
| 1     | esq = 1                       | -           |
| 2     | dir = n                       | -           |
| 3     | while esq <= dir              | t(log(n))   |
| 4     | meio = floor((esq + dir) / 2) | 3t(log(n))  |
| 5     | if A[meio] == x               | 2t(log(n))  |
| 6     | return meio                   | 0           |
| 7     | elif x > A[meio]              | 2t(log(n))  |
| 8     | esq = meio + 1                | 2t(log(n))  |
| 9     | else: dir = meio - 1          | 2t(log(n))  |
| 10    | return -1                     | -           |
|       | Resultado                     | 12t(log(n)) |

## 3º Requisito: Simplificação para a notação Big O

##### Busca Linear

5tn = O(n)

##### Busca Linear Ordenada

7tn = O(n)

##### Busca Binária

12t(log(n)) = O(log n)

## 4º Requisito: Demonstre todos os resultado (Big O) de modo gráfico

![Logo do GitHub](https://github.com/Bruno-Martinho/Fatec-AMS-ED2024-1-1681432412001-Bruno/blob/main/Estruturas-de-dados-entregas-2024/Atividade-B3-3/Gr%C3%A1fico/Grafico.png)
