struct servico {
    FILE *arquivoServico;
    char nome[50];
    char id[50];
    char valor[50];
    char duracao[50];
};

typedef struct servico Servico;

void telaServicos(void);
void cadastroServicos(void);
void exibeServicos(void);
void atualizarServicos(void);
void deletarServicos(void);
void opcaoServicos(void);