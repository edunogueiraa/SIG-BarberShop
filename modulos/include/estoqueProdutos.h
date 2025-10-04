struct estoque {
    FILE * arquivoEstoque;
    char nome[50];
    char id[50];
    char tipo[50];
    char valor[50];
};

typedef struct estoque Estoque;

void telaEstoque(void);
void cadastroEstoque(Estoque);
void exibeProduto(Estoque);
void atualizarEstoque(void);
void deletarEstoque(void);
void opcaoEstoque(void);
