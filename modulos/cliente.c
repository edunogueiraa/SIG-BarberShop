#include <stdio.h>
#include <stdlib.h>

FILE * arquivo;
char letra;
char nome[50];
char cpf[50];
char email[50];
char data[50];
char celular[50];


void telaCliente(void) {
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
    printf("|                                         MENU CLIENTE                                            |\n");
    printf("|_________________________________________________________________________________________________|\n");
    printf("|                                                                                                 |\n");
    printf("|                                   1 Cadastrar                                                   |\n");
    printf("|                                   2 Listar                                                      |\n");
    printf("|                                   3 Atualizar                                                   |\n");
    printf("|                                   4 Deletar                                                     |\n");
    printf("|                                   0 Sair                                                        |\n");
    printf("|_________________________________________________________________________________________________|\n\n");

}

void cadastroCliente(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         CADASTRO CLIENTE                                        |\n");
    printf("|_________________________________________________________________________________________________|\n");
        
    printf("\nNome completo: \n");
    scanf("%s", nome);

    printf("CPF: \n");
    scanf("%s", cpf);

    printf("E-mail: \n");
    scanf("%s", email);

    printf("Data de Nascimento (dd/mm/aaaa): \n");
    scanf("%s", data);

    printf("Celular  (apenas números): \n");
    scanf("%s", celular);

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();


    //Criando o arquivo
    arquivo = fopen("clientes.txt", "at");

    if (arquivo == NULL) {
        printf("Erro na criação de arquivo");
        exit(1);
    }
    //Escrevendo no arquivo
    fprintf(arquivo, "%s\n", nome);
    fprintf(arquivo, "%s\n", cpf);
    fprintf(arquivo, "%s\n", email);
    fprintf(arquivo, "%s\n", data);
    fprintf(arquivo, "%s\n\n", celular);

    fclose(arquivo);


    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void listarCliente(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         LISTAR CLIENTE                                          |\n");
    printf("|_________________________________________________________________________________________________|\n");

    printf("\nInforme o CPF (apenas numeros): \n");
    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualizarCliente(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         ATUALIZAR CLIENTE                                       |\n");
    printf("|_________________________________________________________________________________________________|\n");

    printf("\nInforme o CPF (apenas numeros): \n");
    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void deletarCliente(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         DELETAR CLIENTE                                         |\n");
    printf("|_________________________________________________________________________________________________|\n");

    printf("\nInforme o CPF (apenas numeros): \n");
    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void opcaoCliente(void) {

    char opcaoCliente = '9';

    do {

        telaCliente();
        printf("Digite a opção desejada: ");
        scanf("%c", &opcaoCliente);
        getchar();

        switch (opcaoCliente) {

            case '1':
                cadastroCliente();
                break;

            case '2':
                listarCliente();
                break;

            case '3':
                atualizarCliente();
                break;

            case '4':
                deletarCliente();
                break;

        }

    } while (opcaoCliente != '0');
    
}