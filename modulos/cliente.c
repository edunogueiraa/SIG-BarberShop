#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include "include/cliente.h"
#include "include/utils.h"

// Assinatura de funções
void cadastrarCliente(Cliente * cliente);
void exibirCliente(char cpfCliente[]);
void atualizarCliente(char cpfCliente[], int opcao);
void deletarCliente(char cpfCliente[]);
void excluirBancoCliente(void);
Cliente* iniciarLista(void);
Cliente* retornaUltimo(void);
void atualizarLista(Cliente* ultimo, Cliente* novo, FILE* arquivo);

void telaCliente(void) {
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
    printf("|                                         MENU CLIENTE                                            |\n");
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

void cadastroCliente(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         CADASTRO CLIENTE                                        |\n");
    printf("|_________________________________________________________________________________________________|\n");
    
    Cliente * cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));

    recebeNome(cliente->nome,"cliente");
    recebeCpf(cliente->cpf);
    recebeEmail(cliente->email);
    recebeData(cliente->data,"Nascimento");
    recebeCelular(cliente->celular);

    cadastrarCliente(cliente);
    free(cliente);
}

void exibeCliente(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         LISTAR CLIENTE                                          |\n");
    printf("|_________________________________________________________________________________________________|\n");


    char cpfCliente[15];
    recebeCpf(cpfCliente);

    exibirCliente(cpfCliente);
    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void listaClientes(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                        LISTA DE CLIENTES                                        |\n");
    printf("|_________________________________________________________________________________________________|\n");
    Cliente * cliente = iniciarLista();
    
    FILE * arquivo = fopen("./dados/clientes.bin", "rb");
    verificaArquivo(arquivo);

    while (fread(cliente, sizeof(Cliente), 1, arquivo)) {
    // while (cliente->proximo != NULL) {
        if (cliente->status == True) {
            printf("\n\t\t\tNome: %s\n", cliente->nome);
            exibeCpf(cliente->cpf);
            printf("\t\t\tEmail: %s\n", cliente->email);
            printf("\t\t\tData: %s\n", cliente->data);
            exibeCelular(cliente->celular);
        }
        cliente = cliente->proximo;
    }
    fclose(arquivo);
    free(cliente);

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualizaCliente(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         ATUALIZAR CLIENTE                                       |\n");
    printf("|_________________________________________________________________________________________________|\n");

    char cpfCliente[15];
    recebeCpf(cpfCliente);

    int opcao;
    do {
        system("clear||cls");
        exibirCliente(cpfCliente);

        printf("\nQual dado você deseja alterar?\n");
        printf("\n1 Nome");
        printf("\n2 Email");
        printf("\n3 Data de nascimento");
        printf("\n4 Celular");
        printf("\n0 Finalizar operação\n\n");
        scanf("%d", &opcao);
        getchar();
        if (opcao != 0) {
            atualizarCliente(cpfCliente, opcao);
        }
    } while (opcao != 0);
    
}

void deletaCliente(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         DELETAR CLIENTE                                         |\n");
    printf("|_________________________________________________________________________________________________|\n");

    char cpfCliente[15];
    recebeCpf(cpfCliente);
    
    exibirCliente(cpfCliente);
    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();

    int excluir;
    printf("\nTem certeza que deseja excluir esse cliente? (0 - excluir / 1 - cancelar operação): ");
    scanf("%d", &excluir);
    getchar();

    if (excluir == 0) {
        deletarCliente(cpfCliente);
        printf("\nCliente removido com sucesso.");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
    } else {
        printf("\nOperação cancelada.");
        printf("\n>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
}

void limparBancoCliente(void) {
    system("clear||cls");
    printf("\n");
    printf("___________________________________________________________________________________________________\n");
    printf("|                                                                                                 |\n");
    printf("|                                         LIMPAR BANCO CLIENTE                                    |\n");
    printf("|_________________________________________________________________________________________________|\n");

    excluirBancoCliente();

    printf("\n>>> Tecle <ENTER> para continuar.\n");
    getchar();
}

void opcaoCliente(void) {
    char opcao = '9';

    do {
        telaCliente();
        recebeOpcao(&opcao);
        
        switch (opcao) {
            case '1':
                cadastroCliente();
                break;
            
            case '2':
                exibeCliente();
                break;
            
            case '3':
                listaClientes();
                break;

            case '4':
                atualizaCliente();
                break;

            case '5':
                deletaCliente();
                break;

            case '6':
                limparBancoCliente();
                break;
        }
    } while (opcao != '0');
}

void cadastrarCliente(Cliente * cliente) {
    criarDiretorio();
    FILE * arquivo = fopen("./dados/clientes.bin", "ab");
    verificaArquivo(arquivo);
    
    Cliente* ultimo = retornaUltimo();
    cliente->status = True;
    cliente->proximo = NULL;
    fwrite(cliente, sizeof(Cliente), 1, arquivo);
    atualizarLista(ultimo, cliente, arquivo);
    
    fclose(arquivo);
    free(ultimo);
}

void exibirCliente(char cpfCliente[]) {
    Cliente * cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));

    FILE * arquivo = fopen("./dados/clientes.bin", "rb");
    verificaArquivo(arquivo);

    int encontrado = False;
    while (fread(cliente, sizeof(Cliente), 1, arquivo) && encontrado == False) {
        if(strcmp(cliente->cpf, cpfCliente) == 0 && cliente->status == True) {
            printf("\n\t\t\t <--- Cliente Encontrado ---> \n\n");
            printf("\t\t\tNome: %s\n", cliente->nome);
            exibeCpf(cliente->cpf);
            printf("\t\t\tEmail: %s\n", cliente->email);
            printf("\t\t\tData: %s\n", cliente->data);
            exibeCelular(cliente->celular);
            encontrado = True;
        }
    }
    fclose(arquivo);
    free(cliente);
}

void atualizarCliente(char cpfCliente[], int opcao) {
    char dado[50];
    if (opcao == 1) {
        printf("\nNome completo: ");
        scanf("%[^\n]", dado);
    } else if (opcao == 2) {
        printf("\nEmail: ");
        scanf("%[^\n]", dado);
    } else if (opcao == 3) {
        printf("\nData: ");
        scanf("%[^\n]", dado);
    } else if (opcao == 4) {
        printf("\nCelular: ");
        scanf("%[^\n]", dado);
    }

    Cliente * cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));

    FILE * arquivo = fopen("./dados/clientes.bin", "r+b");

    int encontrado = False;
    while (fread(cliente, sizeof(Cliente), 1, arquivo) && encontrado == False) {
        if (strcmp(cpfCliente, cliente->cpf) == 0) {
            if (opcao == 1) {
                strcpy(cliente->nome, dado);
            } else if (opcao == 2) {
                strcpy(cliente->email, dado);
            } else if (opcao == 3) {
                strcpy(cliente->data, dado);
            } else if (opcao == 4) {
                strcpy(cliente->celular, dado);
            }
            
            encontrado = True;
            fseek(arquivo, (-1) * sizeof(Cliente), SEEK_CUR);
            fwrite(cliente, sizeof(Cliente), 1, arquivo);
        }
    }
    fclose(arquivo);
    free(cliente);
}

