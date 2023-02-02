#include <stdio.h>

typedef struct {
    int id;
    int valor;
    int prox;
}pista;

typedef pista Item;

Item busca(Item *v, int x) {
    int j = 1;
    while(v[j].id != x && x != -1) 
        j++;
    return v[j];
}

void poe_em_ordem(Item *v, int n) {
    Item p = v[0];
    for(int i = 1; i <= n; i++) {
        printf("%d\n", p.valor);
        p = busca(v, p.prox); // procura a proxima pista
    }
}

int main(void) {
    int N;
    scanf("%d", &N);

    Item v[N];
    for(int i = 0; i < N; i++) 
        scanf("%d %d %d", &v[i].id, &v[i].valor, &v[i].prox); // alimenta vetor de pistas

    poe_em_ordem(v, N);
}