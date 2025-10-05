#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include "include/cliente.h"

// Assinatura de funções

// funções gerais
void exibirCliente(char cpfCliente[]);
void trocarArquivos(char antigo[], char novo[]);
void criarDiretorio(void);

void cadastrarCliente(char nome[], char cpf[], char email[], char data[], char celular[]);

void receberNovoDado(char cpfCliente[], int opcao);
void atualizarCliente(char cpfCliente[], int opcao, char novoDado[]);
void atualizarDado(char nome[], char cpf[], char email[], char data[], char celular[], int opcao, char novoDado[], FILE * arquivo);

void deletarCliente(char cpfCliente[]);

void telaCliente(void) {
    system("clear||cls");
    printf("_________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|      _____ _____ _____       ______            _               _____ _                          |\n");
    printf("|     /  ___|_   _|  __ \\      | ___ \\          | |             /  ___| |                         |\n");
    printf("|     \\ `--.  | | | |  \\/______| |_/ / __ _ _ __| |__   ___ _ __\\ `--.| |__   ___  _ __           |\n");
    printf("|      `--. \\ | | | | __|______| ___ \\/ _` | '__| '_ \\ / _ \\ '__|`--. \\ '_ \\ / _ \\| '_ \\          |\n");
    printf("|     /\\__/ /_| |_| |_\\ \\      | |_/ / (_| | |  | |_) |  __/ |  /\\__/ / | | | (_) | |_) |         |\n");
    printf("|     \\____/ \\___/ \\____/      \\____/ \\__,_|_|  |_.__/ \\___|_|  \\____/|_| |_|\\___/| .__/          |\n");
    printf("|                                                                                 | |             |\n");
    printf("|                                                                                 |_|             |\n");
    printf("|_________________________________________________________________________________________________|\n");
    printf("|                                                                                                 |\n");
    printf("|                                         MENU CLIENTE                                            |\n");
    printf("|_________________________________________________________________________________________________|\n");
    printf("|                                                                                                 |\n");
    printf("|                                   1 Cadastrar                                                   |\n");
    printf("|                                   2 Listar                                                      |\n");
    printf("|                                   3 Atualizar                                                   |\n");
    printf("|                                   4 Deletar                                                     |\n");
    printf("|                                   0 Sair                                                        |\n");
    printf("|_________________________________________________________________________________________________|\n\n");

}

void cadastroCliente(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         CADASTRO CLIENTE                                        |\n");
    printf("|_________________________________________________________________________________________________|\n");
    char nome[50];
    char cpf[50];
    char email[50];
    char data[50];
    char celular[50];
        
    printf("\nNome completo: ");
    scanf("%[^\n]", nome);

    printf("CPF: ");
    scanf("%s", cpf);

    printf("E-mail: ");
    scanf("%s", email);

    printf("Data de Nascimento (dd/mm/aaaa): ");
    scanf("%s", data);

    printf("Celular  (apenas números): ");
    scanf("%s", celular);
    getchar();

    cadastrarCliente(nome, cpf, email, data, celular);
}

