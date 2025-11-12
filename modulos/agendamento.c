#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "include/agendamento.h"
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
    recebeNome(agendamento->nomeCliente,"agendamento");
    recebeId(agendamento->idServico,"servico");
    recebeData(agendamento->data,"agendamento");
    recebeHora(agendamento->hora);

    cadastrarAgendamento(agendamento);

}

void listaAgendamento(void) {
    printf("\n%-10s | %-20s | %-25s | %-10s | %-12s | %-8s\n", "ID", "CPF", "Nome", "ID Serviço", "Data", "Hora");
    printf("--------------------------------------------------------------------------------------------------\n");
    Agendamento *agendamento;
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));

    FILE * arquivo = fopen("./dados/agendamentos.bin", "rb");

    verificaArquivo(arquivo);

    while (fread(agendamento,sizeof(Agendamento),1,arquivo)){
        if (agendamento->status == True) {
            printf("%-10s | %-20s | %-25s | %-10s | %-12s | %-8s\n",
                agendamento->id,
                exibeCpf,
                agendamento->nomeCliente,
                agendamento->idServico, 
                agendamento->data,
                agendamento->hora);
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

    int opcao;
    do {
        system("clear||cls");
        exibirAgendamento(idAgendamento);

        printf("\nQual dado você deseja alterar?\n");
        printf("\n1 CPF");
        printf("\n2 Nome");
        printf("\n3 ID Servico");
        printf("\n4 Data");
        printf("\n5 Hora");
        printf("\n0 Finalizar operação\n\n");
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
    
    exibirAgendamento(idAgendamento);

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
        recebeOpcao(&opcao);

        switch (opcao) {

            case '1':
                cadastroAgendamento();
                break;

            case '2':
                exibeAgendamento();
                break;

            case '3':
                listaAgendamento();
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
    criarDiretorio();
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
        recebeNome(dado, "cliente");
    } else if (opcao == 3) {
        printf("\nID Servico: ");
        scanf("%[^\n]", dado);
    } else if (opcao == 4) {
        recebeData(dado, "agendamento");
    } else if (opcao == 5) {
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
                strcpy(agendamento->nomeCliente, dado);
            } else if (opcao == 3) {
                strcpy(agendamento->idServico, dado);
            } else if (opcao == 4) {
                strcpy(agendamento->data, dado);
            } else if (opcao == 5) {
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

void exibirAgendamento(char idAgendamento[]) {
    Agendamento *agendamento;
    agendamento = (Agendamento*) malloc(sizeof(Agendamento));

    FILE * arquivo = fopen("./dados/agendamentos.bin", "rb");

    verificaArquivo(arquivo);

        while (fread(agendamento,sizeof(Agendamento),1,arquivo)){
            if(strcmp(idAgendamento,agendamento->id) == 0 && agendamento->status == True){
                printf("\n\t\t\t <--- Agendamento Encontrado ---> \n\n");
                printf("\t\t\tID: %s\n",agendamento->id);
                exibeCpf(agendamento->cpfCliente);
                printf("\t\t\tNome: %s\n",agendamento->nomeCliente);
                printf("\t\t\tID Servico: %s\n",agendamento->idServico);
                printf("\t\t\tData: %s\n",agendamento->data);
                printf("\t\t\tHora: %s\n",agendamento->hora);
                printf("\n>>> Tecle <ENTER> para continuar...\n");
                getchar();
                fclose(arquivo);
                return;
            }
        }

    free(agendamento);
}


