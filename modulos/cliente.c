#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include "include/cliente.h"
#include "include/utils.h"

// Assinatura de funções
void cadastrarCliente(Cliente * cliente);
void exibirDadosCliente(Cliente* cliente);
void exibirCliente(char cpfCliente[]);
void listarClientes(Cliente* lista);
void listarClientesNome(Cliente* lista, char* filtro);
void atualizarCliente(char cpfCliente[], int opcao);
void deletarCliente(char cpfCliente[]);
void excluirBancoCliente(void);
Cliente* gerarLista(void);
Cliente* gerarListaAlfabetica(void);
Cliente* gerarListaAniversario(void);
void limpaLista(Cliente** lista);

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
    recebeData(cliente->data,"nascimento");
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
    char opcao = '0';
    Cliente* lista;
    do {
        system("clear||cls");
        printf("\n");
        printf("|_________________________________________________________________________________________________|\n");
        printf("|                                                                                                 |\n");
        printf("|                                     ESCOLHA O TIPO DE LISTAGEM                                  |\n");
        printf("|_________________________________________________________________________________________________|\n");
        printf("|                                                                                                 |\n");
        printf("|                                   1 Ordem alfabética                                            |\n");
        printf("|                                   2 Ordem de recentes                                           |\n");
        printf("|                                   3 Data de nascimento                                          |\n");
        printf("|                                   4 Filtrar nome                                                |\n");
        printf("|                                   0 Sair                                                        |\n");
        printf("|_________________________________________________________________________________________________|\n\n");
        
        char filtro[50];
        opcao = recebeOpcao();
        switch (opcao) {
            case '1':
                lista = gerarListaAlfabetica();
                listarClientes(lista);
                break;

            case '2':
                lista = gerarLista();
                listarClientes(lista);
                break;

            case '3':
                lista = gerarListaAniversario();
                listarClientes(lista);
                break;

            case '4':
                lista = gerarLista();
                printf("Digite o nome pelo qual buscar: ");
                scanf("%[^\n]", filtro);
                getchar();
                listarClientesNome(lista, filtro);
                break;

            case '0':
                break;

            default:
                printf("\n>>> Opção inválida.");
                printf("\n>>> Tecle <ENTER> para continuar...\n");
                getchar();
        }
    } while (opcao != '0');

    limpaLista(&lista);
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
        printf("\n1 - Nome");
        printf("\n2 - Email");
        printf("\n3 - Data de nascimento");
        printf("\n4 - Celular");
        printf("\n0 - Finalizar operação\n\n");
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
        opcao = recebeOpcao();
        
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

