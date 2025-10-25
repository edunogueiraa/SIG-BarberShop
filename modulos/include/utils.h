#define True 1
#define False 0

void recebeNome(char ponteiroNome[], char tipo[]);
void recebeValor(char ponteiroValor[]);
void recebeDuracaoTempo(char ponteiroDuracao[]); 
void recebeCpf(char ponteiroCpf[]);
void recebeEmail(char ponteiroEmail[]);
void recebeData(char ponteiroData[], char tipo[]);
void recebeCelular(char ponteiroCelular[]);
void recebeId(char ponteiroId[], char tipo[]);
void recebeOpcao(char ponteiroOpcao[]);
void recebeHora(char ponteiroHora[]);

void verificaArquivo(FILE * arquivo);
void trocaArquivos(char antigo[], char novo[]);
void verificaArquivoTemporario(FILE * arquivoTemp);
void criarDiretorio(void);


