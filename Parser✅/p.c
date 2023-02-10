#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Item char

typedef struct pilha_st{
    Item *v;
    int topo;
    int size;
}pilha_st;

int inicializa(pilha_st *p, int s){
    p->v=malloc(sizeof(Item)*s);
    if (p->v == NULL)
        return 0;
    p->size = s;
    p->topo = 0;
    return 1;
}

int empilha(pilha_st *p, Item e){
    p->v[p->topo++] = e;
    return 1;
}

int esta_vazia(pilha_st *p){
    return p->topo == 0;
}

Item topo(pilha_st *p){
    return p->v[p->topo-1];
}

void desempilha(pilha_st *p){
    p->topo--;
}


int bemformada(char *s) {

    int i = 0,tam = 0;
    Item m = 0;
    tam = strlen(s);
    pilha_st p;
    inicializa(&p,tam);

    while(s[i] != '\0'){
        if (s[i] == '*' || s[i] == '/' || s[i] == '_')
        {
            empilha(&p,s[i]);
            if (m == s[i])
            {
                
                desempilha(&p);
                desempilha(&p);
                m = topo(&p);
            }
            else{
                m = topo(&p);

            }
        }
        i++;
    }
    return esta_vazia(&p);
}

int main ()
{
    int n = 0, p = 0, i = 0;
    char *s = malloc(10000001);
    char *aux = malloc(100001);
    scanf("%d",&n);
    if (n > 100)
    {
        return 0;
    }
    
    while(i != n)
    {
        getchar();
        scanf("%[^\n]",aux);
        strcat(s,aux);
        i++;
    }
    p = bemformada(s);
    if (p == 1)
    {
        printf("C\n");
    }else{
        printf("E\n");
    }
    return 0;
}