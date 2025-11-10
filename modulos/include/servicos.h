#define True 1
#define False 0

struct servico {
    char id[10];
    char nome[50];
    char valor[20];
    char duracao[9];
    int status;
};

typedef struct servico Servico;

void telaServico(void);
void cadastroServico(void);
void exibeServico(void);
void atualizaServico(void);
void deletaServico(void);
void limparBancoServico(void); 
void opcaoServicos(void);

void exibirServico(char idServico[]);
void cadastrarServico(Servico * servico);
void atualizarServico(char idServico[], int opcao);
void deletarServico(char idServico[]);