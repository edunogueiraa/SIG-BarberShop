#include <stdio.h>
#include <stdlib.h>

//Importando arquivos
#include "cliente.c"
#include "servicos.c"
#include "agendamento.c"
#include "relatorio.c"
#include "colaboradores.c"
#include "sobre.c"
#include "sair.c"

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
    int opcaoPrincipal;
    scanf("%d", &opcaoPrincipal);

    while (opcaoPrincipal != 0) {

        // Chamando a função da opção desejada
        switch (opcaoPrincipal) {

            case 1:
                int opcaoCliente;
                while (opcaoCliente != 0){
                    opcaoCliente = cliente();

                    switch (opcaoCliente) {

                        case 1:
                            cadastroCliente();
                            break;

                        case 2:
                            listarCliente();
                            break;

                        case 3:
                            atualizarCliente();
                            break;

                        case 4:
                            deletarCliente();
                            break;

                    }
                }
                break;

            case 2:
                int opcaoServico;
                while (opcaoServico != 0){
                    opcaoServico = servico();

                    switch (opcaoServico) {

                        case 1:
                            cadastroServico();
                            break;

                        case 2:
                            listarServico();
                            break;

                        case 3:
                            atualizarServico();
                            break;

                        case 4:
                            deletarServico();
                            break;
                    }
                }
                break;

            case 3:
                int opcaoAgendamento;
                while (opcaoAgendamento != 0){
                    opcaoAgendamento = agendamento();

                    switch (opcaoAgendamento) {

                        case 1:
                            cadastroAgendamento();
                            break;

                        case 2:
                            listarAgendamento();
                            break;

                        case 3:
                            atualizarAgendamento();
                            break;

                        case 4:
                            deletarAgendamento();
                            break;
                    }
                }
                break;

            case 4:
                int opcaoRelatorio;
                while (opcaoRelatorio != 0){
                    opcaoRelatorio = relatorio();

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
                }            
                break;

            case 5:
                colaboradores();
                break;

            case 6:
                sobre();
                break;

            case 0:
                //int opcaoSair;
                //opcaoSair = sair();
                //if (opcaoSair == 1) {
                //    opcaoPrincipal = 0;
                //}

                break;
        }
    }

    return 0;
}