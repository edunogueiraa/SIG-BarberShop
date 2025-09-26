#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

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

    FILE * arquivo;
    char cpfCliente[50];
    char nomeCliente[50];
    int idServico;
    char data[50];
    char hora[50];

    printf("\nDigite o CPF do cliente (apenas numeros): ");
    scanf("%s", cpfCliente);

    printf("Digite o nome do cliente: ");
    scanf("%s", nomeCliente);

    printf("Digite o ID do serviço: ");
    scanf("%d", &idServico);

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

    arquivo = fopen("./dados/agendamentos.csv", "at");

    if (arquivo == NULL) {
        printf("Erro na criação de arquivo");
        exit(1);
    }
    //Escrevendo no arquivo
    fprintf(arquivo, "%s;", cpfCliente);
    fprintf(arquivo, "%s;", nomeCliente);
    fprintf(arquivo, "%d;", idServico);
    fprintf(arquivo, "%s;", data);
    fprintf(arquivo, "%s\n", hora);

    fclose(arquivo);

}

void listarAgendamento(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         LISTAR AGENDAMENTO                                      |\n");
    printf("|_________________________________________________________________________________________________|\n");

    printf("\nDigite o ID do agendamento: \n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
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