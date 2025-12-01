#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "include/servicos.h"
#include "include/agendamento.h"
#include "include/cliente.h"
#include "include/utils.h"

void telaAgendamento(void) {
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
    printf("|                                         MENU AGENDAMENTO                                        |\n");
    printf("|_________________________________________________________________________________________________|\n");
    printf("|                                                                                                 |\n");
    printf("|                                   1 Cadastrar                                                   |\n");
    printf("|                                   2 Exibir                                                      |\n");
    printf("|                                   3 Listar                                                      |\n");
    printf("|                                   4 Atualizar                                                   |\n");
    printf("|                                   5 Deletar                                                     |\n");
    printf("|                                   6 Limpar Banco                                                |\n");
    printf("|                                   0 Sair                                                        |\n");
    printf("|_________________________________________________________________________________________________|\n\n");
}

void cadastroAgendamento(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         CADASTRO AGENDAMENTO                                    |\n");
    printf("|_________________________________________________________________________________________________|\n");

    Agendamento *agendamento;
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));

    
    int idInteiro = atribuirId("./dados/agendamentos.bin", sizeof(Agendamento));
    sprintf(agendamento->id, "%d", idInteiro); // Converte int para string

    recebeCpf(agendamento->cpfCliente);
    recebeId(agendamento->idServico,"serviço");
    recebeData(agendamento->data,"agendamento");
    recebeHora(agendamento->hora);

    cadastrarAgendamento(agendamento);
}

void listaAgendamento(void) {
    Agendamento *agendamento;
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));
    
    FILE * arquivo = fopen("./dados/agendamentos.bin", "rb");
    verificaArquivo(arquivo);
    
    printf("\n%-10s | %-25s | %-15s  | %-12s | %-8s\n", "ID", "Nome do cliente", "Serviço", "Data", "Hora");
    printf("--------------------------------------------------------------------------------------------------\n");
    while (fread(agendamento,sizeof(Agendamento),1,arquivo)){
        if (agendamento->status == True) {
            exibirDadosAgendamento(agendamento);
        }
    }
    fclose(arquivo);
    free(agendamento);

    printf("\n>>> Tecle <ENTER> para encerrar o programa.\n");
    getchar();
}

