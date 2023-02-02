#include <stdio.h>
#include <stdlib.h>

#define exch(A, B) {Item t = A; A = B; B = t;}

typedef int Item;

int median(Item *v, int l, int r) {
    int m = (r - l) / 2 + l;
    if ((v[m] <= v[l] && v[l] <= v[r]) || (v[r] <= v[l] && v[l] <= v[m])) return l;
    if ((v[l] <= v[m] && v[m] <= v[r]) || (v[r] <= v[m] && v[m] <= v[l])) return m;
    else return r;
}

//O(n)
int partition(Item *v, int l, int r) {
    Item x = v[r];
    int i = l - 1;
    for(int j = l; j < r; j++) 
        if(v[j] < x) {
            i++;
            exch(v[i], v[j]);
        }
    exch(v[r], v[i + 1]);
    return i + 1;
}

//O(n lg(n))
void quicksort(Item *v, int l, int r) {
    if(l >= r) return;
    int med = median(v, l, r);
    exch(v[med], v[r]);

    int pivot = partition(v, l, r);

    quicksort(v, l, pivot - 1);
    quicksort(v, pivot + 1, r);
}

// O(lg(n))
void quickselect(Item *v, int l, int r, int n) {
    int med = median(v, l, r);
    exch(v[med], v[r]);

    int j = partition(v, l, r);
    if(j == n)  return;
    if(j < n) 
        quickselect(v, j + 1, r, n);
    else 
        quickselect(v, l, j - 1, n);
}

Item *redimensiona(Item *v, long long *N) {
    *N *= 2;
    v = realloc(v, *N * sizeof(Item));
    return v;
}

void imprime_menores(Item *v, int n, int r) {
    quickselect(v, 0, r, n-1);
    
    quicksort(v, 0, n-1);

    for(int i = 0; i < n; i++) printf("%d ", v[i]);
    
    printf("\n");
}

int main(void) {
    long long tamanho = 1000000000;
    Item *v = malloc(sizeof(Item) * tamanho);

    int comando, n;
    long long i = -1;
    while(scanf("%d", &comando) == 1) {
        scanf("%d", &n);
        
        if(comando == 1) 
            v[++i] = n;
        else
            imprime_menores(v, n, i);

        if(i+1 == tamanho) 
            v = redimensiona(v, &tamanho);
    }

    free(v);   
}