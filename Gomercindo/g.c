#include <stdio.h>

typedef struct {
    int id;
    int valor;
    int prox;
}pista;

typedef pista Item;

int busca(int x, Item *v) {
    int j = 1;
    while(v[j].id != x && x != -1) 
        j++;
    return v[j];
}

void poe_em_ordem(Item *v, int *p, int n) {
    p[0] = v[0].valor;
    int prox = v[0].prox;

    for(int i = 1; i < n; i++) {
        Item k = busca(v, prox);
        p[i] = v[j].valor;
        prox = v[j].prox;
    }
}

int main(void) {
    int N;
    scanf("%d", &N);

    Item v[N];
    for(int i = 0; i < N; i++) 
        scanf("%d %d %d", &v[i].id, &v[i].valor, &v[i].prox);

    int po[N];
    poe_em_ordem(v, po, N);

    for(int i = 0; i < N; i++) {  
        printf("%d\n", po[i]);
    }
}