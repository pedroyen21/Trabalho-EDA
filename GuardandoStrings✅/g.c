// ideia: 
// - colocar todas as strings em um unico vetor separadas por virgula
// - conto as aparicoes com o strncmp ate achar uma virgula de novo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 4294305

void encontra(char *v, char *str, int l) {
    int ap = 0;
    while(*v != '\0') {   //Conteúdo do endereço do vetor não eh \0 não chegou no fim
        if(*v == ',') {
            printf("%d\n", ap);
            ap = 0;
        }

        if(strncmp(v, str, l) == 0) { // Comparar se tem a ultima string nele o l = tam_p tamanho da string
            ap++;
            v += l;  // somar o tamanho da string para se for igual sem utilizar o strlen
        }
        else 
            v += 1;
    }
}

int main(void) {
    char *v = malloc(MAX_V);

    int tam_v = 0; // tamanho total do vetor
    int tam_p = 0; // tamanho da string a ser concatenada

    while(scanf("%s", v+tam_v) == 1) {
        tam_p = strlen(v+tam_v); // tamanho da string
        tam_v += tam_p; // tamanho da string somado ao tamanho do vetor
        v[tam_v++] = ','; // separa palavras por virgula
    }
    v[tam_v - 1] = '\0'; // termina o vetor de string com '\0' e não com virgula
    
    char *ultimastr = v+tam_v-tam_p-1; //vai direto para a ultima palavra e o - e para pegar o primeiro caractere.

    encontra(v, ultimastr, tam_p); // (vetor, ultima string, tamanho da string)  Não fazer o Strlen
}

