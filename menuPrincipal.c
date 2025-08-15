#include <stdio.h>

//Importações dos arquivos
//#include "servicos.c"
#include "colaboradores.c"
#include "sobre.c"

int main() {

    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|             SIG-BarberShop               |\n");
    printf("|__________________________________________|\n");
    printf("|                                          |\n");
    printf("|           1 Módulo Cliente               |\n");
    printf("|           2 Módulo Serviço               |\n");
    printf("|           3 Módulo Agendamento           |\n");
    printf("|           4 Módulo Relatório             |\n");
    printf("|           5 Módulo Colaboradores         |\n");
    printf("|           6 Módulo Sobre                 |\n");
    printf("|           0 Sair                         |\n");
    printf("|__________________________________________|\n\n");


    printf("Digite a opção desejada: ");
    int opcao;
    scanf("%d", &opcao);
    
    // Chamando a função da opção desejada
    switch (opcao) {
        case 1:
            //cliente();
            break;
        case 2:
            //servico();
            break;
        case 3:
            //agendamento();
            break;
        case 4:
            //relatorio();
            break;
        case 5:
            colaboradores();
            break;
        case 6:
            sobre();
            break;
        case 0:
            //sair();
            break;
    }

    return 0;
}