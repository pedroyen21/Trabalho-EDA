#include <stdio.h>
#include <stdlib.h>

#define exch(A, B) {Item t = A; A = B; B = t;}

typedef int Item;

// O(n)
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

// O(lg(n))
void quickselect(Item *v, int l, int r, int n) {
    int med = median(v, l, r); // mediana de 3
    exch(v[med], v[r]);

    int j = partition(v, l, r);
    if(j == n)  return;
    if(j < n) 
        quickselect(v, j + 1, r, n);
    else 
        quickselect(v, l, j - 1, n);
}

// O(n) quando vetor esta quase ordenado ou ordenado
void insertionsort(Item *v, int l, int r) {
    long chave, j;
    for(int i = l+1; i <= r; i++) {
        chave = v[i];
        j = i;
        while(v[j - 1] > chave && j > 0) {
            v[j] = v[j - 1];
            j--;
        } 
        v[j] = chave;
    }
}

void imprime_menores(Item *v, int n, int r) {
    quickselect(v, 0, r, n-1);
    
    insertionsort(v, 0, n-1);

    for(int i = 0; i < n; i++) printf("%d ", v[i]);
    
    printf("\n");
}

int main(void) {
    long  tam = 1000;
    Item *v = malloc(sizeof(Item) * tam);

    int comando, n;
    int i = -1;

    while(scanf("%d", &comando) == 1) {
        scanf("%d", &n);
        
        if(comando == 1) 
            v[++i] = n; // se o comando for 1, adiciona no vetor
        else
            imprime_menores(v, n, i); // se o comando for 2, imprime os n menores elementos

        if(i+1 >= tam) 
            tam *= 2, v = reallocarray(v, tam, sizeof(Item)); // aumenta o tamanho do vetor em 2x
    }

    free(v);   
}