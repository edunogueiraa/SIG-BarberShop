#define True 1
#define False 0

typedef struct agendamento Agendamento;

struct agendamento {
    char id[50];
    char cpfCliente[15];
    char idServico[10];
    char data[11];
    char hora[9];
    int status;
    Agendamento* proximo;
};

typedef struct agendamento Agendamento;

void telaAgendamento(void);
void cadastroAgendamento(void);
void exibeAgendamento(void);
void listagemAgendamento(void);
void atualizaAgendamento(void);
void deletaAgendamento(void);
void limparBancoAgendamento(void);
void opcaoAgendamento(void);

void cadastrarAgendamento(Agendamento * agendamento);
void exibirDadosAgendamento(Agendamento * agendamento);
int exibirAgendamento(char idAgendamento[]);
void listaAgendamento(Agendamento* lista);
void listarAgendamentosData(Agendamento* lista,char* dataBusca);
void atualizarAgendamento(char idAgendamento[], int opcao);
void deletarAgendamento(char idAgendamento[]);
Agendamento* gerarListaAgendamentos(void);
Agendamento* gerarListaAgendamentosAlfabetica(void);
void limpaListaAgendamentos(Agendamento** lista);

int comparaAgendamentosPorNome(Agendamento* a, Agendamento* b);
int verificaAgendamento(char idAgendamento[]);