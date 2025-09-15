#include <stdio.h>
#include <stdlib.h>
#include "modulos/include/agendamento.h"
#include "modulos/include/cliente.h"
#include "modulos/include/colaboradores.h"
#include "modulos/include/estoqueProdutos.h"
#include "modulos/include/menuPrincipal.h"
#include "modulos/include/relatorio.h"
#include "modulos/include/sair.h"
#include "modulos/include/servicos.h"
#include "modulos/include/sobre.h"

// Programa principal
int main() {

    int opcaoPrincipal = -1;
    int opcaoSair = -1; 
    
    // A estrutura do-While garante que o codigo seja exibido pelo menos uma vez
    do {

        opcaoPrincipal = menuPrincipal();
        
        // Chamando a função da opção desejada
        switch (opcaoPrincipal) {

            case 1:
                opcaoCliente();
                break;

            case 2:
                opcaoServicos();
                break;

            case 3:
                opcaoAgendamento();
                break;

            case 4:
                opcaoRelatorio();
                break;

            case 5:
                colaboradores();
                break;

            case 6:
                sobre();
                break;

            case 7:
                opcaoEstoque();
                break;

            case 0:
                opcaoSair = sair();
                if (opcaoSair == 1) {
                    opcaoPrincipal = 0;

                    printf("\nAté logo!\n\n");
                } else {
                    
                    opcaoPrincipal = 1;
                }
                break;
        }
    } while (opcaoPrincipal != 0);

    return 0;
}