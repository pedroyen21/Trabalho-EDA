#include <stdio.h>
#include <stdlib.h>

#define Item int 

typedef struct no_st {
    Item e; 
    struct no_st *ant, *prox;
} no_st;

typedef struct cabeca_st {
    no_st *inicio;
    no_st *ultimo;
    int tam;
} cabeca_st;

int inicializaLista(cabeca_st *h) {
    h->inicio = NULL;
    h->ultimo = NULL;
    h->tam = 0;
    return 1;
}

int insereInicio(cabeca_st *h, Item e) {
    no_st *novoNo = malloc(sizeof(no_st));
    if(novoNo == NULL) return 0;
    novoNo->e = e;
    novoNo->prox = h->inicio;
    h->inicio = novoNo;
    h->tam++;
    return 1; 
}


Item removeInicio(cabeca_st *h) {
    no_st *toRemove = h->inicio;
    h->inicio = h->inicio->prox;
    Item ret = toRemove->e;
    free(toRemove);
    h->tam--;
    return ret;
}

int empilha(cabeca_st *h, Item e){
    return insereInicio(h,e);
}

Item topo(cabeca_st *h) {
    return h->inicio->e;
}

Item desempilha(cabeca_st *h) {
    return removeInicio(h);
}

int tamanho(cabeca_st *h) {
    return h->tam;
}

int main() {
    
    int teste;
    while(scanf("%d",&teste) && teste != 0)
    {
        int rua = 1;
        int reordenados = 1;
        int caminhoes;
        cabeca_st cab;
        inicializaLista(&cab);
        for(int i = 0; i < teste; i++)
        {
            scanf("%d",&caminhoes);
            if(caminhoes == rua)
            {
                rua++;
            }
            else
            {
                while(tamanho(&cab) > 0 && topo(&cab) == rua)
                {
                    desempilha(&cab);
                    rua++;
                }
                empilha(&cab,caminhoes);
            }
        }
        while(tamanho(&cab)>0)
        {
            if(topo(&cab) != rua)
            {
                reordenados = 0;
                break;
            }
            else
            {
                rua++;
            }
            desempilha(&cab);
            
        }
        if(reordenados == 1) printf("yes\n");
        else printf("no\n");
    }
    return 0;
}
