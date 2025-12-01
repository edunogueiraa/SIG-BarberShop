#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include "include/servicos.h"
#include "include/utils.h"


void telaServico(void) {
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
    printf("|                                         MENU SERVIÇO                                            |\n");
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
void cadastroServico(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         CADASTRO SERVIÇO                                        |\n");
    printf("|_________________________________________________________________________________________________|\n");

    Servico *servico;
    servico = (Servico*) malloc(sizeof(Servico));

    int idInteiro = atribuirId("./dados/servicos.bin", sizeof(Servico));
    sprintf(servico->id, "%d", idInteiro);

    recebeNome(servico->nome,"serviço");
    recebeValor(servico->valor);
    recebeDuracaoTempo(servico->duracao);

    cadastrarServico(servico);
    free(servico);
}
void exibirDadosServicos(Servico * servico){
    float valorNumerico = atof(servico->valor);
        printf("%-19s | %-10s | %-13s | R$ %.2f\n",
            servico->nome,
            servico->id,
            servico->duracao,
            valorNumerico);
}
void listaServico(void){
    Servico *servico;
    servico = (Servico*) malloc(sizeof(Servico));
    
    FILE * arquivo = fopen("./dados/servicos.bin", "rb");
    verificaArquivo(arquivo);
    
    printf("\n%-20s | %-10s | %-15s | %s\n", "Nome do serviço", "ID", "Duração", "Valor (R$)");
    printf("----------------------------------------------------------------------------\n");
    while (fread(servico,sizeof(Servico),1,arquivo)){
        if (servico->status == True) {
            exibirDadosServicos(servico);
        }
    }
    fclose(arquivo);
    free(servico);

    printf("\n>>> Tecle <ENTER> para encerrar o programa.\n");
    getchar();
}
void listarServicosNome(char* filtro){
    Servico *servico = malloc(sizeof(Servico));
    FILE *arquivo = fopen("./dados/servicos.bin", "rb");
    verificaArquivo(arquivo);

    printf("\n%-20s | %-10s | %-15s | %s\n", "Nome do serviço", "ID", "Duração", "Valor (R$)");
    printf("----------------------------------------------------------------------------------------------------------------------\n");
    while (fread(servico, sizeof(Servico), 1, arquivo)) {
        char* filtrado = strstr(servico->nome, filtro);
        if (servico->status == True && filtrado != NULL) {
            exibirDadosServicos(servico);
        }
    }
    fclose(arquivo);
    free(servico); 

    printf("\n>>> Tecle <ENTER> para encerrar o programa.\n");
    getchar();
}
void exibeServico(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         EXIBIR SERVIÇO                                          |\n");
    printf("|_________________________________________________________________________________________________|\n");

    char idServico[50];
    recebeId(idServico,"serviço");

    exibirServico(idServico);
    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
    
}
void atualizaServico(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         ATUALIZAR SERVIÇO                                       |\n");
    printf("|_________________________________________________________________________________________________|\n");

    char idServico[50];
    recebeId(idServico,"serviço");

    if(!exibirServico(idServico)){
        printf("\n>>> Nenhuma ação será realizada.\n");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    int opcao;
    do {
        system("clear||cls");
        exibirServico(idServico);

        printf("\nQual dado você deseja alterar?\n");
        printf("\n1 - Nome Serviço");
        printf("\n2 - Valor");
        printf("\n3 - Duracao Serviço");
        printf("\n0 - Finalizar operação\n\n");
        scanf("%d", &opcao);
        getchar();
        if (opcao != 0) {
            atualizarServico(idServico, opcao);
        }
    } while (opcao != 0);
}
void deletaServico(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         DELETAR SERVIÇO                                         |\n");
    printf("|_________________________________________________________________________________________________|\n");

    char idServico[50];
    recebeId(idServico,"serviço");
    
    if(!exibirServico(idServico)){
        printf("\n>>> Nenhuma ação será realizada.\n");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
        return;
    }

    int excluir;
    printf("\nTem certeza que deseja excluir esse servico? (0 - excluir / 1 - cancelar operação): ");
    scanf("%d", &excluir);
    getchar();

    if (excluir == 0) {
        deletarServico(idServico);
        printf("\nServico removido com sucesso.");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
    } else {
        printf("\nOperação cancelada.");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    
}
void limparBancoServico(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         LIMPAR BANCO SERVIÇO                                    |\n");
    printf("|_________________________________________________________________________________________________|\n");

    Servico *servico;
    servico = (Servico*) malloc(sizeof(Servico));
    
    FILE * arquivo = fopen("./dados/servicos.bin", "rb");
    verificaArquivo(arquivo);
    
    FILE * arquivoTemp = fopen("./dados/servicos_temp.bin", "wb");
    verificaArquivoTemporario(arquivoTemp);

    int servicosMantidos = 0;
    int servicosRemovidos = 0;
    while (fread(servico, sizeof(Servico), 1, arquivo) == 1) {
        if (servico->status == True) {
            fwrite(servico, sizeof(Servico), 1, arquivoTemp);
            servicosMantidos++;
        } else {
            servicosRemovidos++;
        }
    }
    
    free(servico);
    fclose(arquivo);
    fclose(arquivoTemp);
    
    trocaArquivos("./dados/servicos.bin", "./dados/servicos_temp.bin");
    
    printf("Limpeza do banco concluída com sucesso!\n");
    printf("Serviços mantidos: %d\n", servicosMantidos);
    printf("Serviços removidos: %d\n", servicosRemovidos);
    printf("\n>>> Tecle <ENTER> para continuar.\n");
    getchar();

}
void opcaoServicos(void) {
    char opcao = '9';

    do {

        telaServico();
        opcao = recebeOpcao();

        switch (opcao) {

            case '1':
                cadastroServico();
                break;

            case '2':
                exibeServico();
                break;

            case '3':
                listagemServico();
                break;
            
            case '4':
                atualizaServico();
                break;

            case '5':
                deletaServico();
                break;
            
            case '6':
                limparBancoServico();
                break;
        }

    } while (opcao != '0');

}
void cadastrarServico(Servico * servico) {
    criaDiretorio();
    FILE * arquivo = fopen("./dados/servicos.bin", "ab");
    verificaArquivo(arquivo);
    
    servico->status = True;
    fwrite(servico, sizeof(Servico), 1, arquivo);

    fclose(arquivo);
}
void atualizarServico(char idServico[], int opcao) {
    char dado[50];
    if (opcao == 1) {
        recebeNome(dado, "serviço");
    } else if (opcao == 2) {
        recebeValor(dado);
    } else if (opcao == 3) {
        recebeDuracaoTempo(dado);
    }

    Servico *servico;
    servico = (Servico*) malloc(sizeof(Servico));

    FILE * arquivo = fopen("./dados/servicos.bin", "r+b");
    verificaArquivo(arquivo);

    int encontrado = False;

    while (fread(servico, sizeof(Servico), 1, arquivo) && encontrado == False) {
        if (strcmp(idServico, servico->id) == 0) {
            if (opcao == 1) {
                strcpy(servico->nome, dado);
            } else if (opcao == 2) {
                strcpy(servico->valor, dado);
            } else if (opcao == 3) {
                strcpy(servico->duracao, dado);
            }
            
            encontrado = True;
            fseek(arquivo, (-1) * sizeof(Servico), SEEK_CUR);
            fwrite(servico, sizeof(Servico), 1, arquivo);
        }
    }
    fclose(arquivo);
    free(servico);
}
void deletarServico(char idServico[]) {
    Servico *servico;
    servico = (Servico*) malloc(sizeof(Servico));

    FILE * arquivo = fopen("./dados/servicos.bin", "r+b");
    verificaArquivo(arquivo);

    int encontrado = False;
    while (fread(servico, sizeof(Servico), 1, arquivo) && encontrado == False) {
        if (strcmp(servico->id, idServico) == 0) {
            servico->status = False;
            encontrado = True;
            fseek(arquivo, (-1) * sizeof(Servico), SEEK_CUR);
            fwrite(servico, sizeof(Servico), 1, arquivo);
        }
    }
    free(servico);
    fclose(arquivo);
}
int exibirServico(char idServico[]) {
    Servico *servico;
    servico = (Servico*) malloc(sizeof(Servico));
    FILE * arquivo = fopen("./dados/servicos.bin", "rb");

    verificaArquivo(arquivo);

    int encontrado = False;
    while (fread(servico,sizeof(Servico),1,arquivo) && encontrado == False){
        if(strcmp(idServico,servico->id) == 0 && servico->status == True){
            printf("\n\t\t\t <--- Servico Encontrado ---> \n\n");
            printf("\t\t\tNome do serviço: %s\n", servico->nome);
            printf("\t\t\tID do serviço: %s\n", servico->id);
            printf("\t\t\tValor: R$ %.2f\n", atof(servico->valor));
            printf("\t\t\tDuração do serviço: %s\n", servico->duracao);
            
            fclose(arquivo);
            
        }
    }
    fclose(arquivo);
    free(servico);

    if (encontrado == False) {
        printf("\n\t\t\t <--- Serviço não encontrado ---> \n\n");
        return 0;
    }
    return 1;
}
void listagemServico(void) {
    char opcao = '0';
    do {
        system("clear||cls");
        printf("\n");
        printf("|_________________________________________________________________________________________________|\n");
        printf("|                                                                                                 |\n");
        printf("|                                     ESCOLHA O TIPO DE LISTAGEM                                  |\n");
        printf("|_________________________________________________________________________________________________|\n");
        printf("|                                                                                                 |\n");
        printf("|                                   1 Todos os Serviços                                           |\n");
        printf("|                                   2 Filtrar nome                                                |\n");
        printf("|                                   0 Sair                                                        |\n");
        printf("|_________________________________________________________________________________________________|\n\n");
        
        char filtro[50];
        opcao = recebeOpcao();
        switch (opcao) {
            case '1':
                listaServico();
                break;

            case '2':
                printf("Digite o serviço pelo qual buscar: ");
                scanf("%[^\n]", filtro);
                getchar();
                listarServicosNome(filtro);
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
char* nomeServico(char* id) {
    Servico* servico;
    servico = (Servico*) malloc(sizeof(Servico));
    
    char* servicoNome = (char*) malloc(50);
    FILE * arquivo = fopen("./dados/servicos.bin", "rb");
    verificaArquivo(arquivo);

    while (fread(servico, sizeof(Servico), 1, arquivo)) {
        if (strcmp(servico->id, id) == 0 && servico->status == True) {
            strcpy(servicoNome, servico->nome);
            free(servico);
            fclose(arquivo);
            return servicoNome;
        }
    }
    
    return NULL;
}



