#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include "include/estoqueProdutos.h"
#include "include/utils.h"

// Assinatura de funções
void cadastrarProduto(Estoque * estoque);
void exibirProduto(char idProduto[]);
void atualizarProduto(char idProduto[], int opcao);
void deletarProduto(char idProduto[]);
void excluirBancoEstoque(void);

void telaEstoque(void) {
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
    printf("|                                  MENU ESTOQUE DE PRODUTOS                                       |\n");
    printf("|_________________________________________________________________________________________________|\n");
    printf("|                                                                                                 |\n");
    printf("|                                   1 Cadastrar Produto                                           |\n");
    printf("|                                   2 Exibir Produto                                              |\n");
    printf("|                                   3 Listar Produtos                                             |\n");
    printf("|                                   4 Atualizar Produto                                           |\n");
    printf("|                                   5 Deletar Produto                                             |\n");
    printf("|                                   6 Limpar Estoque                                              |\n");
    printf("|                                   0 Sair                                                        |\n");
    printf("|_________________________________________________________________________________________________|\n\n");
    
}

void cadastroEstoque(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         CADASTRO PRODUTO                                        |\n");
    printf("|_________________________________________________________________________________________________|\n");

    Estoque * estoque;
    estoque = (Estoque *) malloc(sizeof(Estoque));
    
    int idInteiro = atribuirId("./dados/estoque.bin", sizeof(Estoque));
    sprintf(estoque->id, "%d", idInteiro); // Converte int para string

    recebeNome(estoque->nome, "produto");
    recebeTipo(estoque->tipo);
    recebeValor(estoque->valor);
    
    cadastrarProduto(estoque);
    free(estoque);
}

