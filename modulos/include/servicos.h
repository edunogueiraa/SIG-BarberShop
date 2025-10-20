#define True 1
#define False 0

struct servico {
    char nome[50];
    char id[50];
    char valor[50];
    char duracao[50];
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