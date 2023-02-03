#include <stdio.h>

typedef struct {
    int id;
    int valor;
    int prox;
}pista;

typedef pista Item;

Item busca_prox(Item *v, int x) {
    int j = 1;
    while(v[j].id != x) 
        j++;
    return v[j];
}

void ordena_pistas(Item *v, int n) {
    Item p = v[0];
    for(int i = 1; i <= n; i++) {
        printf("%d\n", p.valor);
        if(p.prox == -1) return;
        p = busca_prox(v, p.prox); // procura a proxima pista
    }
}

int main(void) {
    int N;
    scanf("%d", &N);

    Item v[N];
    for(int i = 0; i < N; i++) 
        scanf("%d %d %d", &v[i].id, &v[i].valor, &v[i].prox); // alimenta vetor de pistas

    ordena_pistas(v, N);
}