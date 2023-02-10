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
    //printf("Entrou na funcao\n");
    //printf("%s\n",s);
    tam = strlen(s);
    pilha_st p;
    inicializa(&p,tam);

    while(s[i] != '\0'){
        if (s[i] == '*' || s[i] == '/' || s[i] == '_')
        {
            empilha(&p,s[i]);
            if (m == s[i])
            {
                //printf("Entrou no if com M = %c\n", m);
                desempilha(&p);
                desempilha(&p);
                m = topo(&p);
                //printf("Valor do topo2 com M = %c\n", m);
            }
            else{
                m = topo(&p);
                //printf("Valor do M na saida do Topo = %c\n", m);

            }
        }
        i++;
    }
    return esta_vazia(&p);
}

int main ()
{
    int n = 0, p = 0, i = 0;
    char s[100000];
    char aux[100000] = {};
    scanf("%d",&n);
    while(i != n)
    {
        getchar();
        scanf("%[^\n]",s);
        strcat(aux,s);
        i++;
    }
    p = bemformada(aux);
    if (p == 1)
    {
        printf("C\n");
    }else{
        printf("E\n");
    }
    return 0;
}