#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Item char

typedef struct fila_st{
    Item *v;
    int size;
    int ini, fim, ocupado;
}fila_st;

int inicializa(fila_st *f, int s)
{
    f->v = malloc(sizeof(Item)*s);
    if (f->v == NULL) return 0;
    f->ocupado = 0;
    f->ini = -1;
    f->fim = 0;
    return 1;
}

int enfila(fila_st *f, Item e)
{
    if (f->fim == f->ini) return 0;
    f->v[f->fim++] = e;
    f->fim = f->fim % f->size;
    f->ocupado++;
    return 1;
}

Item espia(fila_st *f)
{
    return f->v[(f->ini+1)%f->size];
}

int esta_vazia(fila_st *f)
{
    return f->ocupado == 0;
}

void desenfila(fila_st *f)
{
    f->ocupado--;
    f->ini = (f->ini+1)%f->size;
}
