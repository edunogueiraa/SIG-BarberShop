#define True 1
#define False 0

typedef struct servico Servico;

struct servico {
    char id[10];
    char nome[50];
    char valor[20];
    char duracao[9];
    int status;
    Servico* proximo;
};

void telaServico(void);
void cadastroServico(void);
void exibeServico(void);
void listagemServico(void);
void atualizaServico(void);
void deletaServico(void);
void limparBancoServico(void); 
void opcaoServicos(void);

char* nomeServico(char* id);
void cadastrarServico(Servico * servico);
int verificaServico(char idServico[]);
void exibirDadosServicos(Servico * servico);
int exibirServico(char idServico[]);
void listarServicos(Servico *lista);
void listarServicosNome(Servico* lista, char* filtro);
void atualizarServico(char idServico[], int opcao);
void deletarServico(char idServico[]);

Servico *gerarListaServicos();
Servico *gerarListaServicosAlfabetica(void);
Servico *gerarListaServicosOrdemPreco(void);
void limpaListaServicos(Servico **lista);