#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include "include/servicos.h"

//Inscricoes de funcoes

void exibirServico(char idServico[]);
void trocarArquivosServico(char antigo[], char novo[]);
void criarDiretorioServico(void);
void cadastrarServico(Servico * servico);
void atualizarServico(char idServico[], int opcao);
void deletarServico(char idServico[]);


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

    cadastrarServico(servico);
}

void listaServico(void){
    Servico *servico;
    servico = (Servico*) malloc(sizeof(Servico));

    FILE * arquivo = fopen("./dados/servicos.bin", "rb");

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
    fclose(arquivo);
    free(servico);

    printf("\n>>> Tecle <ENTER> para encerrar o programa.\n");
    getchar();
}

void exibeServico(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         EXIBIR SERVIÇO                                          |\n");
    printf("|_________________________________________________________________________________________________|\n");

    char idServico[50];
    printf("\nDigite o ID do serviço: \n");
    scanf("%s", idServico);
    getchar();

    exibirServico(idServico);
    
}

void atualizaServico(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         ATUALIZAR SERVIÇO                                       |\n");
    printf("|_________________________________________________________________________________________________|\n");

    char idServico[50];
    printf("\nInforme o id (apenas numeros): ");
    scanf("%[^\n]", idServico);
    getchar();

    int opcao;
    do {
        system("clear||cls");
        exibirServico(idServico);

        printf("\nQual dado você deseja alterar?\n");
        printf("\n1 Nome Servico");
        printf("\n2 Valor");
        printf("\n3 Duracao Servico");
        printf("\n0 Finalizar operação\n\n");
        scanf("%d", &opcao);
        getchar();
        if (opcao != 0) {
            atualizarServico(idServico, opcao);
        }
    } while (opcao != 0);
}

void deletaServico(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         DELETAR SERVIÇO                                         |\n");
    printf("|_________________________________________________________________________________________________|\n");

    char idServico[50];
    printf("\nInforme o id (apenas numeros): ");
    scanf("%[^\n]", idServico);
    getchar();
    
    exibirServico(idServico);

    int excluir;
    printf("\nTem certeza que deseja excluir esse servico? (0 - excluir / 1 - cancelar operação): ");
    scanf("%d", &excluir);
    getchar();

    if (excluir == 0) {
        deletarServico(idServico);
        printf("\nServico removido com sucesso.");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
    } else {
        printf("\nOperação cancelada.");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    
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
                listaServico();
                break;
            
            case '4':
                atualizaServico();
                break;

            case '5':
                deletaServico();
                break;
        }

    } while (opcao != '0');

}


void cadastrarServico(Servico * servico) {
    criarDiretorioServico();
    FILE * arquivo = fopen("./dados/servicos.bin", "ab");

    if (arquivo == NULL) {
        printf("Erro na criação de arquivo de servico. O programa será finalizado.");
        printf("\n>>> Tecle <ENTER> para encerrar o programa.\n");
        getchar();
        exit(1);
    }
    
    servico->status = True;
    fwrite(servico, sizeof(Servico), 1, arquivo);

    free(servico);
    fclose(arquivo);
}

void atualizarServico(char idServico[], int opcao) {
    char dado[50];
    if (opcao == 1) {
        printf("\nNome Servico: ");
        scanf("%[^\n]", dado);
    } else if (opcao == 2) {
        printf("\nValor: ");
        scanf("%[^\n]", dado);
    } else if (opcao == 3) {
        printf("\nDuracao Servico: ");
        scanf("%[^\n]", dado);
    }

    Servico *servico;
    servico = (Servico*) malloc(sizeof(Servico));

    FILE * arquivo = fopen("./dados/servicos.bin", "r+b");
    int encontrado = False;

    while (fread(servico, sizeof(Servico), 1, arquivo) && encontrado == False) {
        if (strcmp(idServico, servico->id) == 0) {
            if (opcao == 1) {
                strcpy(servico->nome, dado);
            } else if (opcao == 2) {
                strcpy(servico->valor, dado);
            } else if (opcao == 3) {
                strcpy(servico->duracao, dado);
            }
            
            encontrado = True;
            fseek(arquivo, (-1) * sizeof(Servico), SEEK_CUR);
            fwrite(servico, sizeof(Servico), 1, arquivo);
        }
    }
    fclose(arquivo);
    free(servico);
}

void deletarServico(char idServico[]) {
    Servico *servico;
    servico = (Servico*) malloc(sizeof(Servico));

    FILE * arquivo = fopen("./dados/servicos.bin", "r+b");

    int encontrado = False;
    while (fread(servico, sizeof(Servico), 1, arquivo) && encontrado == False) {
        if (strcmp(servico->id, idServico) == 0) {
            servico->status = False;
            encontrado = True;
            fseek(arquivo, (-1) * sizeof(Servico), SEEK_CUR);
            fwrite(servico, sizeof(Servico), 1, arquivo);
        }
    }
    free(servico);
    fclose(arquivo);
}

void exibirServico(char idServico[]) {
    Servico *servico;
    servico = (Servico*) malloc(sizeof(Servico));
    FILE * arquivo = fopen("./dados/servicos.bin", "rb");

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

void trocarArquivosServico(char antigo[], char novo[]) {
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

void criarDiretorioServico(void) {
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



