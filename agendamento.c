#include <stdio.h>
#include <stdlib.h>


int agendamento() {
    system("clear||cls");
    int opcaoAgendamento;
    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|               Agendamentos               |\n");
    printf("|__________________________________________|\n");
    printf("|                                          |\n");
    printf("|           1 Cadastrar                    |\n");
    printf("|           2 Listar                       |\n");
    printf("|           3 Atualizar                    |\n");
    printf("|           4 Deletar                      |\n");
    printf("|           0 Sair                         |\n");
    printf("|__________________________________________|\n\n");

    printf("Digite a opção desejada: ");
    scanf("%d", &opcaoAgendamento);
    getchar();

    return opcaoAgendamento;
    
}

void cadastroAgendamento(void) {
    system("clear||cls");
    printf("\n");
    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|         Cadastro de Agendamento          |\n");
    printf("|__________________________________________|\n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void listarAgendamento(void) {
    system("clear||cls");
    printf("\n");
    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|            Listar Agendamento            |\n");
    printf("|__________________________________________|\n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualizarAgendamento(void) {
    system("clear||cls");
    printf("\n");
    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|          Atualizar Agendamento           |\n");
    printf("|__________________________________________|\n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void deletarAgendamento(void) {
    system("clear||cls");
    printf("\n");
    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|            Deletar Agendamento           |\n");
    printf("|__________________________________________|\n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}