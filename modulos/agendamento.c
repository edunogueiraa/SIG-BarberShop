#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include "include/agendamento.h"

//Inscriçoes de funcoes

void exibirAgendamento(char idAgendamento[]);
void trocarArquivosAgendamento(char antigo[], char novo[]);
void criarDiretorioAgendamento(void);
void cadastrarAgendamento(Agendamento * agendamento);
void atualizarAgendamento(char idAgendamento[], int opcao);
void deletarAgendamento(char idAgendamento[]);


//Funcoes principais
void telaAgendamento(void) {
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
    printf("|                                         MENU AGENDAMENTO                                        |\n");
    printf("|_________________________________________________________________________________________________|\n");
    printf("|                                                                                                 |\n");
    printf("|                                   1 Cadastrar                                                   |\n");
    printf("|                                   2 Exibir                                                      |\n");
    printf("|                                   3 Listar                                                      |\n");
    printf("|                                   4 Atualizar                                                   |\n");
    printf("|                                   5 Deletar                                                     |\n");
    printf("|                                   0 Sair                                                        |\n");
    printf("|_________________________________________________________________________________________________|\n\n");
}

void cadastroAgendamento(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         CADASTRO AGENDAMENTO                                    |\n");
    printf("|_________________________________________________________________________________________________|\n");

    Agendamento *agendamento;
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));

    printf("\nDigite o ID do agendamento: ");
    scanf("%s", agendamento->id);

    printf("Digite o CPF do cliente (apenas numeros): ");
    scanf("%s", agendamento->cpfCliente);

    printf("Digite o nome do cliente: ");
    scanf("%s", agendamento->nomeCliente);

    printf("Digite o ID do serviço: ");
    scanf("%s", agendamento->idServico);

    printf("Data: ");
    scanf("%s", agendamento->data);

    printf("Horário: ");
    scanf("%s", agendamento->hora);
    getchar();

    cadastrarAgendamento(agendamento);

}

void listaAgendamento(void) {
    Agendamento *agendamento;
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));

    FILE * arquivo = fopen("./dados/agendamentos.bin", "rb");

    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo Agendamento");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fread(agendamento,sizeof(Agendamento),1,arquivo)){
        if (agendamento->status == True) {
            printf("\n\n");
            printf("\t\t\tID: %s\n",agendamento->id);
            printf("\t\t\tCPF: %s\n",agendamento->cpfCliente);
            printf("\t\t\tNome: %s\n",agendamento->nomeCliente);
            printf("\t\t\tID Servico: %s\n",agendamento->idServico);
            printf("\t\t\tData: %s\n",agendamento->data);
            printf("\t\t\tHora: %s\n",agendamento->hora);
            
        }
    }
    fclose(arquivo);
    free(agendamento);

    printf("\n>>> Tecle <ENTER> para encerrar o programa.\n");
    getchar();
}

void exibeAgendamento(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         EXIBIR AGENDAMENTO                                      |\n");
    printf("|_________________________________________________________________________________________________|\n");

    char idAgendamento[50];
    printf("\nDigite o ID do agendamento: ");
    scanf("%s", idAgendamento);
    getchar();

    exibirAgendamento(idAgendamento);

}

void atualizaAgendamento(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         ATUALIZAR AGENDAMENTO                                   |\n");
    printf("|_________________________________________________________________________________________________|\n");

    char idAgendamento[50];
    printf("\nInforme o id (apenas numeros): ");
    scanf("%[^\n]", idAgendamento);
    getchar();

    int opcao;
    do {
        system("clear||cls");
        exibirAgendamento(idAgendamento);

        printf("\nQual dado você deseja alterar?\n");
        printf("\n1 CPF");
        printf("\n2 Nome");
        printf("\n3 ID Servico");
        printf("\n4 Data");
        printf("\n5 Hora");
        printf("\n0 Finalizar operação\n\n");
        scanf("%d", &opcao);
        getchar();
        if (opcao != 0) {
            atualizarAgendamento(idAgendamento, opcao);
        }
    } while (opcao != 0);

}

