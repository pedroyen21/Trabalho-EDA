#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 4194305

int encontra(char *m, char *str) {
    int tam = strlen(str);
    printf("[%s,%d]\n", str, tam);
    int ap = 0;
    while(*m != '\0') {
        if(strncmp(m, str, tam) == 0)
            ap++;
        m += 1;
    }
    return ap;
}

int main(void) {
    char **m = malloc(100000);
    int i = -1;
    char *p = malloc(MAX_CHAR);

    while(scanf("%s", p) == 1) {
        m[++i] = p;
        p = malloc(MAX_CHAR);
    }

    char *ultima = m[i];


    for(int j = 0; j < i; j++) {
        printf("%d\n", encontra(m[j], ultima));
    }

    /* for(int j = 0; j < i; j++) {
        printf("%s\n", m[j]);
    } */
}
