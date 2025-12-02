#define True 1
#define False 0

typedef struct estoque Estoque;

struct estoque {
    char id[50];
    int status;
    char nome[50];
    char tipo[20];
    char valor[20];
    Estoque* proximo;
};

void telaEstoque(void);
void cadastroEstoque(void);
void exibeProduto(void);
void listaEstoque(void);
void atualizaProduto(void);
void deletaProduto(void);
void limparBancoEstoque(void);
void opcaoEstoque(void);

void cadastrarProduto(Estoque *estoque);
int exibirProduto(char idProduto[]);
void exibirDadosProduto(Estoque* estoque);
void listarProdutos(Estoque *lista);
void listarProdutosPreco(Estoque *lista, float minimo, float maximo);
void atualizarProduto(char idProduto[], int opcao);
void deletarProduto(char idProduto[]);
void excluirBancoEstoque(void);
Estoque *gerarListaEstoque(void);
Estoque *gerarListaOrdemPreco(void);

void liberarListaEstoque(Estoque **lista);
int verificaEstoque(char *idProduto);