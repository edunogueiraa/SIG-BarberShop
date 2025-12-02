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
void atualizaServico(void);
void deletaServico(void);
void limparBancoServico(void); 
void opcaoServicos(void);
void listaServico(void);
void listagemServico(void);

void exibirDadosServicos(Servico * servico);
void listarServicosNome(Servico* lista, char* filtro);
int exibirServico(char idServico[]);
void cadastrarServico(Servico * servico);
void atualizarServico(char idServico[], int opcao);
void deletarServico(char idServico[]);
char* nomeServico(char* id);