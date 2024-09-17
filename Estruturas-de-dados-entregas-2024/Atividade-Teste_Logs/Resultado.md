# Resultado dos Registros das "Logs" do executável SOSim

## Todos os testes foram realizados com o Tipo de Processo - CPU-Bound;


### Primeiro Teste

Em nosso primeiro teste, foi realizado a criação de um processo básico:

  - Prioridade: 1
  - Limite de Frames: 1
  - Número de Processos: 1


Prmeiramente entrando nas Logs, conseguimos notar um padrão de execução de cada processo. Porém em um determinado tempo, são executados alguns processos com o nome de "Page Fault1", isso é estrítamente relacioado com um erro que ocorre quando o programa tenta acessar um determinado dado que não está disponível na Memoria Principal, ou então na Memoria RAM da máquina.
Para termos um nível de comparação, em aproximadamente 110 processos executados, esse erro ocorreu 3 (Três) vezes, com um intervalo de processo bem sucedidos entre os erros.

[Log Primeiro Teste](https://github.com/Bruno-Martinho/Fatec-AMS-ED2024-1-1681432412001-Bruno/blob/main/Estruturas-de-dados-entregas-2024/Atividade-Teste_Logs/Logs/Log%20Primeiro%20Teste.txt)


### Segundo Teste

Em nosso segundo teste, foi realizada a criação de processos mais robustos:

  - Prioridade 5
  - Limite de Frames: 5
  - Número de Processos: 1

Ao iniciar o teste, nas Logs, podemos notar ao início que já temos algumas situações diferentes do nosso primeiro teste.
Como nosso Limite de Frames desse processo foi de 5 (Cinco), então podemos observar que foram alocados "blocos", com o tamanho de 5 (Cinco) espaços na memoria para cada processo criado. Logo após, realizando o inicio da execução dos processos, um em seguida do outro. Todos os processos criado estão com o mesmo nível de prioridade.
Neste Segundo Teste, já não houve o erro com o nome "Page Fault1", como ocorrido no Primeiro Teste.

