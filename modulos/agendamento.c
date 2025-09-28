#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

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

    FILE * arquivoAgendamento;
    char id[50];
    char cpfCliente[50];
    char nomeCliente[50];
    char idServico[50];
    char data[50];
    char hora[50];

    printf("\nDigite o ID do agendamento: ");
    scanf("%s", id);

    printf("\nDigite o CPF do cliente (apenas numeros): ");
    scanf("%s", cpfCliente);

    // Futuramente esse nome deve ser consultado em clientes atraves do cpf
    printf("Digite o nome do cliente: ");
    scanf("%s", nomeCliente);

    printf("Digite o ID do serviço: ");
    scanf("%s", idServico);

    printf("Data: ");
    scanf("%s", data);

    printf("Horário: ");
    scanf("%s", hora);

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

    arquivoAgendamento = fopen("./dados/agendamentos.csv", "at");

    if (arquivoAgendamento == NULL) {
        printf("Erro na criação de arquivoAgendamento");
        exit(1);
    }
    //Escrevendo no arquivoAgendamento
    fprintf(arquivoAgendamento, "%s;", id);
    fprintf(arquivoAgendamento, "%s;", cpfCliente);
    fprintf(arquivoAgendamento, "%s;", nomeCliente);
    fprintf(arquivoAgendamento, "%s;", idServico);
    fprintf(arquivoAgendamento, "%s;", data);
    fprintf(arquivoAgendamento, "%s\n", hora);

    fclose(arquivoAgendamento);

}

void listarAgendamento(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         LISTAR AGENDAMENTO                                      |\n");
    printf("|_________________________________________________________________________________________________|\n");

    FILE * arquivoAgendamento;
    char id[50];
    char cpfCliente[50];
    char nomeCliente[50];
    char idServico[50];
    char data[50];
    char hora[50];

    char idAgendamento[50];
    printf("\nDigite o ID do agendamento: ");
    scanf("%s", idAgendamento);
    getchar();

    arquivoAgendamento = fopen("./dados/agendamentos.csv", "rt");

    if (arquivoAgendamento == NULL) {
        printf("Erro na abertura do arquivo Agendamento");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (!feof(arquivoAgendamento)){
        fscanf(arquivoAgendamento, "%[^;]", id);
        fgetc(arquivoAgendamento);
        fscanf(arquivoAgendamento, "%[^;]", cpfCliente);
        fgetc(arquivoAgendamento);
        fscanf(arquivoAgendamento, "%[^;]", nomeCliente);
        fgetc(arquivoAgendamento);
        fscanf(arquivoAgendamento, "%[^;]", idServico);
        fgetc(arquivoAgendamento);
        fscanf(arquivoAgendamento, "%[^;]", data);
        fgetc(arquivoAgendamento);
        fscanf(arquivoAgendamento, "%[^\n]", hora);
        fgetc(arquivoAgendamento);

        if(strcmp(id,idAgendamento) == 0) {
            printf("\n\t\t\t <--- Cliente Encontrado ---> \n\n");
            printf("\t\t\tID: %s\n",id);
            printf("\t\t\tCPF: %s\n",cpfCliente);
            printf("\t\t\tNome: %s\n",nomeCliente);
            printf("\t\t\tID Servico: %s\n",idServico);
            printf("\t\t\tData: %s\n",data);
            printf("\t\t\tHora: %s\n",hora);
            printf("\n>>> Tecle <ENTER> para continuar...\n");
            getchar();
            fclose(arquivoAgendamento);
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

void opcaoAgendamento(void) {

    char opcaoAgendamento = '9';

    do{

        telaAgendamento();
        printf("Digite a opção desejada: ");
        scanf("%c", &opcaoAgendamento);
        getchar();

        switch (opcaoAgendamento) {

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

    } while (opcaoAgendamento != '0');

}