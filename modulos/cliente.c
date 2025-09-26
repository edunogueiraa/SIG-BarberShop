#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE * arquivoCliente;
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
        
    printf("Nome completo: ");
    scanf("%s", nome);

    printf("CPF: ");
    scanf("%s", cpf);

    printf("E-mail: ");
    scanf("%s", email);

    printf("Data de Nascimento (dd/mm/aaaa): ");
    scanf("%s", data);

    printf("Celular  (apenas números): ");
    scanf("%s", celular);
    getchar();
    
    //Criando o arquivoCliente
    arquivoCliente = fopen("clientes.csv", "at");

    if (arquivoCliente == NULL) {
        printf("Erro na criação de arquivo de Clientes. O programa será finalizado.");
        printf("\n>>> Tecle <ENTER> para encerrar o programa.\n");
        getchar();
        exit(1);
    }
    //Escrevendo no arquivoCliente
    fprintf(arquivoCliente, "%s;", nome);
    fprintf(arquivoCliente, "%s;", cpf);
    fprintf(arquivoCliente, "%s;", email);
    fprintf(arquivoCliente, "%s;", data);
    fprintf(arquivoCliente, "%s\n", celular);

    fclose(arquivoCliente);
}

void listarCliente(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         LISTAR CLIENTE                                          |\n");
    printf("|_________________________________________________________________________________________________|\n");

    char cpfCliente[50];
    printf("\nDigite o cpf do cliente: ");
    scanf("%s", cpfCliente);
    getchar();

    arquivoCliente = fopen("clientes.csv", "rt");

    if (arquivoCliente == NULL) {
        printf("Erro na abertura do arquivo clientes");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    while (!feof(arquivoCliente)){
        fscanf(arquivoCliente, "%[^;]", nome);
        fgetc(arquivoCliente);
        fscanf(arquivoCliente, "%[^;]", cpf);
        fgetc(arquivoCliente);
        fscanf(arquivoCliente, "%[^;]", email);
        fgetc(arquivoCliente);
        fscanf(arquivoCliente, "%[^;]", data);
        fgetc(arquivoCliente);
        fscanf(arquivoCliente, "%[^;]", celular);
        fgetc(arquivoCliente);

        if(strcmp(cpf,cpfCliente) == 0) {
            printf("\n\t\t\t <--- Cliente Encontrado ---> \n\n");
            printf("\t\t\tNome: %s\n",nome);
            printf("\t\t\tCPF: %s\n",cpf);
            printf("\t\t\tEmail: %s\n",email);
            printf("\t\t\tData: %s\n",data);
            printf("\t\t\tCelular: %s\n",celular);
            printf("\n>>> Tecle <ENTER> para continuar...\n");
            getchar();
            fclose(arquivoCliente);
            return;
        }
    }
    

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