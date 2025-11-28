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
void atualizarEstoque(void);
void deletarEstoque(void);
void opcaoEstoque(void);