void exibeProduto(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                          EXIBIR PRODUTO                                         |\n");
    printf("|_________________________________________________________________________________________________|\n");
    
    char idProduto[50];
    printf("\nInforme o ID do produto: \n");
    scanf("%s", idProduto);
    getchar();

    exibirProduto(idProduto);
    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void listaEstoque(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         ESTOQUE COMPLETO                                        |\n");
    printf("|_________________________________________________________________________________________________|\n");
    Estoque * estoque;
    estoque = (Estoque *) malloc(sizeof(Estoque));

    FILE * arquivo = fopen("./dados/estoque.bin", "rb");

    while (fread(estoque, sizeof(Estoque), 1, arquivo)) {
        if (estoque->status == True) {
            printf("\n\t\t\tNome do produto: %s\n", estoque->nome);
            printf("\t\t\tID do produto: %s\n", estoque->id);
            printf("\t\t\tTipo do produto: %s\n", estoque->tipo);
            exibeValor(estoque->valor);
        }
    }
    fclose(arquivo);
    free(estoque);

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualizaProduto(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         ATUALIZAR PRODUTO                                       |\n");
    printf("|_________________________________________________________________________________________________|\n");

    char idProduto[50];
    printf("\nInforme o ID do produto: ");
    scanf("%[^\n]", idProduto);
    getchar();

    int opcao = 0;
    do {
        system("clear||cls");
        exibirProduto(idProduto);

        printf("\nQual dado você deseja alterar?\n");
        printf("\n1 Nome");
        printf("\n2 Tipo");
        printf("\n3 Valor");
        printf("\n0 Finalizar operação\n\n");
        scanf("%d", &opcao);
        getchar();
        if (opcao != 0) {
            atualizarProduto(idProduto, opcao);
        }
    } while (opcao != 0);
}

void deletaProduto(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         DELETAR PRODUTO                                         |\n");
    printf("|_________________________________________________________________________________________________|\n");

    char idProduto[50];
    printf("\nInforme o ID do produto: \n");
    scanf("%s", idProduto);
    getchar();

    exibirProduto(idProduto);

    int excluir;
    printf("\nTem certeza que deseja excluir esse produto? (0 - excluir / 1 - cancelar operação): ");
    scanf("%d", &excluir);
    getchar();

    if (excluir == 0) {
        deletarProduto(idProduto);
        printf("\nProduto removido com sucesso.");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
    } else {
        printf("\nOperação cancelada.");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
}

void limparBancoEstoque(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         LIMPAR BANCO CLIENTE                                    |\n");
    printf("|_________________________________________________________________________________________________|\n");

    excluirBancoEstoque();

    printf("\n>>> Tecle <ENTER> para continuar.\n");
    getchar();
}

void opcaoEstoque(void) {
    char opcao = '9';

    do {
        telaEstoque();
        recebeOpcao(&opcao);

        switch (opcao) {

            case '1':
                cadastroEstoque();
                break;

            case '2':
                exibeProduto();
                break;

            case '3':
                listaEstoque();
                break;

            case '4':
                atualizaProduto();
                break;

            case '5':
                deletaProduto();
                break;

            case '6':
                limparBancoEstoque();
                break;
            }
    } while (opcao != '0');
}

void cadastrarProduto(Estoque * estoque) {
    criarDiretorio();
    FILE * arquivo = fopen("./dados/estoque.bin", "ab");
    verificaArquivo(arquivo);

    estoque->status = True;
    fwrite(estoque, sizeof(Estoque), 1, arquivo);

    fclose(arquivo);
}

void exibirProduto(char idProduto[]) {
    Estoque * estoque;
    estoque = (Estoque *) malloc(sizeof(Estoque));

    FILE * arquivo = fopen("./dados/estoque.bin", "rt");
    verificaArquivo(arquivo);
    
    int encontrado = False;
    while (fread(estoque, sizeof(Estoque), 1, arquivo) && encontrado == False) {
        if (strcmp(idProduto, estoque->id) == 0 && estoque->status == True) {
            printf("\n\t\t\t <--- Produto Encontrado ---> \n\n");
            printf("\t\t\tNome do produto: %s\n", estoque->nome);
            printf("\t\t\tID do produto: %s\n", estoque->id);
            printf("\t\t\tTipo do produto: %s\n", estoque->tipo);
            exibeValor(estoque->valor);
            
            encontrado = True;
        }
    }
    fclose(arquivo);
    free(estoque);
}

void atualizarProduto(char idProduto[], int opcao) {
    char dado[50];
    if (opcao == 1) {
        recebeNome(dado, "produto");
    } else if (opcao == 2) {
        recebeTipo(dado);
    } else if (opcao == 3) {
        recebeValor(dado);
    }

    Estoque * estoque;
    estoque = (Estoque *) malloc(sizeof(Estoque));

    FILE * arquivo = fopen("./dados/estoque.bin", "r+b");
    
    int encontrado = False;
    while (fread(estoque, sizeof(Estoque), 1, arquivo) && encontrado == False) {
        if (strcmp(idProduto, estoque->id) == 0) {
            if (opcao == 1) {
                strcpy(estoque->nome, dado);
            } else if (opcao == 2) {
                strcpy(estoque->tipo, dado);
            } else if (opcao == 3) {
                strcpy(estoque->valor, dado);
            }
            
            fseek(arquivo, (-1) * sizeof(Estoque), SEEK_CUR);
            fwrite(estoque, sizeof(Estoque), 1, arquivo);
            encontrado = True;
        }
    }
    fclose(arquivo);
    free(estoque);
}

void deletarProduto(char idProduto[]) {
    Estoque * estoque;
    estoque = (Estoque *) malloc(sizeof(Estoque));
    
    FILE * arquivo = fopen("./dados/estoque.bin", "r+b");
    
    int encontrado = False;
    
    while (fread(estoque, sizeof(Estoque), 1, arquivo) && encontrado == False) {
        if (strcmp(idProduto, estoque->id) == 0) {
            estoque->status = False;

            encontrado = True;
            fseek(arquivo, (-1) * sizeof(Estoque), SEEK_CUR);
            fwrite(estoque, sizeof(Estoque), 1, arquivo);
        }
    }
    fclose(arquivo);
    free(estoque);
}

void excluirBancoEstoque(void) {
    Estoque * estoque;
    estoque = (Estoque *) malloc(sizeof(Estoque));
    
    int estoquesMantidos = 0;
    int estoquesRemovidos = 0;
    
    FILE * arquivoTemp = fopen("./dados/estoque_temp.bin", "wb");
    verificaArquivoTemporario(arquivoTemp);
    
    FILE * arquivo = fopen("./dados/estoque.bin", "rb");
    while (fread(estoque, sizeof(Estoque), 1, arquivo) == 1) {
        if (estoque->status == True) {
            fwrite(estoque, sizeof(Estoque), 1, arquivoTemp);
            estoquesMantidos++;
        } else {
            estoquesRemovidos++;
        }
    }
    
    fclose(arquivo);
    fclose(arquivoTemp);
    free(estoque);

    trocaArquivos("./dados/estoque.bin", "./dados/estoque_temp.bin");

    printf("Limpeza do banco concluída com sucesso!\n");
    printf("Estoques mantidos: %d\n", estoquesMantidos);
    printf("Estoques removidos: %d\n", estoquesRemovidos);
}