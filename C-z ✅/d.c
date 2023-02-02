#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 1000

typedef char Item[101];

typedef struct {
    Item *v;
    int capacidade;
    int topo;
} pilha_st;


int pilhacheia(pilha_st *p) {
    if(p->topo == p->capacidade)
        return 1;
    else 
        return 0;
}

int pilhavazia(pilha_st *p) {
    if(p->topo == 0)
        return 1;
    else return 0;
}

int inicializa_pilha(pilha_st *p, int t) {
    p->topo = 0;
    p->capacidade = t;
    p->v = malloc(sizeof(Item) * p->capacidade);
    return 0;
}

int empilha(pilha_st *p, Item x) {
    if (!pilhacheia(p)) {
        strcpy(p->v[p->topo++], x);
        return 1;
    }
    else {
        printf("Pilha cheia\n");    
        return 0;
    }
}

void desempilha(pilha_st *p) {
    if(!pilhavazia(p)) 
        printf("%s\n" ,p->v[--p->topo]);
    else {
        printf("NULL\n");
    }
}

int main(void) {
    pilha_st p;
    inicializa_pilha(&p, TAM);

    Item linha;
    char comando[12];
    char ins[12] = "inserir";

    while(scanf("%s", comando) == 1) {
        if(strcmp(comando, ins) == 0) { // se o comando for igual a "inserir"
            scanf(" %[^\n]", linha); // guarda a linha 
            empilha(&p, linha); // empilha a linha
        }
        else {
            desempilha(&p); // desempilha a linha
        }
    }

}

