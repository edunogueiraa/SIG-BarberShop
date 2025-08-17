#include <stdio.h>
#include <stdlib.h>

int menuPrincipal() {

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
    printf("|                                   1 Módulo Cliente                                              |\n");
    printf("|                                   2 Módulo Serviço                                              |\n");
    printf("|                                   3 Módulo Agendamento                                          |\n");
    printf("|                                   4 Módulo Relatório                                            |\n");
    printf("|                                   5 Módulo Colaboradores                                        |\n");
    printf("|                                   6 Módulo Sobre                                                |\n");
    printf("|                                   0 Sair                                                        |\n");
    printf("|_________________________________________________________________________________________________|\n\n");


    printf("Digite a opção desejada: ");
    int opcaoPrincipal;
    scanf("%d", &opcaoPrincipal);

    return opcaoPrincipal;
}