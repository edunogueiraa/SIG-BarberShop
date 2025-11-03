#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <ctype.h>

#include "include/utils.h"

// Funções de validação
int validaNome(char *nome) {

    if (nome == NULL) {
        return False;
    } 

    for (int i = 0; nome[i] != '\0'; ++i) {
        char caractere = nome[i];

        //isalpha verifica se é uma letra
        if (!((isalpha(caractere) || caractere == ' '))) {
            return False;
        }
    }
    return True;
}
int validaCpf(char *cpf) {
    if (cpf == NULL) {
        return False;
    }

    int tamanho = strlen(cpf);
    if (tamanho > 11) {
        return False;
    }
    
    // A partir daqui, adaptada de https://pog-carlos.blogspot.com/2011/11/validacao-de-cpf-em-c-usando-vetor.html
    int numeros[12];
    int soma = 0, digito1, digito2, resultado1, resultado2, valor;
    int i;
    
    // Transforma characteres em números
    for (i = 0; i < 11; i++) {
        numeros[i] = cpf[i] - 48;
        // Esse - 48 é por causa da tabela ASCII, bate certinho com o número e a conversão funciona
    }

    // Guarda as somas para o primeiro dígito
    for (i = 0; i < 9; i++) {
        soma += numeros[i] * (10 - i);
    }

    // Se for divisível por 11/resto for 1, o dígito é 0, senão, dígito é a continha
    resultado1 = soma % 11;
    if ((resultado1 == 0) || (resultado1 == 1)) {
        digito1 = 0;
    } else {
        digito1 = 11 - resultado1;
    }

    soma = 0;
    // Somas para o segundo dígito
    for (i = 0; i < 10; i++)
    {
        soma += numeros[i] * (11 - i);
    }

    // Conta diferente, mas mesma ideia
    valor = (soma / 11) * 11;
    resultado2 = soma - valor;
    if ((resultado2 == 0) || (resultado2 == 1)) {
        digito2 = 0;
    } else {
        digito2 = 11 - resultado2;
    }

    // Compara com os dígitos que tão no CPF
    if ((digito1 == numeros[9]) && (digito2 == numeros[10])) {
        return True;
    } else {
        return False;
    }
}
int validaEmail(char *email) {
    //strchr verifica esse caractere no email
    char *arroba = strchr(email, '@');
    int tamanho = strlen(email);

    if (email == NULL) {
        return False;
    } 

    if (tamanho < 3) {
        return False;
    }

    if (arroba == NULL){
        return False;
    }

    for (int i = 0; email[i] != '\0'; i++) {
        char caractere = email[i];

        if (!((caractere >= 'a' && caractere <= 'z') || (caractere >= '0' && caractere <= '9') || caractere == '.' || caractere == '@')) {
            return False;
        }
    }
    return True;
}
int validaData(char *data) {
    int tamanho = strlen(data);

    if (data == NULL) {
        return False;
    }
    
    if (tamanho > 11) {
        return False;
    }

    for (int i = 0; data[i] != '\0'; i++) {
        char caractere = data[i];

        if (i != 2 && i != 5) {
            if (!isdigit(caractere)){
                return False;
            }
        } else {
            if (caractere != '/') {
                return False;
            }
        }
    }
    return True;
}
int validaCelular(char *celular) {
    int tamanho = strlen(celular);

    if (celular == NULL) {
        return False;
    }
    
    if (tamanho > 12) {
        return False;
    }

    for (int i = 0; celular[i] != '\0'; i++) {
        char digito = celular[i];

        if (!isdigit(digito)){
            return False;
        }
    }
    return True;
}
int validaValor(char *valor) {

    if (valor == NULL) {
        return False;
    }

    for (int i = 0; valor[i] != '\0'; i++) {
        char digito = valor[i];

        if (!isdigit(digito) && digito != '.'){
            return False;
        }
    }
    return True;
}
int validaHora(char *hora) {
    int tamanho = strlen(hora);

    if (hora == NULL) {
        return False;
    }

    if (tamanho != 5 && tamanho != 8) {
        return False;
    }
    
    for (int i = 0; hora[i] != '\0'; i++) {
        char digito = hora[i];

        if ((i == 2 || i == 5)) {
            if (digito != ':') {
                return False;
            }
        } else if (!isdigit(digito)){
            return False;
        }
    }
    return True;
}

