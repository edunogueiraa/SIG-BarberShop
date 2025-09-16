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
                sobre();
                break;

            case '7':
                opcaoEstoque();
                break;

            case '0':

                do{
                    opcaoSair = sair();
                    if (opcaoSair == '1') {
                        opcaoPrincipal = '0';
                        printf("\nEncerrando sistema!\n\n");
                        sleep(1);
                        printf("\nAté logo!\n\n");
                    } else if (opcaoSair == '2') {
                        opcaoPrincipal = '1';
                    } else {
                        printf("\nOpção inválida!");
                    }
                } while (opcaoSair != '1' && opcaoSair != '2');
                break;
        }
    } while (opcaoPrincipal != '0');

    return 0;
}