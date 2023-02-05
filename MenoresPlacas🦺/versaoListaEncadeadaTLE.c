#include <stdio.h>
#include <stdlib.h>

// Minha ideia e colocar os numeros ja na ordem dentro da lista encadeada.
// Sempre que o comando for 2, imprimir os menores
// Insercao linear, tomou time limit exceeded

typedef int Item;

typedef struct reg {
    Item conteudo;
    struct reg *prox;
} celula; // lista encadeada

void apaga_lista(celula *le) {
    if(le == NULL) return;
    apaga_lista(le->prox);
    free(le);
}

int insere_na_ordem(celula *le, int n) {
    celula *p = le;
    celula *q = le->prox;

    celula *nova = malloc(sizeof(celula));
    nova->conteudo = n;
    
    while(q != NULL && q->conteudo < nova->conteudo) {
        p = q;
        q = q->prox;
    }

    nova->prox = q;
    p->prox = nova;
    return 1;
}

void imprime_menores(celula *le, int n){
    celula *p = le->prox;
    
    while(n-- && p) {
        printf("%d ", p->conteudo);
        p = p->prox;
    }
    printf("\n");
}

int main(void) {
    celula *le = malloc(sizeof(celula));
    le->prox = NULL;

    int comando;
    while(scanf("%d", &comando) == 1) {
        int n;
        scanf("%d", &n);
        
        if(comando == 1) {
            insere_na_ordem(le, n);
        }
        else {
            imprime_menores(le, n);
        }
    }
    apaga_lista(le);    
}



