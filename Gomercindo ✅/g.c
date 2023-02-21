#include <stdio.h>

typedef struct {  //strucy definida para separar o elementos
    int id;
    int valor;
    int prox;
}pista;

typedef pista Item;

Item busca_prox(Item *v, int x) { // busca sequencial
    int j = 1;
    while(v[j].id != x) // verificando se o elemento do p.prox e diferente no que vc está
        j++;
    return v[j]; // caso seja retorna o valor do elemento para ser printado
}

void ordena_pistas(Item *v, int n) { // Vai fazer a ordenação das pistas
    Item p = v[0];
    for(int i = 1; i <= n; i++) { // imprime primeiro a primeira pista
        printf("%d\n", p.valor);
        if(p.prox == -1) return; // caso seja o último identificador acaba por aqui
        p = busca_prox(v, p.prox); // procura a proxima pista
    }
}

int main(void) {
    int N;
    scanf("%d", &N); // scanf para pegar número de pistas

    Item v[N];
    for(int i = 0; i < N; i++) 
        scanf("%d %d %d", &v[i].id, &v[i].valor, &v[i].prox); // alimenta vetor de pistas

    ordena_pistas(v, N); // chama a função passando o numero de Elementos e o vetor
}