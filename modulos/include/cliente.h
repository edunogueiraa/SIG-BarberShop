#define True 1
#define False 0

typedef struct cliente Cliente;

struct cliente {
    int status;
    char nome[50];
    char cpf[15];
    char email[50];
    char data[11];
    char celular[10];
    Cliente* proximo;
};

void telaCliente(void);
void cadastroCliente(void);
void exibeCliente(void);
void atualizaCliente(void);
void deletaCliente(void);
void opcaoCliente(void);
char* nomeCliente(char* cpf);

void cadastrarCliente(Cliente *cliente);
void exibirDadosCliente(Cliente *cliente);
int exibirCliente(char *cpfCliente);
void listarClientes(Cliente *lista);
void listarClientesNome(Cliente *lista, char *filtro);
void atualizarCliente(char cpfCliente[], int opcao);
void deletarCliente(char cpfCliente[]);
void excluirBancoCliente(void);
Cliente *gerarListaClientes(void);
Cliente *gerarListaClientesAlfabetica(void);
Cliente *gerarListaClientesAniversario(void);
void limpaListaClientes(Cliente **lista);
int verificaCliente(char *cpfCliente);