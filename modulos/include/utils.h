#define True 1
#define False 0

// Funções de validação
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
char recebeOpcao(void);

// Funções de comparação
int comparaNomes(char* primeiro, char* segundo);
int comparaDatas(char* primeira, char* segunda);

// Funções de tratamento
char* paraMaiusculo(char* palavra);
char* formataCpf(char *cpf);
char* formataCelular(char *celular);

// Funções de verificação de arquivos
void verificaArquivo(FILE * arquivo);
void verificaArquivoTemporario(FILE * arquivoTemp);
void trocaArquivos(char antigo[], char novo[]);
void criarDiretorio(void);
int verificaItensArquivo(FILE *arquivo, int tamanho);
int atribuirId(const char *nomeArquivo, int tamanhoRegistro);