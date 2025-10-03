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

void cadastroAgendamento(Agendamento) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         CADASTRO AGENDAMENTO                                    |\n");
    printf("|_________________________________________________________________________________________________|\n");

    Agendamento *agen;
    agen = malloc(sizeof(Agendamento));

    printf("\nDigite o ID do agendamento: ");
    scanf("%s", agen->id);

    printf("Digite o CPF do cliente (apenas numeros): ");
    scanf("%s", agen->cpfCliente);

    // Futuramente esse nome deve ser consultado em clientes atraves do cpf
    printf("Digite o nome do cliente: ");
    scanf("%s", agen->nomeCliente);

    printf("Digite o ID do serviço: ");
    scanf("%s", agen->idServico);

    printf("Data: ");
    scanf("%s", agen->data);

    printf("Horário: ");
    scanf("%s", agen->hora);

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

    agen->arquivoAgendamento = fopen("./dados/agendamentos.csv", "at");

    if (agen->arquivoAgendamento == NULL) {
        printf("Erro na criação de arquivoAgendamento");
        exit(1);
    }
    //Escrevendo no arquivoAgendamento
    fprintf(agen->arquivoAgendamento, "%s;", agen->id);
    fprintf(agen->arquivoAgendamento, "%s;", agen->cpfCliente);
    fprintf(agen->arquivoAgendamento, "%s;", agen->nomeCliente);
    fprintf(agen->arquivoAgendamento, "%s;", agen->idServico);
    fprintf(agen->arquivoAgendamento, "%s;", agen->data);
    fprintf(agen->arquivoAgendamento, "%s\n", agen->hora);

    fclose(agen->arquivoAgendamento);

}

void listarAgendamento(Agendamento) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         LISTAR AGENDAMENTO                                      |\n");
    printf("|_________________________________________________________________________________________________|\n");

    Agendamento *agen;
    agen = malloc(sizeof(Agendamento));

    char idAgendamento[50];
    printf("\nDigite o ID do agendamento: ");
    scanf("%s", idAgendamento);
    getchar();

    agen->arquivoAgendamento = fopen("./dados/agendamentos.csv", "rt");

    if (agen->arquivoAgendamento == NULL) {
        printf("Erro na abertura do arquivo Agendamento");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (!feof(agen->arquivoAgendamento)){
        fscanf(agen->arquivoAgendamento, "%[^;]", agen->id);
        fgetc(agen->arquivoAgendamento);
        fscanf(agen->arquivoAgendamento, "%[^;]", agen->cpfCliente);
        fgetc(agen->arquivoAgendamento);
        fscanf(agen->arquivoAgendamento, "%[^;]", agen->nomeCliente);
        fgetc(agen->arquivoAgendamento);
        fscanf(agen->arquivoAgendamento, "%[^;]", agen->idServico);
        fgetc(agen->arquivoAgendamento);
        fscanf(agen->arquivoAgendamento, "%[^;]", agen->data);
        fgetc(agen->arquivoAgendamento);
        fscanf(agen->arquivoAgendamento, "%[^\n]", agen->hora);
        fgetc(agen->arquivoAgendamento);

        if(strcmp(agen->id,idAgendamento) == 0) {
            printf("\n\t\t\t <--- Cliente Encontrado ---> \n\n");
            printf("\t\t\tID: %s\n",agen->id);
            printf("\t\t\tCPF: %s\n",agen->cpfCliente);
            printf("\t\t\tNome: %s\n",agen->nomeCliente);
            printf("\t\t\tID Servico: %s\n",agen->idServico);
            printf("\t\t\tData: %s\n",agen->data);
            printf("\t\t\tHora: %s\n",agen->hora);
            printf("\n>>> Tecle <ENTER> para continuar...\n");
            getchar();
            fclose(agen->arquivoAgendamento);
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
    Agendamento agen;

    char opcao = '9';

    do{

        telaAgendamento();
        printf("Digite a opção desejada: ");
        scanf("%c", &opcao);
        getchar();

        switch (opcao) {

            case '1':
                cadastroAgendamento(agen);
                break;

            case '2':
                listarAgendamento(agen);
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