#include <stdlib.h>
#include <stdio.h>

int main() {
    for (int i = 1; i <= 1; i++) {
        char comando[50];
        char mostrarInput[50];
        printf("Input:\n");
        sprintf(mostrarInput, "cat ./inputs/%d.txt", i);
        system(mostrarInput);
        system("gcc -Wall -Wextra -Wpedantic -O2 d.c -o 'd'");
        printf("\n\nResposta: \n");
        sprintf(comando, "./d < ./inputs/%d.txt", i);
        system(comando);
        printf("-----------------------------------\n");
    }
}