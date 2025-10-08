#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include "include/estoqueProdutos.h"

void criarDiretorio(void);

void cadastrarProduto(Estoque * estoque);

void exibirProduto(char idProduto[]);

void deletarProduto(char idProduto[]);

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
    printf("|                                   2 Exibir Produto                                              |\n");
    printf("|                                   3 Listar Produtos                                             |\n");
    printf("|                                   4 Atualizar Produto                                           |\n");
    printf("|                                   5 Deletar Produto                                             |\n");
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

    Estoque * estoque;
    estoque = (Estoque *) malloc(sizeof(Estoque));
    
    printf("\nNome do produto: ");
    scanf("%[^\n]", estoque->nome);
    printf("ID do produto (apenas números): ");
    scanf("%s", estoque->id);
    printf("Tipo do produto: ");
    scanf("%s", estoque->tipo);
    printf("Valor (R$): ");
    scanf("%s", estoque->valor);
    getchar();
    
    criarDiretorio();
    cadastrarProduto(estoque);
    
    free(estoque);
}

void exibeProduto(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                          EXIBIR PRODUTO                                         |\n");
    printf("|_________________________________________________________________________________________________|\n");
    
    char idProduto[50];
    printf("\nInforme o ID: \n");
    scanf("%s", idProduto);
    getchar();

    exibirProduto(idProduto);
    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void listaEstoque(void) {
    Estoque * estoque;
    estoque = (Estoque *) malloc(sizeof(Estoque));

    FILE * arquivo;
    arquivo = fopen("./dados/estoque.bin", "rb");

    while (fread(estoque, sizeof(Estoque), 1, arquivo)) {
        if (estoque->status == True) {
            printf("\t\t\tNome do produto: %s\n", estoque->nome);
            printf("\t\t\tID do produto: %s\n", estoque->id);
            printf("\t\t\tTipo do produto: %s\n", estoque->tipo);
            printf("\t\t\tValor (R$): %s\n\n", estoque->valor);
        }
    }
    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();

    fclose(arquivo);
    free(estoque);
}

void atualizaProduto(void) {
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

void deletaProduto(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         DELETAR PRODUTO                                         |\n");
    printf("|_________________________________________________________________________________________________|\n");

    char idProduto[50];
    printf("\nInforme o ID: \n");
    scanf("%s", idProduto);
    getchar();

    exibirProduto(idProduto);

    int excluir;
    printf("\nTem certeza que deseja excluir esse produto? (0 - excluir / 1 - cancelar operação): ");
    scanf("%d", &excluir);
    getchar();

    if (excluir == 0) {
        deletarProduto(idProduto);
        printf("\nProduto removido com sucesso.");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
    } else {
        printf("\nOperação cancelada.");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
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
                listaEstoque();
                break;

            case '4':
                atualizaProduto();
                break;

            case '5':
                deletaProduto();
                break;

        }
    } while (opcao != '0');
}

void cadastrarProduto(Estoque * estoque) {
    FILE * arquivo;
    arquivo = fopen("./dados/estoque.bin", "ab");

    if (arquivo == NULL)
    {
        printf("Erro na criação de arquivo de Estoque. O programa será finalizado.");
        printf("\n>>> Tecle <ENTER> para encerrar o programa.\n");
        getchar();
        exit(1);
    }

    estoque->status = True;
    fwrite(estoque, sizeof(Estoque), 1, arquivo);

    fclose(arquivo);
}

void exibirProduto(char idProduto[]) {
    Estoque * estoque;
    estoque = (Estoque *) malloc(sizeof(Estoque));

    FILE * arquivo;
    arquivo = fopen("./dados/estoque.bin", "rt");

    if (arquivo == NULL) {
        printf("Erro na abertura do arquivo de estoque");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (fread(estoque, sizeof(Estoque), 1, arquivo)) {
        if (strcmp(idProduto, estoque->id) == 0 && estoque->status == True) {
            printf("\n\t\t\t <--- Produto Encontrado ---> \n\n");
            printf("\t\t\tNome do produto: %s\n", estoque->nome);
            printf("\t\t\tID do produto: %s\n", estoque->id);
            printf("\t\t\tTipo do produto: %s\n", estoque->tipo);
            printf("\t\t\tValor (R$): %s\n", estoque->valor);
            fclose(arquivo);
            return;
        }
    }
}

void deletarProduto(char idProduto[]) {
    Estoque * estoque;
    estoque = (Estoque *) malloc(sizeof(Estoque));

    FILE * arquivo;
    arquivo = fopen("./dados/estoque.bin", "r+b");

    int encontrado = False;
    
    while (fread(estoque, sizeof(Estoque), 1, arquivo) && encontrado == False) {
        if (strcmp(idProduto, estoque->id) == 0) {
            estoque->status = False;
            encontrado = True;
            fseek(arquivo, (-1) * sizeof(Estoque), SEEK_CUR);
            fwrite(estoque, sizeof(Estoque), 1, arquivo);
            fclose(arquivo);
        }
    }
    free(estoque);
}

void criaDiretorio(void) {
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
}