// Funções de entrada de dados
void recebeNome(char ponteiroNome[], char tipo[]) {
    char nome[50];
    int validado = False;

    do {
        printf("Digite o nome do %s: ",tipo);
        scanf("%[^\n]", nome);
        getchar();

        if (validaNome(nome)) {
            validado = True;
        } else {
            printf("Nome errado, digite somente letras e espaço!\n");
        }

    } while (validado == False);
    strcpy(ponteiroNome, nome);
}
void recebeCpf(char ponteiroCpf[]) {
    char cpf[15];
    int validado = False;

    do {
        printf("CPF: ");
        scanf("%[^\n]", cpf);
        getchar();
        
        if (validaCpf(cpf)) {
            validado = True;
        } else {
            printf("CPF inválido, por favor digite novamente, usando apenas números!\n");
        }
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

        if (validaEmail(email)) {
            validado = True;
        } else {
            printf("E-mail inválido! Digite novamente.\n");
        }
    } while (validado == 0);
    strcpy(ponteiroEmail, email);
}
void recebeData(char ponteiroData[], char tipo[]) {
    char data[11];
    int validado = False;

    do {
        printf("Digite a data do %s: ",tipo);
        scanf("%[^\n]", data);
        getchar();

        if (validaData(data)) {
            validado = True;
        } else {
            printf("Data inválida, por favor digite novamente!\n");
        }
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

        if (validaCelular(celular)) {
            validado = True;
        } else {
            printf("Celular errado, digite apenas numeros, incluindo DDD!\n");
        }
    } while (validado == False);

    strcpy(ponteiroCelular, celular);
}
void recebeTipo(char ponteiroTipo[]) {
    char tipo[20];
    int validado = False;

    do {
        printf("Tipo do produto: ");
        scanf("%[^\n]", tipo);
        getchar();
        if (validaNome(tipo)) {
            validado = True;
        } else {
            printf("Tipo errado, digite somente letras e espaço!\n");
        }
    } while (validado == False);

    strcpy(ponteiroTipo, tipo);
}
void recebeValor(char ponteiroValor[]) {
    char valor[10];
    int validado = False;

    do {
        printf("Valor: ");
        scanf("%[^\n]", valor);
        getchar();

        if (validaValor(valor)) {
            validado = True;
        } else {
            printf("Valor errado! Digite apenas um valor numérico. Ex: 13.50\n");
        }

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

        validado = True;
    } while (validado == False);

    strcpy(ponteiroDuracao, duracao);
}
void recebeHora(char ponteiroHora[]) {
    char hora[9];
    int validado = False;

    do {
        printf("Horário: ");
        scanf("%s", hora);
        getchar();

        if (validaHora(hora)) {
            validado = True;
        } else {
            printf("Hora inválida. Por favor use o formato HH:MM:SS ou apenas HH:MM.\n");
        }
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

// Funções de exibicao
void exibeValor(char *valor) {
    float valorFormatado = atof(valor);
    printf("\t\t\tValor: R$ %.2f\n", valorFormatado);
}
void exibeCpf(char *cpf) {
    char formatado[15];
    
    int posicao = 0;
    for (int i = 0; cpf[i] != '\0'; ++i) {
        if (i == 3 || i == 6) {
            formatado[posicao++] = '.';
        } else if (i == 9) {
            formatado[posicao++] = '-';
        }
        formatado[posicao++] = cpf[i];
    }

    formatado[posicao] = '\0';
    printf("\t\t\tCPF: %s\n", formatado);
}
void exibeCelular(char *celular) {
    char formatado[15];
    
    int posicao = 0;
    for (int i = 0; celular[i] != '\0'; ++i) {
        if (i == 0) {
            formatado[posicao++] = '(';
        } else if (i == 2) {
            formatado[posicao++] = ')';
        } else if (i == 7) {
            formatado[posicao++] = '-';
        }
        formatado[posicao++] = celular[i];
    }

    formatado[posicao] = '\0';
    printf("\t\t\tCelular: %s\n", formatado);
}

// Funções de verificação de arquivos
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
int verificaItensArquivo(FILE *arquivo, int tamanho) {
    // Adaptado da geração automática da IA do Google
    fseek(arquivo, 0, SEEK_END);
    long int bytes = ftell(arquivo);
    int quantidade = bytes / tamanho;
    return quantidade;
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