void exibeAgendamento(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         EXIBIR AGENDAMENTO                                      |\n");
    printf("|_________________________________________________________________________________________________|\n");

    char idAgendamento[50];
    recebeId(idAgendamento,"agendamento");

    exibirAgendamento(idAgendamento);
    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void atualizaAgendamento(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         ATUALIZAR AGENDAMENTO                                   |\n");
    printf("|_________________________________________________________________________________________________|\n");

    char idAgendamento[50];
    recebeId(idAgendamento,"agendamento");
    
    if(!verificaAgendamento(idAgendamento)){
        printf("\n>>> Nenhuma ação será realizada.\n");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    int opcao;
    do {
        system("clear||cls");
        exibirAgendamento(idAgendamento);

        printf("\nQual dado você deseja alterar?\n");
        printf("\n1 - CPF");
        printf("\n2 - ID Servico");
        printf("\n3 - Data");
        printf("\n4 - Hora");
        printf("\n0 - Finalizar operação\n\n");
        scanf("%d", &opcao);
        getchar();
        if (opcao != 0) {
            atualizarAgendamento(idAgendamento, opcao);
        }
    } while (opcao != 0);

}

void deletaAgendamento(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         DELETAR AGENDAMENTO                                     |\n");
    printf("|_________________________________________________________________________________________________|\n");

    char idAgendamento[50];
    recebeId(idAgendamento,"agendamento");
    
    if(!exibirAgendamento(idAgendamento)){
        printf("\n>>> Nenhuma ação será realizada.\n");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    int excluir;
    printf("\nTem certeza que deseja excluir esse agendamento? (0 - excluir / 1 - cancelar operação): ");
    scanf("%d", &excluir);
    getchar();

    if (excluir == 0) {
        deletarAgendamento(idAgendamento);
        printf("\nAgendamento removido com sucesso.");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
    } else {
        printf("\nOperação cancelada.");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    
}

void limparBancoAgendamento(void) {              
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         LIMPAR BANCO AGENDAMENTO                                |\n");
    printf("|_________________________________________________________________________________________________|\n");

    Agendamento * agendamento;
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));
    
    FILE * arquivo = fopen("./dados/agendamentos.bin", "rb");
    
    FILE * arquivoTemp = fopen("./dados/agendamentos_temp.bin", "wb");
    verificaArquivoTemporario(arquivoTemp);

    int servicosMantidos = 0;
    int servicosRemovidos = 0;
    while (fread(agendamento, sizeof(Agendamento), 1, arquivo) == 1) {
        if (agendamento->status == True) {
            fwrite(agendamento, sizeof(Agendamento), 1, arquivoTemp);
            servicosMantidos++;
        } else {
            servicosRemovidos++;
        }
    }
    
    free(agendamento);
    fclose(arquivo);
    fclose(arquivoTemp);
    
    trocaArquivos("./dados/agendamentos.bin", "./dados/agendamentos_temp.bin");
    
    printf("Limpeza do banco concluída com sucesso!\n");
    printf("Agendamentos mantidos: %d\n", servicosMantidos);
    printf("Agendamentos removidos: %d\n", servicosRemovidos);
    printf("\n>>> Tecle <ENTER> para continuar.\n");
    getchar();
}

void opcaoAgendamento() {

    char opcao = '9';

    do{

        telaAgendamento();
        opcao = recebeOpcao();

        switch (opcao) {

            case '1':
                cadastroAgendamento();
                break;

            case '2':
                exibeAgendamento();
                break;

            case '3':
                listagemAgendamento();
                break;

            case '4':
                atualizaAgendamento();
                break;

            case '5':
                deletaAgendamento();
                break;

            case '6':
                limparBancoAgendamento();
                break;
        }

    } while (opcao != '0');

}


void cadastrarAgendamento(Agendamento * agendamento) {
    criaDiretorio();
    FILE * arquivo = fopen("./dados/agendamentos.bin", "ab");
    verificaArquivo(arquivo);
    
    agendamento->status = True;
    fwrite(agendamento, sizeof(Agendamento), 1, arquivo);

    free(agendamento);
    fclose(arquivo);
}

void atualizarAgendamento(char idAgendamento[], int opcao) {
    char dado[50];
    if (opcao == 1) {
        recebeCpf(dado);
    } else if (opcao == 2) {
        printf("\nDigite o ID serviço: ");
        scanf("%[^\n]", dado);
    } else if (opcao == 3) {
        recebeData(dado, "agendamento");
    } else if (opcao == 4) {
        recebeHora(dado);
    }

    Agendamento *agendamento;
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));

    FILE * arquivo = fopen("./dados/agendamentos.bin", "r+b");
    verificaArquivo(arquivo);

    int encontrado = False;

    while (fread(agendamento, sizeof(Agendamento), 1, arquivo) && encontrado == False) {
        if (strcmp(idAgendamento, agendamento->id) == 0) {
            if (opcao == 1) {
                strcpy(agendamento->cpfCliente, dado);
            } else if (opcao == 2) {
                strcpy(agendamento->idServico, dado);
            } else if (opcao == 3) {
                strcpy(agendamento->data, dado);
            } else if (opcao == 4) {
                strcpy(agendamento->hora, dado);
            }
            
            encontrado = True;
            fseek(arquivo, (-1) * sizeof(Agendamento), SEEK_CUR);
            fwrite(agendamento, sizeof(Agendamento), 1, arquivo);
        }
    }
    fclose(arquivo);
    free(agendamento);
}

void deletarAgendamento(char idAgendamento[]) {
    Agendamento * agendamento;
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));

    FILE * arquivo = fopen("./dados/agendamentos.bin", "r+b");
    verificaArquivo(arquivo);

    int encontrado = False;
    while (fread(agendamento, sizeof(Agendamento), 1, arquivo) && encontrado == False) {
        if (strcmp(agendamento->id, idAgendamento) == 0) {
            agendamento->status = False;
            encontrado = True;
            fseek(arquivo, (-1) * sizeof(Agendamento), SEEK_CUR);
            fwrite(agendamento, sizeof(Agendamento), 1, arquivo);
        }
    }
    free(agendamento);
    fclose(arquivo);
}

