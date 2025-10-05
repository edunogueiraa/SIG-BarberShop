struct cliente {
    FILE * arquivo;
    char nome[50];
    char cpf[50];
    char email[50];
    char data[50];
    char celular[50];
};

typedef struct cliente Cliente;

void telaCliente(void);
void cadastroCliente(void);
void exibeCliente(void);
void atualizaCliente(void);
void deletaCliente(void);
void opcaoCliente(void);