// ideia: 
// - colocar todas as strings em um unico vetor separadas por virgula
// - conto as aparicoes com o strncmp ate achar uma virgula de novo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_V 4294305

void encontra(char *v, char *str, int l) {
    int ap = 0;
    while(*v != '\0') {
        if(*v == ',') {
            printf("%d\n", ap);
            ap = 0;
        }

        if(strncmp(v, str, l) == 0) {
            ap++;
            v += l;
        }
        else 
            v += 1;
    }
}

int main(void) {
    char *v = malloc(MAX_V);

    int tam_v = 0; // tamanho total do vetor
    int tam_p; // tamanho da string a ser concatenada

    while(scanf("%s", v+tam_v) == 1) {
        tam_p = strlen(v+tam_v); // tamanho da string
        tam_v += tam_p; // tamanho da string somado ao tamanho do vetor
        v[tam_v++] = ','; // separa palavras por virgula
    }
    v[tam_v - 1] = '\0'; // termina string com '\0'
    
    char *ultimastr = v+tam_v-tam_p-1;

    encontra(v, ultimastr, tam_p); // (vetor, ultima string, tamanho da string) 
}