int exibirAgendamento(char idAgendamento[]) {
    Agendamento *agendamento;
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));

    FILE * arquivo = fopen("./dados/agendamentos.bin", "rb");

    verificaArquivo(arquivo);

    int encontrado = False;
    while (fread(agendamento,sizeof(Agendamento),1,arquivo) && encontrado == False){
        if(strcmp(idAgendamento,agendamento->id) == 0 && agendamento->status == True){
            char* cliente = nomeCliente(agendamento->cpfCliente);
            char* servico = nomeServico(agendamento->idServico);
            printf("\n\t\t\t <--- Agendamento Encontrado ---> \n\n");
            printf("\t\t\tID: %s\n",agendamento->id);
            printf("\t\t\tNome do cliente: %s\n", cliente);
            printf("\t\t\tServiço: %s\n",servico);
            printf("\t\t\tData: %s\n",agendamento->data);
            printf("\t\t\tHora: %s\n",agendamento->hora);
            free(cliente);
            encontrado = True;
        }
    }

    fclose(arquivo);
    free(agendamento);

    if (encontrado == False) {
        printf("\n\t\t\t <--- Agendamento não encontrado ---> \n\n");
        return 0;
    }
    return 1;
}

void listagemAgendamento(void) {
    char opcao = '0';
    do {
        system("clear||cls");
        printf("\n");
        printf("|_________________________________________________________________________________________________|\n");
        printf("|                                                                                                 |\n");
        printf("|                                     ESCOLHA O TIPO DE LISTAGEM                                  |\n");
        printf("|_________________________________________________________________________________________________|\n");
        printf("|                                                                                                 |\n");
        printf("|                                   1 Todos os agendamentos                                       |\n");
        printf("|                                   2 Filtrar data                                                |\n");
        printf("|                                   0 Sair                                                        |\n");
        printf("|_________________________________________________________________________________________________|\n\n");
        
        char dataBusca[16];
        opcao = recebeOpcao();
        switch (opcao) {
            case '1':
                listaAgendamento();
                break;

            case '2':
                printf("Digite a data pelo qual deseja buscar: ");
                scanf(" %15[^\n]", dataBusca);
                getchar();
                listarAgendamentosData(dataBusca);
                break;

            case '0':
                break;

            default:
                printf("\n>>> Opção inválida.");
                printf("\n>>> Tecle <ENTER> para continuar...\n");
                getchar();
        }
    } while (opcao != '0');
}

void exibirDadosAgendamento(Agendamento* agendamento){
    char* cliente = nomeCliente(agendamento->cpfCliente);
    char* servico = nomeServico(agendamento->idServico);
    printf("%-10s | %-25s | %-15s | %-12s | %-8s\n",
        agendamento->id,
        cliente,
        servico, 
        agendamento->data,
        agendamento->hora);
    free(cliente);
    free(servico);
}

void listarAgendamentosData(char* dataBusca){
    Agendamento * agendamento = malloc(sizeof(Agendamento));
    FILE *arquivo = fopen("./dados/agendamentos.bin", "rb");
    verificaArquivo(arquivo);

    printf("\n%-10s | %-25s | %-15s  | %-12s | %-8s\n", "ID", "Nome do cliente", "Serviço", "Data", "Hora");
    printf("--------------------------------------------------------------------------------------------------\n");
    while (fread(agendamento, sizeof(Agendamento), 1, arquivo)) {

        char* filtrado = strstr(agendamento->data, dataBusca);
        if (agendamento->status == True && filtrado != NULL) {
            exibirDadosAgendamento(agendamento);
        }
    }
    fclose(arquivo);
    free(agendamento); 

    printf("\n>>> Tecle <ENTER> para encerrar o programa.\n");
    getchar();
}

int verificaAgendamento(char idAgendamento[]) {
    Agendamento *agendamento;
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));

    FILE * arquivo = fopen("./dados/agendamentos.bin", "rb");

    verificaArquivo(arquivo);

    int encontrado = False;
    while (fread(agendamento,sizeof(Agendamento),1,arquivo) && encontrado == False){
        if(strcmp(idAgendamento,agendamento->id) == 0 && agendamento->status == True){
            encontrado = True;
        }
    }
    fclose(arquivo);
    free(agendamento);

    if (encontrado == False) {
        printf("\n\t\t\t <--- Agendamento não encontrado ---> \n\n");
        return 0;
    }
    return 1;
}
