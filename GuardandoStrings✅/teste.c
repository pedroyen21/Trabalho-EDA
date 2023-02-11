#include <stdio.h>
#include <stdlib.h>

#define NOME_ARQUIVO "g"
#define N_INPUTS 5

int main() {
    char comando[70];
    #ifdef __linux
    sprintf(comando, "gcc -Wall -Wextra -Wpedantic -O2 %s.c -o '%s'", NOME_ARQUIVO, NOME_ARQUIVO);
    #else// colocar comando que compila
    sprintf(comando, "gcc -Wall -Wextra -Wpedantic -O2 %s.c -o '%s'", NOME_ARQUIVO, NOME_ARQUIVO);
    #endif
    system(comando);
    
    for (int i = 1; i <= N_INPUTS; i++) {
        printf("Input:\n");

        #ifdef __linux
        sprintf(comando, "cat ./inputs/%d.txt", i);
        #else//colocar comando que poe o input no terminal
        sprintf(comando, "type ./inputs/%d.txt", i);
        #endif

        system(comando);

        printf("\n\nOutput: \n");

        #ifdef __linux
        sprintf(comando, "./%s < ./inputs/%d.txt",NOME_ARQUIVO, i);
        #else//colocar comando que roda no windows
        sprintf(comando, "./%s < ./inputs/%d.txt",NOME_ARQUIVO, i);
        #endif

        system(comando);
        printf("-----------------------------------\n");
    }
}