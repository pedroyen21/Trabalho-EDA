#include <stdlib.h>
#include <stdio.h>

#define NOME_ARQUIVO "g"

int main() {

    for (int i = 1; i <= 1; i++) {
        char comando[50];
        char mostrarInput[50];

        printf("Input:\n");
        sprintf(mostrarInput, "cat ./inputs/%d.txt", i);
        system(mostrarInput);
        
        sprintf(comando, "gcc -Wall -Wextra -Wpedantic -O2 %s.c -o '%s'", NOME_ARQUIVO, NOME_ARQUIVO);
        system(comando);

        printf("\n\nResposta: \n");
        sprintf(comando, "./%s < ./inputs/%d.txt",NOME_ARQUIVO, i);
        system(comando);
        printf("-----------------------------------\n");
    }
}