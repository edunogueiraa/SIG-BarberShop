#include <stdio.h>
#include <stdlib.h>

void estoque(void) {
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
    printf("|                                         MENU ESTOQUE                                            |\n");
    printf("|_________________________________________________________________________________________________|\n");
    printf("|                                                                                                 |\n");
    printf("|                                   1 Cadastrar                                                   |\n");
    printf("|                                   2 Listar                                                      |\n");
    printf("|                                   3 Atualizar                                                   |\n");
    printf("|                                   4 Deletar                                                     |\n");
    printf("|                                   0 Sair                                                        |\n");
    printf("|_________________________________________________________________________________________________|\n\n");
    
}

void cadastroEstoque(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         CADASTRO ESTOQUE                                        |\n");
    printf("|_________________________________________________________________________________________________|\n");
        
    printf("\nNome: \n");
    printf("ID: \n");
    printf("Tipo: \n");
    printf("Valor (R$): \n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void listarEstoque(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         LISTAR ESTOQUE                                          |\n");
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
    printf("|                                         ATUALIZAR ESTOQUE                                       |\n");
    printf("|_________________________________________________________________________________________________|\n");

    printf("\nInforme o ID: \n");
    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void deletarEstoque(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         DELETAR ESTOQUE                                         |\n");
    printf("|_________________________________________________________________________________________________|\n");

    printf("\nInforme O ID: \n");
    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void opcaoEstoque(void) {
    int opcaoEstoque = -1;

    do {
        estoque();
        printf("Digite a opção desejada: ");
        scanf("%d", &opcaoEstoque);
        getchar();

        switch (opcaoEstoque) {

            case 1:
                cadastroEstoque();
                break;

            case 2:
                listarEstoque();
                break;

            case 3:
                atualizarEstoque();
                break;

            case 4:
                deletarEstoque();
                break;

        }
    } while (opcaoEstoque != 0);
}
