#include <stdio.h>
#include <stdlib.h>


int servico() {
    system("clear||cls");
    int opcaoServico;
    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|                Serviços                  |\n");
    printf("|__________________________________________|\n");
    printf("|                                          |\n");
    printf("|           1 Cadastrar                    |\n");
    printf("|           2 Listar                       |\n");
    printf("|           3 Atualizar                    |\n");
    printf("|           4 Deletar                      |\n");
    printf("|           0 Sair                         |\n");
    printf("|__________________________________________|\n\n");

    printf("Digite a opção desejada: ");
    scanf("%d", &opcaoServico);
    getchar();

    return opcaoServico;
    
}

void cadastroServico(void) {
    system("clear||cls");
    printf("\n");
    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|           Cadastro de Serviço            |\n");
    printf("|__________________________________________|\n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void listarServico(void) {
    system("clear||cls");
    printf("\n");
    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|             Listar Serviço               |\n");
    printf("|__________________________________________|\n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualizarServico(void) {
    system("clear||cls");
    printf("\n");
    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|            Atualizar Serviço             |\n");
    printf("|__________________________________________|\n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void deletarServico(void) {
    system("clear||cls");
    printf("\n");
    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|             Deletar Serviço              |\n");
    printf("|__________________________________________|\n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}