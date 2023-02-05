#include <stdio.h>
#include <stdlib.h>
// ideia: merge sort

#define less(A, B) (A.este < B.este)
#define eq(A, B) (A.este == B.este)


typedef unsigned long long ull;

typedef struct {
    ull este;
    ull ant;
    ull prox;
}Item;

Item *redimensiona(Item *v, long *m) {
    *m *= 2;
    v = realloc(v, *m);
    return v;
}

// O(n)
void merge(Item *v, ull l, ull m, ull r) {
    Item *v2 = malloc(sizeof(Item) * (r - l + 1));

    ull ia = l, ib = m + 1, i = 0;
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
    for(ull k = l; k <= r; k++)
        v[k] = v2[i++];
    
    free(v2);
}

//O(n lg(n))
void mergesort(Item *v, ull l, ull r) {
    if(l >= r) return;
    ull m = (r - l) / 2 + l;

    mergesort(v, l, m);
    mergesort(v, m + 1, r);
    merge(v, l, m, r);
}

//O(lg(n))
int binarysearch(Item *v, ull l, ull r, ull x) {
    if (l > r) return -1;
    ull m = (r - l) / 2 + l;

    if(x == v[m].este) return m;
    if(x < v[m].este) r = m - 1;
    else l = m + 1;

    return binarysearch(v, l, r, x); 
}

//O(n)
int verifica_sanidade(Item *v, ull i) {
    ull k = 0;
    Item p = v[0];
    while(k <= i && p.prox != 0) {
        printf("i: %lld k: %lld \n", i, k );
        ull l = binarysearch(v, 1, i-1, p.prox);
        Item pos =  v[l];
        printf("[%lld, %lld, %lld]\n",l, p.este, pos.ant);
        if(pos.ant != p.este) return 0;
        p = pos;
        k++;
    }
    return 1;
}

void imprime(Item *v, int n) {
    for(int i = 0; i < n; i++)
        printf("[%lld, %lld, %lld]\n", v[i].este, v[i].ant, v[i].prox);
}

int main(void) {
    ull max = 10;
    Item *v = malloc(sizeof(Item) * max);

    int i = 0;

    while(scanf("%llx %llx %llx", &v[i].este, &v[i].ant, &v[i].prox) == 3)
        i++;

    imprime(v, i);

    printf("----------------\n");
    mergesort(v, 1, i-1);

    imprime(v, i);
    if(verifica_sanidade(v, i))
        printf("sana\n");
    else    
        printf("insana\n");

}

