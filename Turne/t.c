#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef char Item[27];

#define imprimeedesenfila { printf("%s\n", espia(f)); desenfila(f);}

typedef struct fila_st{
    Item *v;
    int size;
    int ini, fim, ocupado;
}fila_st;

int inicializa(fila_st *f, int s)
{
    f->v = malloc(sizeof(Item) * s);
    if (f->v == NULL) return 0;
    f->ocupado = 0;
    f->ini = -1;
    f->fim = 0;
    f->size = s;
    return 1;
}

int enfila(fila_st *f, Item e)
{
    if (f->fim == f->ini) return 0;
    strcpy(f->v[f->fim++], e);
    f->fim = f->fim % f->size;
    f->ocupado++;
    return 1;
}

Item *espia(fila_st *f)
{
    return &f->v[(f->ini+1)%f->size];
}

int esta_vazia(fila_st *f)
{
    return f->ocupado == 0;
}

void desenfila(fila_st *f)
{
    f->ocupado--;
    f->ini = (f->ini+1) % f->size;
}


char ultimocaratere(Item *v) {
    while(*(v+1) != 0)
        v++;
    return *v[0];
} 

void coordena(fila_st *f) {
    int show = 0;
    char u = ultimocaratere(f->v);
    imprimeedesenfila;

    for(int i = f->ini + 1; i < f->fim; i++) {
        if(show) {
            u = ultimocaratere(f->v[i]);
            printf("-----%s\n", f->v[i]);
            imprimeedesenfila;
            show = 0;
        }
        else {
            if(f->v[0][0] == u) {
                Item *p = espia(f);
                u = ultimocaratere(p);
                imprimeedesenfila;
                enfila(f, p);
                show = 1;
            }

        }
    }
}

int main(void) {
    fila_st f;
    inicializa(&f, 100000);

    Item palavra;
    while(scanf("%27s", palavra) == 1)
        enfila(&f, palavra);
    
    coordena(&f);
    
}