void deletaAgendamento(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         DELETAR AGENDAMENTO                                     |\n");
    printf("|_________________________________________________________________________________________________|\n");

    char idAgendamento[50];
    printf("\nInforme o id (apenas numeros): ");
    scanf("%[^\n]", idAgendamento);
    getchar();
    
    exibirAgendamento(idAgendamento);

    int excluir;
    printf("\nTem certeza que deseja excluir esse agendamento? (0 - excluir / 1 - cancelar operação): ");
    scanf("%d", &excluir);
    getchar();

    if (excluir == 0) {
        deletarAgendamento(idAgendamento);
        printf("\nAgendamento removido com sucesso.");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
    } else {
        printf("\nOperação cancelada.");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    
}

void opcaoAgendamento() {

    char opcao = '9';

    do{

        telaAgendamento();
        printf("Digite a opção desejada: ");
        scanf("%c", &opcao);
        getchar();

        switch (opcao) {

            case '1':
                cadastroAgendamento();
                break;

            case '2':
                exibeAgendamento();
                break;

            case '3':
                listaAgendamento();
                break;

            case '4':
                atualizaAgendamento();
                break;

            case '5':
                deletaAgendamento();
                break;
        }

    } while (opcao != '0');

}

//Funcoes adicionais

void cadastrarAgendamento(Agendamento * agendamento) {
    criarDiretorioAgendamento();
    FILE * arquivo = fopen("./dados/agendamentos.bin", "ab");

    if (arquivo == NULL) {
        printf("Erro na criação de arquivo de Clientes. O programa será finalizado.");
        printf("\n>>> Tecle <ENTER> para encerrar o programa.\n");
        getchar();
        exit(1);
    }
    
    agendamento->status = True;
    fwrite(agendamento, sizeof(Agendamento), 1, arquivo);

    free(agendamento);
    fclose(arquivo);
}

void atualizarAgendamento(char idAgendamento[], int opcao) {
    char dado[50];
    if (opcao == 1) {
        printf("\nCPF: ");
        scanf("%[^\n]", dado);
    } else if (opcao == 2) {
        printf("\nNome: ");
        scanf("%[^\n]", dado);
    } else if (opcao == 3) {
        printf("\nID Servico: ");
        scanf("%[^\n]", dado);
    } else if (opcao == 4) {
        printf("\nData: ");
        scanf("%[^\n]", dado);
    } else if (opcao == 5) {
        printf("\nHora: ");
        scanf("%[^\n]", dado);
    }

    Agendamento *agendamento;
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));

    FILE * arquivo = fopen("./dados/agendamentos.bin", "r+b");
    int encontrado = False;

    while (fread(agendamento, sizeof(Agendamento), 1, arquivo) && encontrado == False) {
        if (strcmp(idAgendamento, agendamento->id) == 0) {
            if (opcao == 1) {
                strcpy(agendamento->cpfCliente, dado);
            } else if (opcao == 2) {
                strcpy(agendamento->nomeCliente, dado);
            } else if (opcao == 3) {
                strcpy(agendamento->idServico, dado);
            } else if (opcao == 4) {
                strcpy(agendamento->data, dado);
            } else if (opcao == 5) {
                strcpy(agendamento->hora, dado);
            }
            
            encontrado = True;
            fseek(arquivo, (-1) * sizeof(Agendamento), SEEK_CUR);
            fwrite(agendamento, sizeof(Agendamento), 1, arquivo);
        }
    }
    fclose(arquivo);
    free(agendamento);
}

void deletarAgendamento(char idAgendamento[]) {
    Agendamento * agendamento;
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));

    FILE * arquivo = fopen("./dados/agendamentos.bin", "r+b");

    int encontrado = False;
    while (fread(agendamento, sizeof(Agendamento), 1, arquivo) && encontrado == False) {
        if (strcmp(agendamento->id, idAgendamento) == 0) {
            agendamento->status = False;
            encontrado = True;
            fseek(arquivo, (-1) * sizeof(Agendamento), SEEK_CUR);
            fwrite(agendamento, sizeof(Agendamento), 1, arquivo);
        }
    }
    free(agendamento);
    fclose(arquivo);
}

void exibirAgendamento(char idAgendamento[]) {
    Agendamento *agendamento;
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));

    FILE * arquivo = fopen("./dados/agendamentos.bin", "rb");

    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo Agendamento");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

        while (fread(agendamento,sizeof(Agendamento),1,arquivo)){
            if(strcmp(idAgendamento,agendamento->id) == 0 && agendamento->status == True){
                printf("\n\t\t\t <--- Agendamento Encontrado ---> \n\n");
                printf("\t\t\tID: %s\n",agendamento->id);
                printf("\t\t\tCPF: %s\n",agendamento->cpfCliente);
                printf("\t\t\tNome: %s\n",agendamento->nomeCliente);
                printf("\t\t\tID Servico: %s\n",agendamento->idServico);
                printf("\t\t\tData: %s\n",agendamento->data);
                printf("\t\t\tHora: %s\n",agendamento->hora);
                printf("\n>>> Tecle <ENTER> para continuar...\n");
                getchar();
                fclose(arquivo);
                return;
            }
        }

    free(agendamento);
}

void trocarArquivosAgendamento(char antigo[], char novo[]) {
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

void criarDiretorioAgendamento(void) {
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