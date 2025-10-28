#define True 1
#define False 0

int validaEmail(char *email);
int validaNome(char *nome);
int validaCelular(char *celular);
void recebeNome(char ponteiroNome[], char tipo[]);
void recebeCpf(char ponteiroCpf[]);
void recebeId(char ponteiroId[], char tipo[]);
void recebeEmail(char ponteiroEmail[]);
void recebeData(char ponteiroData[], char tipo[]);
void recebeCelular(char ponteiroCelular[]);
void recebeTipo(char ponteiroTipo[]);
void recebeValor(char ponteiroValor[]);
void recebeDuracaoTempo(char ponteiroDuracao[]); 
void recebeHora(char ponteiroHora[]);
void recebeOpcao(char ponteiroOpcao[]);

void verificaArquivo(FILE * arquivo);
void verificaArquivoTemporario(FILE * arquivoTemp);
void trocaArquivos(char antigo[], char novo[]);
void criarDiretorio(void);