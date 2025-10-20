#define True 1
#define False 0

struct cliente {
    int status;
    char nome[50];
    char cpf[15];
    char email[50];
    char data[11];
    char celular[12];
};

typedef struct cliente Cliente;

void telaCliente(void);
void cadastroCliente(void);
void exibeCliente(void);
void atualizaCliente(void);
void deletaCliente(void);
void opcaoCliente(void);