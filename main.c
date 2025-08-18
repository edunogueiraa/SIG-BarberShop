#include <stdio.h>
#include <stdlib.h>

//Importando arquivos
#include "menuPrincipal.c"
#include "cliente.c"
#include "servicos.c"
#include "agendamento.c"
#include "relatorio.c"
#include "colaboradores.c"
#include "sobre.c"
#include "sair.c"

int main() {

    int opcaoPrincipal = -1;
    int opcaoCliente = -1;
    int opcaoServico = -1;
    int opcaoAgendamento = -1;
    int opcaoRelatorio = -1;
    int opcaoSair;

    while (opcaoPrincipal != 0) {
        opcaoPrincipal = menuPrincipal();
        
        // Chamando a função da opção desejada
        switch (opcaoPrincipal) {

            case 1:
                opcaoCliente = -1;
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

                        case 0:
                            break;

                        default:
                            printf("Opção inválida!\n");
                            break;

                    }
                }
                break;

            case 2:
                opcaoServico = -1;
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
                opcaoAgendamento = -1;
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
                opcaoRelatorio = -1;
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
                opcaoSair;
                opcaoSair = sair();
                if (opcaoSair == 1) {
                    opcaoPrincipal = 0;

                    printf("\nAté logo!\n\n");
                } else {
                    
                    opcaoPrincipal = 1;
                }

                break;
        }
    }

    return 0;
}