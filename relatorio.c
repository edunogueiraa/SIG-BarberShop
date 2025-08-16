#include <stdio.h>
#include <stdlib.h>


int relatorio() {
    system("clear||cls");
    int opcaoCliente;
    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|                Relatórios                |\n");
    printf("|__________________________________________|\n");
    printf("|                                          |\n");
    printf("|           1 Consultar por Data           |\n");
    printf("|           2 Consultar por Serviço        |\n");
    printf("|           3 Consultar por Cliente        |\n");
    printf("|           0 Sair                         |\n");
    printf("|__________________________________________|\n\n");

    printf("Digite a opção desejada: ");
    scanf("%d", &opcaoCliente);
    getchar();

    return opcaoCliente;
    
}

void relatorioData(void) {
    system("clear||cls");
    printf("\n");
    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|           Relatório por Data             |\n");
    printf("|__________________________________________|\n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void relatorioServico(void) {
    system("clear||cls");
    printf("\n");
    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|           Relatório por Servico          |\n");
    printf("|__________________________________________|\n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void relatorioCliente(void) {
    system("clear||cls");
    printf("\n");
    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|           Relatório por Cliente          |\n");
    printf("|__________________________________________|\n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}