void exibeCliente(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         LISTAR CLIENTE                                          |\n");
    printf("|_________________________________________________________________________________________________|\n");


    char cpfCliente[50];
    printf("\nDigite o cpf do cliente: ");
    scanf("%s", cpfCliente);
    getchar();

    exibirCliente(cpfCliente);
    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualizaCliente(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         ATUALIZAR CLIENTE                                       |\n");
    printf("|_________________________________________________________________________________________________|\n");

    char cpfCliente[50];
    printf("\nInforme o CPF (apenas numeros): ");
    scanf("%[^\n]", cpfCliente);
    getchar();

    int opcao;
    do {
        system("clear||cls");
        exibirCliente(cpfCliente);

        printf("\nQual dado você deseja alterar?\n");
        printf("\n1 Nome");
        printf("\n2 Email");
        printf("\n3 Data de nascimento");
        printf("\n4 Celular");
        printf("\n0 Finalizar operação\n");
        scanf("%d", &opcao);
        getchar();
        if (opcao != 0) {
            receberNovoDado(cpfCliente, opcao);
        }
    } while (opcao != 0);
    
}

void deletaCliente(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         DELETAR CLIENTE                                         |\n");
    printf("|_________________________________________________________________________________________________|\n");

    char cpfCliente[50];
    printf("\nInforme o CPF (apenas numeros): ");
    scanf("%[^\n]", cpfCliente);
    getchar();
    
    exibirCliente(cpfCliente);
    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();

    int excluir;
    printf("\nTem certeza que deseja excluir esse cliente? (0 - excluir / 1 - cancelar operação): ");
    scanf("%d", &excluir);
    getchar();

    if (excluir == 0) {
        deletarCliente(cpfCliente);
        printf("\nCliente removido com sucesso.");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
    } else {
        printf("\nOperação cancelada.");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
}

void opcaoCliente(void) {
    char opcao = '9';

    do {
        telaCliente();
        printf("Digite a opção desejada: ");
        scanf("%c", &opcao);
        getchar();

        switch (opcao) {
            case '1':
                cadastroCliente();
                break;

            case '2':
                exibeCliente();
                break;

            case '3':
                atualizaCliente();
                break;

            case '4':
                deletaCliente();
                break;
        }
    } while (opcao != '0');
}

void cadastrarCliente(char nome[], char cpf[], char email[], char data[], char celular[]) {
    criarDiretorio();
    FILE * arquivoCliente;
    arquivoCliente = fopen("./dados/clientes.csv", "at");

    if (arquivoCliente == NULL) {
        printf("Erro na criação de arquivo de Clientes. O programa será finalizado.");
        printf("\n>>> Tecle <ENTER> para encerrar o programa.\n");
        getchar();
        exit(1);
    }
    //Escrevendo no arquivoCliente
    fprintf(arquivoCliente, "%s;", nome);
    fprintf(arquivoCliente, "%s;", cpf);
    fprintf(arquivoCliente, "%s;", email);
    fprintf(arquivoCliente, "%s;", data);
    fprintf(arquivoCliente, "%s\n", celular);

    fclose(arquivoCliente);
}

// Funcões de atualização de cliente
void receberNovoDado(char cpfCliente[], int opcao) {
    char dado[50];
    if (opcao == 1) {
        printf("\nNome completo: ");
        scanf("%[^\n]", dado);
    } else if (opcao == 2) {
        printf("\nEmail: ");
        scanf("%[^\n]", dado);
    } else if (opcao == 3) {
        printf("\nData: ");
        scanf("%[^\n]", dado);
    } else if (opcao == 4) {
        printf("\nCelular: ");
        scanf("%[^\n]", dado);
    }
    atualizarCliente(cpfCliente, opcao, dado);
}
void atualizarDado(char nome[], char cpf[], char email[], char data[], char celular[], int opcao, char novoDado[], FILE * arquivo) {
    if (opcao == 1) {
        fprintf(arquivo, "%s;", novoDado);
        fprintf(arquivo, "%s;", cpf);
        fprintf(arquivo, "%s;", email);
        fprintf(arquivo, "%s;", data);
        fprintf(arquivo, "%s\n", celular);
    } else if (opcao == 2) {
        fprintf(arquivo, "%s;", nome);
        fprintf(arquivo, "%s;", cpf);
        fprintf(arquivo, "%s;", novoDado);
        fprintf(arquivo, "%s;", data);
        fprintf(arquivo, "%s\n", celular);
    } else if (opcao == 3) {
        fprintf(arquivo, "%s;", nome);
        fprintf(arquivo, "%s;", cpf);
        fprintf(arquivo, "%s;", email);
        fprintf(arquivo, "%s;", novoDado);
        fprintf(arquivo, "%s\n", celular);
    } else if (opcao == 4) {
        fprintf(arquivo, "%s;", nome);
        fprintf(arquivo, "%s;", cpf);
        fprintf(arquivo, "%s;", email);
        fprintf(arquivo, "%s;", data);
        fprintf(arquivo, "%s\n", novoDado);
    }
}
void atualizarCliente(char cpfCliente[], int opcao, char dadoNovo[]) {
    FILE * arquivoAntigo = fopen("./dados/clientes.csv", "rt");
    FILE * arquivoNovo = fopen("./dados/clientes_temp.csv", "wt");
    char nome[50];
    char cpf[50];
    char email[50];
    char data[50];
    char celular[50];

    while (fscanf(arquivoAntigo, "%[^;]", nome) == 1) {
        fgetc(arquivoAntigo);
        fscanf(arquivoAntigo, "%[^;]", cpf);
        fgetc(arquivoAntigo);
        fscanf(arquivoAntigo, "%[^;]", email);
        fgetc(arquivoAntigo);
        fscanf(arquivoAntigo, "%[^;]", data);
        fgetc(arquivoAntigo);
        fscanf(arquivoAntigo, "%[^\n]", celular);
        fgetc(arquivoAntigo);
        
        if (strcmp(cpf, cpfCliente) == 0) {
            atualizarDado(nome, cpf, email, data, celular, opcao, dadoNovo, arquivoNovo);
        } else {
            fprintf(arquivoNovo, "%s;", nome);
            fprintf(arquivoNovo, "%s;", cpf);
            fprintf(arquivoNovo, "%s;", email);
            fprintf(arquivoNovo, "%s;", data);
            fprintf(arquivoNovo, "%s\n", celular);
        }
    }
    fclose(arquivoNovo);
    fclose(arquivoAntigo);

    trocarArquivos("./dados/clientes.csv", "./dados/clientes_temp.csv");
}

void deletarCliente(char cpfCliente[]) {
    FILE * arquivoAntigo = fopen("./dados/clientes.csv", "rt");
    FILE * arquivoNovo = fopen("./dados/clientes_temp.csv", "wt");
    char nome[50];
    char cpf[50];
    char email[50];
    char data[50];
    char celular[50];

    while (fscanf(arquivoAntigo, "%[^;]", nome) == 1) {
        fgetc(arquivoAntigo);
        fscanf(arquivoAntigo, "%[^;]", cpf);
        fgetc(arquivoAntigo);
        fscanf(arquivoAntigo, "%[^;]", email);
        fgetc(arquivoAntigo);
        fscanf(arquivoAntigo, "%[^;]", data);
        fgetc(arquivoAntigo);
        fscanf(arquivoAntigo, "%[^\n]", celular);
        fgetc(arquivoAntigo);
        
        if (strcmp(cpf, cpfCliente) != 0) {
            fprintf(arquivoNovo, "%s;", nome);
            fprintf(arquivoNovo, "%s;", cpf);
            fprintf(arquivoNovo, "%s;", email);
            fprintf(arquivoNovo, "%s;", data);
            fprintf(arquivoNovo, "%s\n", celular);
        }
    }
    fclose(arquivoNovo);
    fclose(arquivoAntigo);

    trocarArquivos("./dados/clientes.csv", "./dados/clientes_temp.csv");
}

void exibirCliente(char cpfCliente[]) {
    FILE * arquivoCliente;
    char nome[50];
    char cpf[50];
    char email[50];
    char data[50];
    char celular[50];

    arquivoCliente = fopen("./dados/clientes.csv", "rt");

    if (arquivoCliente == NULL) {
        printf("Erro na abertura do arquivo clientes");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fscanf(arquivoCliente, "%[^;]", nome) == 1) {
        fgetc(arquivoCliente);
        fscanf(arquivoCliente, "%[^;]", cpf);
        fgetc(arquivoCliente);
        fscanf(arquivoCliente, "%[^;]", email);
        fgetc(arquivoCliente);
        fscanf(arquivoCliente, "%[^;]", data);
        fgetc(arquivoCliente);
        fscanf(arquivoCliente, "%[^\n]", celular);
        fgetc(arquivoCliente);

        if(strcmp(cpf,cpfCliente) == 0) {
            printf("\n\t\t\t <--- Cliente Encontrado ---> \n\n");
            printf("\t\t\tNome: %s\n",nome);
            printf("\t\t\tCPF: %s\n",cpf);
            printf("\t\t\tEmail: %s\n",email);
            printf("\t\t\tData: %s\n",data);
            printf("\t\t\tCelular: %s\n",celular);
            fclose(arquivoCliente);
            return;
        }
    }
}

void trocarArquivos(char antigo[], char novo[]) {
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