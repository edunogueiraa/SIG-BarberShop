#include <stdio.h>
#include <stdlib.h>


void relatorio(void) {
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
    printf("|                                         MENU RELATÓRIO                                          |\n");
    printf("|_________________________________________________________________________________________________|\n");
    printf("|                                                                                                 |\n");
    printf("|                                    1 Consultar por Data                                         |\n");
    printf("|                                    2 Consultar por Serviço                                      |\n");
    printf("|                                    3 Consultar por Cliente                                      |\n");
    printf("|                                    0 Sair                                                       |\n");
    printf("|_________________________________________________________________________________________________|\n\n");
    
}

void relatorioData(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         RELATÓRIO POR DATA                                      |\n");
    printf("|_________________________________________________________________________________________________|\n");

    printf("\nListagem de agendamentos por data: \n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void relatorioServico(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         RELATÓRIO POR SERVIÇO                                   |\n");
    printf("|_________________________________________________________________________________________________|\n");

    printf("\nListagem de agendamentos por serviços: \n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void relatorioCliente(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         RELATÓRIO POR CLIENTE                                   |\n");
    printf("|_________________________________________________________________________________________________|\n");

    printf("\nListagem de agendamentos por clientes: \n");

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void opcaoRelatorio(void) {

    int opcaoRelatorio = -1;

    do {
        relatorio();
        printf("Digite a opção desejada: ");
        scanf("%d", &opcaoRelatorio);
        getchar();

        switch (opcaoRelatorio) {

            case 1:
                relatorioData();
                break;

            case 2:
                relatorioServico();
                break;

            case 3:
                relatorioCliente();
                break;
        }

    } while (opcaoRelatorio != 0);

}