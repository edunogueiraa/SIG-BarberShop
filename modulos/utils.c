#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

#include "include/utils.h"

void recebeNome(char ponteiroNome[], char tipo[]) {
    char nome[50];
    printf("Digite o nome do %s: ",tipo);
    
    // precisa fazer o método de validar strings aqui, pra ver se o que digitou passa
    // faz um if pra ver se passou coisa certa ou não

    // Só de A a Z
    scanf("%[^\n]", nome);
    getchar();
    
    strcpy(ponteiroNome, nome);
}

void recebeCpf(char ponteiroCpf[]) {
    char cpf[15];
    int validado = False;

    do {
        printf("CPF: ");
        scanf("%[^\n]", cpf);
        getchar();

        // precisa fazer o método de validar strings aqui, pra ver se o que digitou passa
        // faz um if pra ver se passou coisa certa ou não

        // tem que ter @ e terminar em .com
        // validado = validaCpf(cpf);
        validado = True;
    } while (validado == False);

    strcpy(ponteiroCpf, cpf);
}

void recebeId(char ponteiroId[], char tipo[]) {
    char id[50];
    printf("Digite o ID de %s: ",tipo);
    
    scanf("%[^\n]", id);
    getchar();
    
    strcpy(ponteiroId, id);
}

void recebeEmail(char ponteiroEmail[]) {
    char email[50];
    int validado = False;

    do {
        printf("E-mail: ");
        scanf("%[^\n]", email);
        getchar();

        // precisa fazer o método de validar strings aqui, pra ver se o que digitou passa
        // faz um if pra ver se passou coisa certa ou não

        // tem que ter @ e terminar em .com
        // validado = validaEmail(email);
        validado = True;
    } while (validado == False);

    strcpy(ponteiroEmail, email);
}

void recebeData(char ponteiroData[], char tipo[]) {
    char data[11];
    int validado = False;

    do {
        printf("Digite a data do %s: ",tipo);
        scanf("%[^\n]", data);
        getchar();

        // precisa fazer o método de validar strings aqui, pra ver se o que digitou passa
        // faz um if pra ver se passou coisa certa ou não

        // tem que ter @ e terminar em .com
        // validado = validaData(data);
        validado = True;
    } while (validado == False);

    strcpy(ponteiroData, data);
}

void recebeCelular(char ponteiroCelular[]) {
    char celular[12];
    int validado = False;

    do {
        printf("Celular: ");
        scanf("%[^\n]", celular);
        getchar();

        // precisa fazer o método de validar strings aqui, pra ver se o que digitou passa
        // faz um if pra ver se passou coisa certa ou não

        // tem que ter @ e terminar em .com
        // validado = validaCelular(celular);
        validado = True;
    } while (validado == False);

    strcpy(ponteiroCelular, celular);
}

void recebeValor(char ponteiroValor[]) {
    char valor[10];
    int validado = False;

    do {
        printf("Valor: ");
        scanf("%[^\n]", valor);
        getchar();

        // precisa fazer o método de validar strings aqui, pra ver se o que digitou passa
        // faz um if pra ver se passou coisa certa ou não

        // tem que ter @ e terminar em .com
        // validado = validaCpf(cpf);
        validado = True;
    } while (validado == False);

    strcpy(ponteiroValor, valor);
}

void recebeDuracaoTempo(char ponteiroDuracao[]) {
    char duracao[10];
    int validado = False;

    do {
        printf("Duracao: ");
        scanf("%[^\n]", duracao);
        getchar();

        // precisa fazer o método de validar strings aqui, pra ver se o que digitou passa
        // faz um if pra ver se passou coisa certa ou não

        // tem que ter @ e terminar em .com
        // validado = validaCpf(cpf);
        validado = True;
    } while (validado == False);

    strcpy(ponteiroDuracao, duracao);
}

void recebeHora(char ponteiroHora[]) {
    char hora[5];
    int validado = False;

    do {
        printf("Horário: ");
        scanf("%s", hora);
        getchar();

        validado = True;
    } while (validado == False);

    strcpy(ponteiroHora, hora);
}

void recebeOpcao(char ponteiroOpcao[]) {
    char opcao[2];
    printf("Digite a opção desejada: ");
    scanf("%c", opcao);
    getchar();

    strcpy(ponteiroOpcao, opcao);
}

void verificaArquivo(FILE * arquivo) {

    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
        exit(1);
    }
}

void verificaArquivoTemporario(FILE * arquivoTemp) {

    if (arquivoTemp == NULL) {
        printf("Erro na criação de arquivo de agendamento temporario. O programa será finalizado.");
        printf("\n>>> Tecle <ENTER> para encerrar o programa.\n");
        getchar();
        exit(1);
    }
}

void trocaArquivos(char antigo[], char novo[]) {
    int retorno = remove(antigo);
    if (retorno != 0) {
        printf("Houve um erro na exclusão. O programa será finalizado.");
        printf("\n>>> Tecle <ENTER> para encerrar o programa.\n");
        getchar();
        exit(1);
    }

    int renomeacao = rename(novo, antigo);
    if (renomeacao != 0) {
        printf("Houve um erro na renomeação do arquivo. O programa será finalizado.");
        printf("\n>>> Tecle <ENTER> para encerrar o programa.\n");
        getchar();
        exit(1);
    }
    return;
}

void criarDiretorio(void) {
    // Função adaptada de:
    // https://linux.die.net/man/2/mkdir e https://stackoverflow.com/questions/7430248/creating-a-new-directory-in-c
    // Criando diretório para armazenamento de dados
    int status = mkdir("dados", 0700);
    if (status < 0 && errno != EEXIST)
    {
        printf("Houve um erro na criação do diretório de armazenamento de dados. O programa será finalizado.");
        printf("\n>>> Tecle <ENTER> para encerrar o programa.\n");
        getchar();
        exit(1);
    }
}