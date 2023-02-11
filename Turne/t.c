#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define apresentashow {p = f->v[f->inicio];  printf("%s\n", p); u = ultimocaratere(p); desenfila(f); show = 1;} 

typedef char Item[27];

typedef struct {
    Item **v;
    int inicio;
    int fim;
    int tamanho;
}fila;

int estacheia(fila *f) {
    if(f->fim - f->inicio == f->tamanho)
        return 1; 
    else
        return 0;
}
int estavazia(fila *f) {
    if(f->inicio == f->fim)
        return 1; 
    else
        return 0;
}
int enfila(fila *f, Item x) {
    if( !estacheia(f) ) {
        strncpy(f->v[f->fim++], x, 27);
        return 1;
    }
    else printf("Fila cheia\n");
    return 0;
}

void desenfila(fila *f) {
    if( !estavazia(f) ) {
        f->inicio++;
    }
    else printf("Fila vazia\n");
}

int inicializa_fila(fila *f, int t) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = t;
    f->v = malloc(sizeof(Item) * t);
    return 1;
}

void printafila(fila *f) {
    for(int i = f->inicio; i < f->fim; i++) {
        printf("%s\n", f->v[i]);
    }
}


char ultimocaratere(Item v) {
    int i = 0;
    while(v[i+1] != '\0') i++;

    return v[i];
}

void coordena(fila *f) {
    int show = 0;
    char *p; 
    char u;  
    apresentashow;

    int i = f->inicio;
    while(!estavazia(f)) {
        if(show) {
            p = f->v[f->inicio];
            if(tolower(*p) == tolower(u)) {
                desenfila(f);
                enfila(f, p);
                show = 0;
            }
            else {
                apresentashow;
            }
            
        }
        else 
            apresentashow;
        }
        i++;
    }


int main(void) {
    fila f;
    inicializa_fila(&f, 100);

    Item palavra;
    while(scanf("%s", palavra) == 1)
        enfila(&f, palavra);

    coordena(&f);
    
}