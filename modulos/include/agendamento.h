#define True 1
#define False 0

struct agendamento {
    char id[50];
    char cpfCliente[15];
    char nome[50];
    char idServico[10];
    char data[15];
    char hora[9];
    int status;
};

typedef struct agendamento Agendamento;

void telaAgendamento(void);
void cadastroAgendamento(void);
void listaAgendamento(void);
void exibeAgendamento(void);
void atualizaAgendamento(void);
void deletaAgendamento(void);
void limparBancoAgendamento(void);
void opcaoAgendamento(void);
void listagemAgendamento(void);

void listarAgendamentosData(char* dataBusca);
void exibirDadosAgendamento(Agendamento * agendamento);
void listarAgendamentosNome(char* filtro);
void exibirAgendamento(char idAgendamento[]);
void cadastrarAgendamento(Agendamento * agendamento);
void atualizarAgendamento(char idAgendamento[], int opcao);
void deletarAgendamento(char idAgendamento[]);
