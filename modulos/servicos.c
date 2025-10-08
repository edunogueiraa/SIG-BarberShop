#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include "include/servicos.h"

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
    printf("|                                   2 Exibir                                                      |\n");
    printf("|                                   3 Listar                                                      |\n");
    printf("|                                   4 Atualizar                                                   |\n");
    printf("|                                   5 Deletar                                                     |\n");
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

    Servico *servico;
    servico = (Servico*) malloc(sizeof(Servico));

    printf("\nNome do serviço: ");
    scanf("%[^\n]", servico->nome);

    printf("ID do serviço: ");
    scanf("%s", servico->id);

    printf("Valor: ");
    scanf("%s", servico->valor);

    printf("Duração: ");
    scanf("%s", servico->duracao);
    getchar();

    servico->status = True;

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
    FILE * arquivo;
    arquivo = fopen("./dados/servicos.bin", "ab");

    if (arquivo == NULL) {
        printf("Erro na criação de arquivo Servico");
        exit(1);
    }

    fwrite(servico,sizeof(Servico),1,arquivo);

    fclose(arquivo);
    free(servico);
}

void listarServico(void){
    Servico *servico;
    servico = (Servico*) malloc(sizeof(Servico));

    FILE * arquivo;
    arquivo = fopen("./dados/servicos.bin", "rb");

    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo Servico");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fread(servico,sizeof(Servico),1,arquivo)){
        if (servico->status == True) {
            printf("\n\n");
            printf("\t\t\tNome do serviço: %s\n", servico->nome);
            printf("\t\t\tID do serviço: %s\n", servico->id);
            printf("\t\t\tValor (R$): %s\n", servico->valor);
            printf("\t\t\tDuração do serviço: %s\n", servico->duracao);
        }
    }

    printf("\n>>> Tecle <ENTER> para encerrar o programa.\n");
    getchar();

    fclose(arquivo);
    free(servico);
}

void exibeServico(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         EXIBIR SERVIÇO                                          |\n");
    printf("|_________________________________________________________________________________________________|\n");

    Servico *servico;
    servico = (Servico*) malloc(sizeof(Servico));
    FILE * arquivo;

    char idServico[50];
    printf("\nDigite o ID do serviço: \n");
    scanf("%s", idServico);
    getchar();

    arquivo = fopen("./dados/servicos.bin", "rb");

    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo de serviço");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

        while (fread(servico,sizeof(Servico),1,arquivo)){
            if(strcmp(idServico,servico->id) == 0 && servico->status == True){
                printf("\n\t\t\t <--- Servico Encontrado ---> \n\n");
                printf("\t\t\tNome do serviço: %s\n", servico->nome);
                printf("\t\t\tID do serviço: %s\n", servico->id);
                printf("\t\t\tValor (R$): %s\n", servico->valor);
                printf("\t\t\tDuração do serviço: %s\n", servico->duracao);
                printf("\n>>> Tecle <ENTER> para continuar...\n");
                getchar();
                fclose(arquivo);
                return;
            }
        }

    free(servico);
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
    char opcao = '9';

    do {

        telaServico();
        printf("Digite a opção desejada: ");
        scanf("%c", &opcao);
        getchar();

        switch (opcao) {

            case '1':
                cadastroServico();
                break;

            case '2':
                exibeServico();
                break;

            case '3':
                listarServico();
                break;
            
            case '4':
                atualizarServico();
                break;

            case '5':
                deletarServico();
                break;
        }

    } while (opcao != '0');

}

