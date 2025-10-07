struct estoque {
    int status;
    char nome[50];
    char id[50];
    char tipo[50];
    char valor[50];
};

typedef struct estoque Estoque;

void telaEstoque(void);
void cadastroEstoque(void);
void exibeProduto(void);
void atualizarEstoque(void);
void deletarEstoque(void);
void opcaoEstoque(void);
