#include <stdio.h>
#include <stdlib.h>

//FILE * arquivo;
//char nome[50];
//char id[50];
//char tipo[50];
//char valor[50];

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
        
/*    printf("\nNome: \n");
    scanf("%s", nome);

    printf("ID: \n");
    scanf("%s", id);

    printf("Tipo: \n");
    scanf("%s", tipo);

    printf("Valor (R$): \n");
    scanf("%s", valor);

    getchar();

    // Criando o arquivo
    arquivo = fopen("./dados/estoque.txt", "at");

    if (arquivo == NULL)
    {
        printf("Erro na criação de arquivo");
        exit(1);
    }
    // Escrevendo no arquivo
    fprintf(arquivo, "%s\n", nome);
    fprintf(arquivo, "%s\n", id);
    fprintf(arquivo, "%s\n", tipo);
    fprintf(arquivo, "%s\n\n", valor);

    fclose(arquivo); */
}

void listarEstoque(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         LISTAR PRODUTO                                         |\n");
    printf("|_________________________________________________________________________________________________|\n");

    printf("\nInforme o ID: \n");
    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
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
    char opcaoEstoque = '9';

    do {
        telaEstoque();
        printf("Digite a opção desejada: ");
        scanf("%c", &opcaoEstoque);
        getchar();

        switch (opcaoEstoque) {

            case '1':
                cadastroEstoque();
                break;

            case '2':
                listarEstoque();
                break;

            case '3':
                atualizarEstoque();
                break;

            case '4':
                deletarEstoque();
                break;

        }
    } while (opcaoEstoque != '0');
}
