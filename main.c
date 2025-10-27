#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include "modulos/include/agendamento.h"
#include "modulos/include/cliente.h"
#include "modulos/include/colaboradores.h"
#include "modulos/include/estoqueProdutos.h"
#include "modulos/include/menuPrincipal.h"
#include "modulos/include/relatorio.h"
#include "modulos/include/sair.h"
#include "modulos/include/servicos.h"
#include "modulos/include/sobre.h"

int main() {

    char opcaoPrincipal = '9';
    char opcaoSair = '9'; 
    
    do {

        opcaoPrincipal = menuPrincipal();
        
        switch (opcaoPrincipal) {

            case '1':
                opcaoCliente();
                break;

            case '2':
                opcaoServicos();
                break;

            case '3':
                opcaoAgendamento();
                break;

            case '4':
                opcaoRelatorio();
                break;

            case '5':
                colaboradores();
                break;

            case '6':
                telaSobre();
                break;

            case '7':
                opcaoEstoque();
                break;

            case '0':

                do{
                    opcaoSair = telaSair();
                    if (opcaoSair == '0') {
                        printf("\nEncerrando sistema!\n\n");
                        sleep(1);
                        printf("\nAté logo!\n\n");
                        opcaoPrincipal = '0';
                        opcaoSair = '0';
                    } else if (opcaoSair == '1') {
                        opcaoPrincipal = '1';
                    } else {
                        printf("\nOpção inválida!");
                    }
                } while (opcaoSair != '0' && opcaoSair != '1');
                break;
        }
    } while (opcaoPrincipal != '0');

    return 0;
}