#include <stdlib.h>
#include <stdio.h>

#define NOME_ARQUIVO "d"
#define N_INPUTS 1

int main() {
        
    char comando[70];
    sprintf(comando, "gcc -Wall -Wextra -Wpedantic -O2 %s.c -o '%s'", NOME_ARQUIVO, NOME_ARQUIVO);
    system(comando);
    
    for (int i = 1; i <= N_INPUTS; i++) {

        printf("Input:\n");
        sprintf(comando, "cat ./inputs/%d.txt", i);
        system(comando);

        printf("\n\nOutput: \n");
        sprintf(comando, "./%s < ./inputs/%d.txt",NOME_ARQUIVO, i);
        system(comando);
        printf("-----------------------------------\n");
    }
}