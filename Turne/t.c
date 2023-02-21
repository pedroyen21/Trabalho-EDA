#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define apresentashow {p = f->v[f->inicio];  printf("%s\n", p); u = ultimocaratere(p); desenfila(f); show = 1;} 

typedef char Item[27];

typedef struct {
    Item *v;
    int inicio;
    int fim;
    int tamanho;
}fila;

int estacheia(fila *f) {
    if(f->fim + 1 ==  f->inicio)
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
        strcpy(f->v[f->fim++], x);
        if(f->fim == f->tamanho) f->fim = 0;
        return 1;
    }
    else printf("Fila cheia\n");
    return 0;
}

void desenfila(fila *f) {
    if( !estavazia(f) ) {
        if(++f->inicio == f->tamanho) f->inicio = 0;
    }
    else printf("Fila vazia\n");
}

int inicializa_fila(fila *f, int t) {
    f->inicio = -1;
    f->fim = 0;
    f->tamanho = t;
    f->v = malloc(sizeof(Item) * t);
    return 1;
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

    while(!estavazia(f)) {
        if(show) {
            p = f->v[f->inicio];
            if(tolower(*p) == u) {
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
}


int main(void) {
    fila f;
    inicializa_fila(&f, 10000);

    Item palavra;
    while(scanf("%s", palavra) == 1)
        enfila(&f, palavra);

    coordena(&f);
    
}