char* nomeCliente(char* cpf) {
    Cliente * cliente;
    cliente = (Cliente*) malloc(sizeof(Cliente));

    char* nome = (char*) malloc(50);
    FILE * arquivo = fopen("./dados/clientes.bin", "rb");
    verificaArquivo(arquivo);

    while (fread(cliente, sizeof(Cliente), 1, arquivo)) {
        if(strcmp(cliente->cpf, cpf) == 0 && cliente->status == True) {
            strcpy(nome, cliente->nome);
            free(cliente);
            fclose(arquivo);
            return nome;
        }
    }

    return NULL;
}
void cadastrarCliente(Cliente * cliente) {
    criaDiretorio();
    FILE * arquivo = fopen("./dados/clientes.bin", "ab");
    verificaArquivo(arquivo);
    
    cliente->status = True;
    fwrite(cliente, sizeof(Cliente), 1, arquivo);
    
    fclose(arquivo);
}
void exibirDadosCliente(Cliente* cliente) {
    char* cpf = formataCpf(cliente->cpf);
    char* celular = formataCelular(cliente->celular);

    printf("%-35s | \t%-18s | %-35s | \t%-14s | %-12s\n",
        cliente->nome,
        cpf,
        cliente->email,
        cliente->data,
        celular);

    free(cpf);
    free(celular);
}
void exibirCliente(char* cpfCliente) {
    Cliente * cliente = (Cliente*) malloc(sizeof(Cliente));

    FILE * arquivo = fopen("./dados/clientes.bin", "rb");
    verificaArquivo(arquivo);

    int encontrado = False;
    while (fread(cliente, sizeof(Cliente), 1, arquivo) && encontrado == False) {
        if(strcmp(cliente->cpf, cpfCliente) == 0 && cliente->status == True) {
            char* cpf = formataCpf(cliente->cpf);
            char* celular = formataCelular(cliente->celular);

            printf("\n\t\t\t <--- Cliente Encontrado ---> \n\n");
            printf("\t\t\tNome: %s\n", cliente->nome);
            printf("\t\t\tCPF: %s\n", cpf);
            printf("\t\t\tEmail: %s\n", cliente->email);
            printf("\t\t\tData: %s\n", cliente->data);
            printf("\t\t\tCelular: %s\n", celular);

            free(cpf);
            free(celular);
            encontrado = True;
        }
    }
    fclose(arquivo);
    free(cliente);

    if (encontrado == False) {
        printf("\n\t\t\t <--- Cliente não encontrado ---> \n\n");
    }
}
void listarClientes(Cliente* lista) {
    Cliente* cliente = lista;
    
    printf("\n\t\t\t\t\t\t <--- Lista de clientes ---> \n\n");
    printf("%-35s | %-20s | %-35s | %-14s  | %-12s\n", "Nome", "CPF", "Email", "Data de nascimento", "Celular");
    printf("---------------------------------------------------------------------------------------------------------------------------------------\n");
    while (cliente != NULL) {
        exibirDadosCliente(cliente);
        cliente = cliente->proximo;
    }
    free(cliente);

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
void listarClientesNome(Cliente* lista, char* filtro) {
    Cliente* cliente = lista;
    printf("\n\t\t\t\t\t <--- Lista de clientes filtrada por nome---> \n\n");
    printf("\n%-35s | %-20s | %-35s | %-14s  | %-12s\n", "Nome", "CPF", "Email", "Data de nascimento", "Celular");
    printf("---------------------------------------------------------------------------------------------------------------------------------------\n");
    while (cliente != NULL) {
        char* filtrado = strstr(cliente->nome, filtro);
        if (filtrado != NULL) {
            exibirDadosCliente(cliente);
        }
        cliente = cliente->proximo;
    }
    free(cliente);

    printf("\n>>> Tecle <ENTER> para continuar...\n");
    getchar();
}
void atualizarCliente(char cpfCliente[], int opcao) {
    char dado[50];
    if (opcao == 1) {
        recebeNome(dado, "cliente");
    } else if (opcao == 2) {
        recebeEmail(dado);
    } else if (opcao == 3) {
        recebeData(dado, "nascimento");
    } else if (opcao == 4) {
        recebeCelular(dado);
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
Cliente* gerarLista(void) {
    Cliente* lista = NULL;
    Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));
    
    FILE *arquivo = fopen("./dados/clientes.bin", "rb");
    verificaArquivo(arquivo);

    while (fread(cliente, sizeof(Cliente), 1, arquivo)) {
        if (cliente->status == True) {
            cliente->proximo = lista;
            lista = cliente;
            cliente = (Cliente*) malloc(sizeof(Cliente));
        }
    }
    fclose(arquivo);

    return lista;
}
Cliente* gerarListaAlfabetica(void) {
    Cliente* lista = NULL;
    Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));
    
    FILE *arquivo = fopen("./dados/clientes.bin", "rb");
    verificaArquivo(arquivo);

    while (fread(cliente, sizeof(Cliente), 1, arquivo)) {
        if (cliente->status == True) {
            if (lista == NULL) {
                lista = cliente;
                cliente->proximo = NULL;
            } else if (comparaNomes(cliente->nome, lista->nome) < 0) {
                cliente->proximo = lista;
                lista = cliente;
            } else {
                Cliente* anterior = lista;
                Cliente* atual = lista->proximo;

                while ((atual != NULL) && comparaNomes(atual->nome, cliente->nome) < 0) {
                    anterior = atual;
                    atual = atual->proximo;
                }
                anterior->proximo = cliente;
                cliente->proximo = atual;
            }
            cliente = (Cliente *)malloc(sizeof(Cliente));
        }
    }
    fclose(arquivo);

    return lista;  
}
Cliente* gerarListaAniversario(void) {
    Cliente* lista = NULL;
    Cliente* cliente = (Cliente*) malloc(sizeof(Cliente));
    
    FILE *arquivo = fopen("./dados/clientes.bin", "rb");
    verificaArquivo(arquivo);

    while (fread(cliente, sizeof(Cliente), 1, arquivo)) {
        if (cliente->status == True) {
            if (lista == NULL) {
                lista = cliente;
                cliente->proximo = NULL;
            } else if (comparaDatas(cliente->data, lista->data) < 0) {
                cliente->proximo = lista;
                lista = cliente;
            } else {
                Cliente* anterior = lista;
                Cliente* atual = lista->proximo;

                while ((atual != NULL) && comparaDatas(atual->data, cliente->data) < 0) {
                    anterior = atual;
                    atual = atual->proximo;
                }
                anterior->proximo = cliente;
                cliente->proximo = atual;
            }
            cliente = (Cliente *)malloc(sizeof(Cliente));
        }
    }
    fclose(arquivo);

    return lista;  
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
void limpaLista(Cliente** lista) {
    Cliente* cliente;

    while (*lista != NULL) {
        cliente = *lista;
        *lista = (*lista)->proximo;
        free(cliente);
    }

    *lista = NULL;
}