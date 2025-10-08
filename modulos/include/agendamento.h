#define True 1
#define False 0

struct agendamento {
    char id[50];
    char cpfCliente[50];
    char nomeCliente[50];
    char idServico[50];
    char data[50];
    char hora[50];
    int status;
};

typedef struct agendamento Agendamento;

void telaAgendamento(void);
void cadastroAgendamento(void);
void listarAgendamento(void);
void exibeAgendamento(void);
void atualizarAgendamento(void);
void deletarAgendamento(void);
void opcaoAgendamento(void);

