#include <stdio.h>
#include <stdlib.h>

#define NOME_ARQUIVO "s"
#define N_INPUTS 1

int main() {
    char comando[1000];
    #ifdef __linux
    sprintf(comando, "gcc -fno-common -pipe -Werror -Wall -Wextra -Wvla   -Wpacked -Wcast-align -Wenum-compare -Wpointer-arith -Wunused -Wuninitialized -Winit-self -Winvalid-pch -Woverlength-strings -Woverflow -Wsequence-point -Wno-unknown-pragmas -Wtrigraphs -finput-charset=UTF-8 -Wpacked-bitfield-compat -Wlogical-op -Wsync-nand   -Wpointer-arith -O2 %s.c -o '%s'", NOME_ARQUIVO, NOME_ARQUIVO);
    #else// colocar comando que compila
    sprintf(comando, "gcc -Wall -Wextra -Wpedantic -O2 %s.c -o %s", NOME_ARQUIVO, NOME_ARQUIVO);
    #endif
    system(comando);
    
    for (int i = 1; i <= N_INPUTS; i++) {
        printf("Input:\n");

        #ifdef __linux
        sprintf(comando, "cat ./inputs/%d.txt", i);
        #else//colocar comando que poe o input no terminal
        sprintf(comando, "type inputs\\%d.txt", i);
        #endif

        system(comando);

        printf("\n\nOutput: \n");

        #ifdef __linux
        sprintf(comando, "./%s < ./inputs/%d.txt",NOME_ARQUIVO, i);
        #else//colocar comando que roda no windows
        sprintf(comando, "%s.exe < inputs\\%d.txt",NOME_ARQUIVO, i);
        #endif

        system(comando);
        printf("-----------------------------------\n");
    }
}