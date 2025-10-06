#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include "include/estoqueProdutos.h"

void telaEstoque(void) {
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
    printf("|                                  MENU ESTOQUE DE PRODUTOS                                       |\n");
    printf("|_________________________________________________________________________________________________|\n");
    printf("|                                                                                                 |\n");
    printf("|                                   1 Cadastrar Produto                                           |\n");
    printf("|                                   2 Listar Produtos                                             |\n");
    printf("|                                   3 Atualizar Produto                                           |\n");
    printf("|                                   4 Deletar Produto                                             |\n");
    printf("|                                   0 Sair                                                        |\n");
    printf("|_________________________________________________________________________________________________|\n\n");
    
}

void cadastroEstoque(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         CADASTRO PRODUTO                                        |\n");
    printf("|_________________________________________________________________________________________________|\n");

    Estoque *estoque;
    estoque = (Estoque*) malloc(sizeof(Estoque));

    printf("\nNome do produto: ");
    scanf("%[^\n]", estoque->nome);

    printf("ID do produto (apenas números): ");
    scanf("%s", estoque->id);

    printf("Tipo do produto: ");
    scanf("%s", estoque->tipo);

    printf("Valor (R$): ");
    scanf("%s", estoque->valor);
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
    estoque->arquivoEstoque = fopen("./dados/estoque.csv", "at");

    if (estoque->arquivoEstoque == NULL)
    {
        printf("Erro na criação de arquivo de Estoque. O programa será finalizado.");
        printf("\n>>> Tecle <ENTER> para encerrar o programa.\n");
        getchar();
        exit(1);
    }
    // Escrevendo no arquivo
    fprintf(estoque->arquivoEstoque, "%s;", estoque->nome);
    fprintf(estoque->arquivoEstoque, "%s;", estoque->id);
    fprintf(estoque->arquivoEstoque, "%s;", estoque->tipo);
    fprintf(estoque->arquivoEstoque, "%s\n", estoque->valor);

    fclose(estoque->arquivoEstoque);
}

void exibeProduto(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         LISTAR PRODUTO                                         |\n");
    printf("|_________________________________________________________________________________________________|\n");

    Estoque *estoque;
    estoque = (Estoque*) malloc(sizeof(Estoque));

    char idProduto[50];
    printf("\nInforme o ID: \n");
    scanf("%s", idProduto);
    getchar();

    estoque->arquivoEstoque = fopen("./dados/estoque.csv", "rt");

    if (estoque->arquivoEstoque == NULL) {
        printf("Erro na abertura do arquivo de estoque");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (!feof(estoque->arquivoEstoque))
    {
        fscanf(estoque->arquivoEstoque, "%[^;]", estoque->nome);
        fgetc(estoque->arquivoEstoque);
        fscanf(estoque->arquivoEstoque, "%[^;]", estoque->id);
        fgetc(estoque->arquivoEstoque);
        fscanf(estoque->arquivoEstoque, "%[^;]", estoque->tipo);
        fgetc(estoque->arquivoEstoque);
        fscanf(estoque->arquivoEstoque, "%[^\n]", estoque->valor);
        fgetc(estoque->arquivoEstoque);

        if (strcmp(idProduto, estoque->id) == 0)
        {
            printf("\n\t\t\t <--- Produto Encontrado ---> \n\n");
            printf("\t\t\tNome do produto: %s\n", estoque->nome);
            printf("\t\t\tID do produto: %s\n", estoque->id);
            printf("\t\t\tTipo do produto: %s\n", estoque->tipo);
            printf("\t\t\tValor (R$): %s\n", estoque->valor);
            printf("\n>>> Tecle <ENTER> para continuar...\n");
            getchar();
            fclose(estoque->arquivoEstoque);
            return;
        }
    }
}

void atualizarEstoque(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         ATUALIZAR PRODUTO                                       |\n");
    printf("|_________________________________________________________________________________________________|\n");

    printf("\nInforme o ID: \n");
    printf("\nNome: \n");
    printf("ID: \n");
    printf("Tipo: \n");
    printf("Valor (R$): \n");
    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void deletarEstoque(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         DELETAR PRODUTO                                         |\n");
    printf("|_________________________________________________________________________________________________|\n");

    printf("\nInforme O ID: \n");
    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void opcaoEstoque(void) {
    char opcao = '9';

    do {
        telaEstoque();
        printf("Digite a opção desejada: ");
        scanf("%c", &opcao);
        getchar();

        switch (opcao) {

            case '1':
                cadastroEstoque();
                break;

            case '2':
                exibeProduto();
                break;

            case '3':
                atualizarEstoque();
                break;

            case '4':
                deletarEstoque();
                break;

        }
    } while (opcao != '0');
}
