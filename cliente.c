#include <stdio.h>
#include <stdlib.h>


int cliente() {
    system("clear||cls");
    int opcaoCliente;
    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|                Clientes                  |\n");
    printf("|__________________________________________|\n");
    printf("|                                          |\n");
    printf("|           1 Cadastrar                    |\n");
    printf("|           2 Listar                       |\n");
    printf("|           3 Atualizar                    |\n");
    printf("|           4 Deletar                      |\n");
    printf("|           0 Sair                         |\n");
    printf("|__________________________________________|\n\n");

    printf("Digite a opção desejada: ");
    scanf("%d", &opcaoCliente);
    getchar();

    return opcaoCliente;
    
}

void cadastroCliente(void) {
    system("clear||cls");
    printf("\n");
    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|           Cadastro de Cliente            |\n");
    printf("|__________________________________________|\n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void listarCliente(void) {
    system("clear||cls");
    printf("\n");
    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|             Listar Cliente               |\n");
    printf("|__________________________________________|\n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualizarCliente(void) {
    system("clear||cls");
    printf("\n");
    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|            Atualizar Cliente             |\n");
    printf("|__________________________________________|\n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void deletarCliente(void) {
    system("clear||cls");
    printf("\n");
    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|             Deletar Cliente              |\n");
    printf("|__________________________________________|\n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}