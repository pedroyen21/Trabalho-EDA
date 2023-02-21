#include <stdio.h>
#include <stdlib.h>

#define less(A, B) (A.este < B.este)
#define eq(A, B) (A.este == B.este)

typedef unsigned long long ull;

typedef struct {
    ull este;
    ull ant;
    ull prox;
}Item;

// O(n)
void merge(Item *v, int l, int m, int r) {
    Item *v2 = malloc(sizeof(Item) * (r - l + 1));

    int ia = l, ib = m + 1, i = 0;
    while(ia <= m && ib <= r) {
        if(less(v[ib], v[ia]))
            v2[i++] = v[ib++];
        else
            v2[i++] = v[ia++];
    }

    while(ia <= m) 
        v2[i++] = v[ia++];
    
    while(ib <= r)
        v2[i++] = v[ib++];

    i = 0;
    for(int k = l; k <= r; k++)
        v[k] = v2[i++];
    
    free(v2);
}

//O(n lg(n))
void mergesort(Item *v, int l, int r) {
    if(l >= r) return;
    int m = (r - l) / 2 + l;

    mergesort(v, l, m);
    mergesort(v, m + 1, r);
    merge(v, l, m, r);
}

//O(lg(n))
int binarysearch(Item *v, int l, int r, ull x) {
    if (l > r) return -1;
    int m = (r - l) / 2 + l;

    if(x == v[m].este) return m;
    if(x < v[m].este) r = m - 1;
    else l = m + 1;

    return binarysearch(v, l, r, x); 
}

//O(n lg(n))
int verifica_sanidade(Item *v, Item p, Item f, int i) {
    while(1) {
        if(f.ant == p.este && f.este == p.prox) //verificar se o primerio eo ultimo já não sao um loop estão apontando para o outro.
            return 1;
            
        int l = binarysearch(v, 0, i-1, p.prox); // proximo = a este que ele esta procurando

        if(l == -1 || v[l].ant != p.este || p.prox != v[l].este) return 0;
        p = v[l];
    }
    return 1;
}

void imprime(Item *v, int i) {
    for(int j = 0; j < i; j++)
        printf("[%llx, %llx, %llx]\n", v[j].este, v[j].ant, v[j].prox);
    
}
int main(void) {
    Item *v = malloc(sizeof(Item) * 200000);
    int i = 0;

    //O(n)
    while(scanf("%llx %llx %llx", &v[i].este, &v[i].ant, &v[i].prox) == 3)
        i++;

    Item p = v[0]; //input primero
    Item u = v[1]; //input segundo  
    
    //O(n lg(n))
    mergesort(v, 0, i-1);

    printf("Vetor ordenado\n");
    imprime(v, i);
    //O(n lg(n))
    if(verifica_sanidade(v, p, u, i))
        printf("sana\n");
    else    
        printf("insana\n");


}

