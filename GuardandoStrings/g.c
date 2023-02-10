#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 4194305

void encontra(char *v, char *str) {
    int ap = 0;
    int l = strlen(str);
    while(*v != '\0') {
        if(*v == ' ') {
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
    char *v = malloc(MAX_CHAR);
    char *aux = malloc(MAX_CHAR);

    while(scanf("%s", aux) == 1) {
        strcat(v, aux);
        strcat(v, " ");
    }
    v[strlen(v) -1] = '\0';
    //printf("ultima->%s\n", aux);
    //printf("v-> %s", v);
    
    encontra(v, aux);
}

