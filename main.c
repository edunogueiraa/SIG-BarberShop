#include <stdio.h>
#include <stdlib.h>

//Importando arquivos
#include "Modulos/menuPrincipal.c"
#include "Modulos/cliente.c"
#include "Modulos/servicos.c"
#include "Modulos/agendamento.c"
#include "Modulos/relatorio.c"
#include "Modulos/colaboradores.c"
#include "Modulos/sobre.c"
#include "Modulos/sair.c"
#include "Modulos/estoque.c"


//Assinaturas de funções
int menuPrincipal();
void opcaoCliente();
void opcaoServico();
void opcaoAgendamento();
void opcaoRelatorio();
void opcaoEstoque();
void colaboradores();
void sobre();
int sair();

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
                opcaoServico();
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