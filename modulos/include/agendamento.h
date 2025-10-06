struct agendamento {
    FILE * arquivoAgendamento;
    char id[50];
    char cpfCliente[50];
    char nomeCliente[50];
    char idServico[50];
    char data[50];
    char hora[50];
};

typedef struct agendamento Agendamento;

void telaAgendamento(void);
void cadastroAgendamento(void);
void listarAgendamento(void);
void atualizarAgendamento(void);
void deletarAgendamento(void);
void opcaoAgendamento(void);