Cliente* iniciarLista(void) {
    Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));

    FILE *arquivo = fopen("./dados/clientes.bin", "rb");
    fread(cliente, sizeof(Cliente), 1, arquivo);

    return cliente;
}

Cliente* retornaUltimo(void) {
    Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));

    FILE *arquivo = fopen("./dados/clientes.bin", "r+b");
    fseek(arquivo, -sizeof(Cliente), SEEK_END);
    fread(cliente, sizeof(Cliente), 1, arquivo);

    return cliente;
}

void atualizarLista(Cliente* ultimo, Cliente* novo, FILE* arquivo) {
    ultimo->proximo = novo;

    fwrite(ultimo, sizeof(Cliente), 1, arquivo);
}

void deletarCliente(char cpfCliente[]) {
    Cliente * cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));

    FILE * arquivo = fopen("./dados/clientes.bin", "r+b");

    int encontrado = False;
    while (fread(cliente, sizeof(Cliente), 1, arquivo) && encontrado == False) {
        if (strcmp(cliente->cpf, cpfCliente) == 0) {
            cliente->status = False;
            encontrado = True;
            fseek(arquivo, (-1) * sizeof(Cliente), SEEK_CUR);
            fwrite(cliente, sizeof(Cliente), 1, arquivo);
            fclose(arquivo);
        }
    }
    free(cliente);
    fclose(arquivo);
}

void excluirBancoCliente(void) {
    Cliente * cliente;
    cliente = (Cliente *) malloc(sizeof(Cliente));
    
    FILE * arquivo = fopen("./dados/clientes.bin", "rb");
    
    FILE * arquivoTemp = fopen("./dados/clientes_temp.bin", "wb");
    verificaArquivoTemporario(arquivoTemp);

    int clientesMantidos = 0;
    int clientesRemovidos = 0;
    while (fread(cliente, sizeof(Cliente), 1, arquivo) == 1) {
        if (cliente->status == True) {
            fwrite(cliente, sizeof(Cliente), 1, arquivoTemp);
            clientesMantidos++;
        } else {
            clientesRemovidos++;
        }
    }
    
    fclose(arquivo);
    fclose(arquivoTemp);
    free(cliente);
    
    trocaArquivos("./dados/clientes.bin", "./dados/clientes_temp.bin");
    
    printf("Limpeza do banco concluída com sucesso!\n");
    printf("Clientes mantidos: %d\n", clientesMantidos);
    printf("Clientes removidos: %d\n", clientesRemovidos);
}