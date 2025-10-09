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

void cadastrarCliente(Cliente * cliente);

void receberNovoDado(char cpfCliente[], int opcao);
void atualizarCliente(char cpfCliente[], int opcao, char novoDado[]);
void atualizarDado(Cliente * cliente, int opcao, char novoDado[], FILE * arquivo);

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
    
    Cliente * cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));
        
    printf("\nNome completo: ");
    scanf("%[^\n]", cliente->nome);

    printf("CPF: ");
    scanf("%s", cliente->cpf);

    printf("E-mail: ");
    scanf("%s", cliente->email);

    printf("Data de Nascimento (dd/mm/aaaa): ");
    scanf("%s", cliente->data);

    printf("Celular  (apenas números): ");
    scanf("%s", cliente->celular);
    getchar();

    cadastrarCliente(cliente);
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

void cadastrarCliente(Cliente * cliente) {
    criarDiretorio();
    FILE * arquivo = fopen("./dados/clientes.bin", "ab");

    if (arquivo == NULL) {
        printf("Erro na criação de arquivo de Clientes. O programa será finalizado.");
        printf("\n>>> Tecle <ENTER> para encerrar o programa.\n");
        getchar();
        exit(1);
    }
    
    cliente->status = True;
    fwrite(cliente, sizeof(Cliente), 1, arquivo);

    free(cliente);
    fclose(arquivo);
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
void atualizarCliente(char cpfCliente[], int opcao, char dadoNovo[]) {
    Cliente * cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));

    cliente->arquivo = fopen("./dados/clientes.csv", "rt");
    FILE * arquivoNovo = fopen("./dados/clientes_temp.csv", "wt");

    while (fscanf(cliente->arquivo, "%[^;]", cliente->nome) == 1) {
        fgetc(cliente->arquivo);
        fscanf(cliente->arquivo, "%[^;]", cliente->cpf);
        fgetc(cliente->arquivo);
        fscanf(cliente->arquivo, "%[^;]", cliente->email);
        fgetc(cliente->arquivo);
        fscanf(cliente->arquivo, "%[^;]", cliente->data);
        fgetc(cliente->arquivo);
        fscanf(cliente->arquivo, "%[^\n]", cliente->celular);
        fgetc(cliente->arquivo);
        
        if (strcmp(cliente->cpf, cpfCliente) == 0) {
            atualizarDado(cliente, opcao, dadoNovo, arquivoNovo);
        } else {
            fprintf(arquivoNovo, "%s;", cliente->nome);
            fprintf(arquivoNovo, "%s;", cliente->cpf);
            fprintf(arquivoNovo, "%s;", cliente->email);
            fprintf(arquivoNovo, "%s;", cliente->data);
            fprintf(arquivoNovo, "%s\n", cliente->celular);
        }
    }
    fclose(arquivoNovo);
    fclose(cliente->arquivo);

    trocarArquivos("./dados/clientes.csv", "./dados/clientes_temp.csv");
}
void atualizarDado(Cliente * cliente, int opcao, char novoDado[], FILE * arquivo) {
    if (opcao == 1) {
        fprintf(arquivo, "%s;", novoDado);
        fprintf(arquivo, "%s;", cliente->cpf);
        fprintf(arquivo, "%s;", cliente->email);
        fprintf(arquivo, "%s;", cliente->data);
        fprintf(arquivo, "%s\n", cliente->celular);
    } else if (opcao == 2) {
        fprintf(arquivo, "%s;", cliente->nome);
        fprintf(arquivo, "%s;", cliente->cpf);
        fprintf(arquivo, "%s;", novoDado);
        fprintf(arquivo, "%s;", cliente->data);
        fprintf(arquivo, "%s\n", cliente->celular);
    } else if (opcao == 3) {
        fprintf(arquivo, "%s;", cliente->nome);
        fprintf(arquivo, "%s;", cliente->cpf);
        fprintf(arquivo, "%s;", cliente->email);
        fprintf(arquivo, "%s;", novoDado);
        fprintf(arquivo, "%s\n", cliente->celular);
    } else if (opcao == 4) {
        fprintf(arquivo, "%s;", cliente->nome);
        fprintf(arquivo, "%s;", cliente->cpf);
        fprintf(arquivo, "%s;", cliente->email);
        fprintf(arquivo, "%s;", cliente->data);
        fprintf(arquivo, "%s\n", novoDado);
    }
}

void deletarCliente(char cpfCliente[]) {
    Cliente * cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));

    cliente->arquivo = fopen("./dados/clientes.csv", "rt");
    FILE * arquivoNovo = fopen("./dados/clientes_temp.csv", "wt");

    while (fscanf(cliente->arquivo, "%[^;]", cliente->nome) == 1) {
        fgetc(cliente->arquivo);
        fscanf(cliente->arquivo, "%[^;]", cliente->cpf);
        fgetc(cliente->arquivo);
        fscanf(cliente->arquivo, "%[^;]", cliente->email);
        fgetc(cliente->arquivo);
        fscanf(cliente->arquivo, "%[^;]", cliente->data);
        fgetc(cliente->arquivo);
        fscanf(cliente->arquivo, "%[^\n]", cliente->celular);
        fgetc(cliente->arquivo);
        
        if (strcmp(cliente->cpf, cpfCliente) != 0) {
            fprintf(arquivoNovo, "%s;", cliente->nome);
            fprintf(arquivoNovo, "%s;", cliente->cpf);
            fprintf(arquivoNovo, "%s;", cliente->email);
            fprintf(arquivoNovo, "%s;", cliente->data);
            fprintf(arquivoNovo, "%s\n", cliente->celular);
        }
    }
    fclose(arquivoNovo);
    fclose(cliente->arquivo);

    trocarArquivos("./dados/clientes.csv", "./dados/clientes_temp.csv");
}

void exibirCliente(char cpfCliente[]) {
    Cliente * cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));

    cliente->arquivo = fopen("./dados/clientes.csv", "rt");

    if (cliente->arquivo == NULL) {
        printf("Erro na abertura do arquivo clientes");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fscanf(cliente->arquivo, "%[^;]", cliente->nome) == 1) {
        fgetc(cliente->arquivo);
        fscanf(cliente->arquivo, "%[^;]", cliente->cpf);
        fgetc(cliente->arquivo);
        fscanf(cliente->arquivo, "%[^;]", cliente->email);
        fgetc(cliente->arquivo);
        fscanf(cliente->arquivo, "%[^;]", cliente->data);
        fgetc(cliente->arquivo);
        fscanf(cliente->arquivo, "%[^\n]", cliente->celular);
        fgetc(cliente->arquivo);

        if(strcmp(cliente->cpf, cpfCliente) == 0) {
            printf("\n\t\t\t <--- Cliente Encontrado ---> \n\n");
            printf("\t\t\tNome: %s\n", cliente->nome);
            printf("\t\t\tCPF: %s\n", cliente->cpf);
            printf("\t\t\tEmail: %s\n", cliente->email);
            printf("\t\t\tData: %s\n", cliente->data);
            printf("\t\t\tCelular: %s\n", cliente->celular);
            fclose(cliente->arquivo);
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