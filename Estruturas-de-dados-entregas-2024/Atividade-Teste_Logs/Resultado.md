# Resultado dos Registros das "Logs" do executável SOSim
---
## Introdução
Neste relatório, apresentamos os resultados de testes com o executável SOSim, focando na gestão de processos e na ocorrência de falhas, como o "Page Fault". Realizamos quatro simulações, variando a prioridade, o limite de frames e o número de processos para entender como essas mudanças afetam o desempenho do sistema.
### Primeiro Teste

Em nosso primeiro teste, foi realizado a criação de um processo básico:

  - Prioridade: 1
  - Limite de Frames: 1
  - Número de Processos: 1


Primeiramente entrando nos Logs, conseguimos notar um padrão de execução de cada processo. Porém em um determinado tempo, são executados alguns processos com o nome de "Page Fault1", isso é estritamente relacionado com um erro que ocorre quando o programa tenta acessar um determinado dado que não está disponível na Memória Principal, ou então na Memória RAM da máquina.
Para termos um nível de comparação, em aproximadamente 110 processos executados, esse erro ocorreu 3 (Três) vezes, com um intervalo de processo bem-sucedidos entre os erros.

[Log Primeiro Teste](https://github.com/Bruno-Martinho/Fatec-AMS-ED2024-1-1681432412001-Bruno/blob/main/Estruturas-de-dados-entregas-2024/Atividade-Teste_Logs/Logs/Log%20Primeiro%20Teste.txt)

##

### Segundo Teste

Em nosso segundo teste, foi realizada a criação de processos mais robustos:

  - Prioridade 5
  - Limite de Frames: 5
  - Número de Processos: 3

Ao iniciar o teste, nos Logs, podemos notar ao início que já temos algumas situações diferentes do nosso Primeiro Teste.
Como nosso Limite de Frames desse processo foi de 5 (Cinco), então podemos observar que foram alocados 3 (Três) "blocos", com o tamanho de 5 (Cinco) espaços na memória para cada processo criado. Logo após, realizando o início da execução dos processos, um em seguida do outro. Todos os processos criados estão com o mesmo nível de prioridade.
Neste Segundo Teste, já não houve o erro com o nome "Page Fault", como ocorrido no Primeiro Teste.

[Log Segundo Teste](https://github.com/Bruno-Martinho/Fatec-AMS-ED2024-1-1681432412001-Bruno/blob/main/Estruturas-de-dados-entregas-2024/Atividade-Teste_Logs/Logs/Log%20Segundo%20Teste.txt)

##

### Terceiro Teste

  - Prioridade: 2 e 4
  - Limite de Frames: 2
  - Número de Processos: 4

Tivemos um resultado interessante nos Logs em nosso Terceiro Teste.
Primeiramente, foram criados 2 (Dois) processos com Prioridade 2 (Dois), que foram executados normalmente durante um intervalo de tempo. Logo após, foram criados mais 2 (Dois) processos, porém com uma Prioridade 4 (Quatro), maior do que dos processos criados anteriormente, e ai que a situação ficou interessante.
Agora temos um total de 4 (Quatro) processos rodando em nosso programa, porém somente os processos de maior Prioridade estão sendo executados, até o momento em que acontece o erro (Page Fault) de uma vez nos 2 (Dois) processos de maior Prioridade, aonde os 2 (Dois) processo de menor Prioridade voltam a ser executados. E assim o Looping dos processos se inicia.
Notamos que os processos de maior Prioridade assumem o programa, sendo sempre executados, até que por um determinado motivo, ele tenha que parar, e assim fazendo com que os processos de menor Prioridade assuma a responsabilidade de ser executado.

[Log Terceiro Teste](https://github.com/Bruno-Martinho/Fatec-AMS-ED2024-1-1681432412001-Bruno/blob/main/Estruturas-de-dados-entregas-2024/Atividade-Teste_Logs/Logs/Log%20Terceiro%20Teste.txt)

##

### Quarto Teste - Swap de memória

  - Prioridade 1 e 5
  - Limite de Frames 10
  - Numero de Processos: 11

Neste caso, foi realizado o teste de Swap de memória, com o tipo de processo em I/O - bound (disco). Para uma explicação mais simplificada, o Swap de memória é uma técnica de gestão de memória que permite a troca de dados entre a memória RAM, e um espaço de armazenamento secundário (Armazenamento interno, por exemplo).
Seguindo com os testes, colocamos diversos processos para rodar, com prioridades, limites de frames e números de processos, com diversos casos. Com isso, o programa nos retornou uma mensagem de "Lista de pags livres menor que 80%", ou seja, foi obrigado a realizar um Swap de memória para continuar a execução.

[Log Quarto Teste](https://github.com/Bruno-Martinho/Fatec-AMS-ED2024-1-1681432412001-Bruno/blob/main/Estruturas-de-dados-entregas-2024/Atividade-Teste_Logs/Logs/Log%20Quarto%20Teste.txt)
