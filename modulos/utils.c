#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/utils.h"

void recebeNome(char ponteiroNome[]) {
    char nome[50];
    printf("Nome completo: ");
    
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

void recebeDataNascimento(char ponteiroData[]) {
    char data[11];
    int validado = False;

    do {
        printf("Data de nascimento: ");
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

void verificaArquivo(FILE * arquivo) {}

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