#ifndef HEADER_H
#define HEADER_H

typedef struct Pacote {
    int chave_acesso;
    char cidade_orig[50];
    char cidade_dest[50];
    char conteudo_pacote[50];
    char status_pacote[20];
    struct Pacote *prox;
} pacote;

pacote *buscarPacote(pacote *head, int id);
void cadastrarPacote(pacote **head, int id, char *CIDORIG, char *CIDDEST, char *CONTEUDO, char *STATUS);
void alterarPacote(pacote *head, int id, int statusOpcao);
void rastrearPacotes(pacote *head);

#endif
