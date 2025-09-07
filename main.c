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

int opcaoCliente();

int servico();
void cadastroServico();
void listarServico();
void atualizarServico();
void deletarServico();

int agendamento();
void cadastroAgendamento();
void listarAgendamento();
void atualizarAgendamento();
void deletarAgendamento();

int relatorio();
void relatorioData();
void relatorioServico();
void relatorioCliente();

int sair();
void colaboradores();
void sobre();

int estoque();
void cadastroEstoque();
void listarEstoque();
void atualizarEstoque();
void deletarEstoque();


// Programa principal
int main() {

    int opcaoPrincipal = -1;
    int opcaoServico = -1;
    int opcaoAgendamento = -1;
    int opcaoRelatorio = -1;
    int opcaoSair = -1;
    int opcaoEstoque = -1; 
    
    // A estrutura do-While garante que o codigo seja exibido pelo menos uma vez
    do {

        opcaoPrincipal = menuPrincipal();
        
        // Chamando a função da opção desejada
        switch (opcaoPrincipal) {

            case 1:

                opcaoCliente();

                break;

            case 2:

                do {

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
                
                } while (opcaoServico != 0);

                break;

            case 3:

                do{
                    
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
                
                } while (opcaoAgendamento != 0);

                break;

            case 4:

                do{
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
                
                } while (opcaoRelatorio != 0);            
                break;

            case 5:
                colaboradores();
                break;

            case 6:
                sobre();
                break;

            case 7:

                do{

                    opcaoEstoque = estoque();

                    switch (opcaoEstoque) {

                        case 1:
                            cadastroEstoque();
                            break;

                        case 2:
                            listarEstoque();
                            break;

                        case 3:
                            atualizarEstoque();
                            break;

                        case 4:
                            deletarEstoque();
                            break;

                    }
                } while (opcaoEstoque != 0);
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