#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>
#include "include/agendamento.h"

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
    printf("|                                   2 Listar                                                      |\n");
    printf("|                                   3 Atualizar                                                   |\n");
    printf("|                                   4 Deletar                                                     |\n");
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
    agendamento = malloc(sizeof(Agendamento));

    printf("\nDigite o ID do agendamento: ");
    scanf("%s", agendamento->id);

    printf("Digite o CPF do cliente (apenas numeros): ");
    scanf("%s", agendamento->cpfCliente);

    // Futuramente esse nome deve ser consultado em clientes atraves do cpf
    printf("Digite o nome do cliente: ");
    scanf("%s", agendamento->nomeCliente);

    printf("Digite o ID do serviço: ");
    scanf("%s", agendamento->idServico);

    printf("Data: ");
    scanf("%s", agendamento->data);

    printf("Horário: ");
    scanf("%s", agendamento->hora);
    getchar();

    // Função adaptada de:
    // https://linux.die.net/man/2/mkdir e https://stackoverflow.com/questions/7430248/creating-a-new-directory-in-c
    // Criando diretório para armazenamento de dados
    int status = mkdir("dados", 0700);
    if (status < 0 && errno != EEXIST)
    {
        printf("Houve um erro na criação do diretório de armazenamento de dados. O programa será finalizado.");
        printf("\n>>> Tecle <ENTER> para encerrar o programa.\n");
        getchar();
    }

    agendamento->arquivoAgendamento = fopen("./dados/agendamentos.csv", "at");

    if (agendamento->arquivoAgendamento == NULL) {
        printf("Erro na criação de arquivoAgendamento");
        exit(1);
    }
    //Escrevendo no arquivoAgendamento
    fprintf(agendamento->arquivoAgendamento, "%s;", agendamento->id);
    fprintf(agendamento->arquivoAgendamento, "%s;", agendamento->cpfCliente);
    fprintf(agendamento->arquivoAgendamento, "%s;", agendamento->nomeCliente);
    fprintf(agendamento->arquivoAgendamento, "%s;", agendamento->idServico);
    fprintf(agendamento->arquivoAgendamento, "%s;", agendamento->data);
    fprintf(agendamento->arquivoAgendamento, "%s\n", agendamento->hora);

    fclose(agendamento->arquivoAgendamento);

}

void listarAgendamento(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         LISTAR AGENDAMENTO                                      |\n");
    printf("|_________________________________________________________________________________________________|\n");

    Agendamento *agendamento;
    agendamento = malloc(sizeof(Agendamento));

    char idAgendamento[50];
    printf("\nDigite o ID do agendamento: ");
    scanf("%s", idAgendamento);
    getchar();

    agendamento->arquivoAgendamento = fopen("./dados/agendamentos.csv", "rt");

    if (agendamento->arquivoAgendamento == NULL) {
        printf("Erro na abertura do arquivo Agendamento");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (!feof(agendamento->arquivoAgendamento)){
        fscanf(agendamento->arquivoAgendamento, "%[^;]", agendamento->id);
        fgetc(agendamento->arquivoAgendamento);
        fscanf(agendamento->arquivoAgendamento, "%[^;]", agendamento->cpfCliente);
        fgetc(agendamento->arquivoAgendamento);
        fscanf(agendamento->arquivoAgendamento, "%[^;]", agendamento->nomeCliente);
        fgetc(agendamento->arquivoAgendamento);
        fscanf(agendamento->arquivoAgendamento, "%[^;]", agendamento->idServico);
        fgetc(agendamento->arquivoAgendamento);
        fscanf(agendamento->arquivoAgendamento, "%[^;]", agendamento->data);
        fgetc(agendamento->arquivoAgendamento);
        fscanf(agendamento->arquivoAgendamento, "%[^\n]", agendamento->hora);
        fgetc(agendamento->arquivoAgendamento);

        if(strcmp(agendamento->id,idAgendamento) == 0) {
            printf("\n\t\t\t <--- Cliente Encontrado ---> \n\n");
            printf("\t\t\tID: %s\n",agendamento->id);
            printf("\t\t\tCPF: %s\n",agendamento->cpfCliente);
            printf("\t\t\tNome: %s\n",agendamento->nomeCliente);
            printf("\t\t\tID Servico: %s\n",agendamento->idServico);
            printf("\t\t\tData: %s\n",agendamento->data);
            printf("\t\t\tHora: %s\n",agendamento->hora);
            printf("\n>>> Tecle <ENTER> para continuar...\n");
            getchar();
            fclose(agendamento->arquivoAgendamento);
            return;
        }
    }
}

void atualizarAgendamento(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         ATUALIZAR AGENDAMENTO                                   |\n");
    printf("|_________________________________________________________________________________________________|\n");

    printf("\nDigite o ID do agendamento: \n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void deletarAgendamento(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         DELETAR AGENDAMENTO                                     |\n");
    printf("|_________________________________________________________________________________________________|\n");

    printf("\nDigite o ID do agendamento: \n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
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
                listarAgendamento();
                break;

            case '3':
                atualizarAgendamento();
                break;

            case '4':
                deletarAgendamento();
                break;
        }

    } while (opcao != '0');

}