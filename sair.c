#include <stdio.h>
#include <stdlib.h>

int sair(void) {
    system("clear||cls");
    int opcaoSair;
    printf("\n");
    printf("____________________________________________\n");
    printf("|                                          |\n");
    printf("|               Deseja sair?               |\n");
    printf("|__________________________________________|\n");
    printf("|                                          |\n");
    printf("|           1 Sim                          |\n");
    printf("|           0 Não                          |\n");
    printf("|__________________________________________|\n\n");


    printf("Digite a opção desejada: ");
    scanf("%d", &opcaoSair);
    getchar();

    return opcaoSair;

}