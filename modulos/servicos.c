#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>

void telaServico(void) {
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
    printf("|                                         MENU SERVIÇO                                            |\n");
    printf("|_________________________________________________________________________________________________|\n");
    printf("|                                                                                                 |\n");
    printf("|                                   1 Cadastrar                                                   |\n");
    printf("|                                   2 Listar                                                      |\n");
    printf("|                                   3 Atualizar                                                   |\n");
    printf("|                                   4 Deletar                                                     |\n");
    printf("|                                   0 Sair                                                        |\n");
    printf("|_________________________________________________________________________________________________|\n\n");
}

void cadastroServico(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         CADASTRO SERVIÇO                                        |\n");
    printf("|_________________________________________________________________________________________________|\n");

    FILE *arquivoServico;
    char nome[50];
    char id[50];
    char valor[50];
    char duracao[50];

    printf("\nNome do serviço: ");
    scanf("%s", nome);

    printf("\nID do serviço: ");
    scanf("%s", id);

    printf("Valor: ");
    scanf("%s", valor);

    printf("Duração: ");
    scanf("%s", duracao);

    printf("\n>>> Tecle <ENTER> para continuar...\n");
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

    // Criando o arquivo
    arquivoServico = fopen("./dados/servico.csv", "at");

    if (arquivoServico == NULL)
    {
        printf("Erro na criação de arquivo de Servico. O programa será finalizado.");
        printf("\n>>> Tecle <ENTER> para encerrar o programa.\n");
        getchar();
        exit(1);
    }
    // Escrevendo no arquivo
    fprintf(arquivoServico, "%s;", nome);
    fprintf(arquivoServico, "%s;", id);
    fprintf(arquivoServico, "%s;", valor);
    fprintf(arquivoServico, "%s\n", duracao);

    fclose(arquivoServico);
}

void listarServico(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         LISTAR SERVIÇO                                          |\n");
    printf("|_________________________________________________________________________________________________|\n");

    printf("\nDigite o ID do serviço: \n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualizarServico(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         ATUALIZAR SERVIÇO                                       |\n");
    printf("|_________________________________________________________________________________________________|\n");

    printf("\nDigite o ID do serviço: \n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void deletarServico(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         DELETAR SERVIÇO                                         |\n");
    printf("|_________________________________________________________________________________________________|\n");

    printf("\nDigite o ID do serviço: \n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void opcaoServicos(void) {

    char opcaoServico = '9';

    do {

        telaServico();
        printf("Digite a opção desejada: ");
        scanf("%c", &opcaoServico);
        getchar();

        switch (opcaoServico) {

            case '1':
                cadastroServico();
                break;

            case '2':
                listarServico();
                break;

            case '3':
                atualizarServico();
                break;

            case '4':
                deletarServico();
                break;
        }

    } while (opcaoServico != '0');

}

