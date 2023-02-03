#include <stdio.h>
#include <stdlib.h>

#define exch(A, B) {Item t = A; A = B; B = t;}

int invertida = 0;

typedef int Item;

typedef struct {
    Item *v;
    int inicio;
    int fim;
    int tam;
} lista;
//O(1)
int lista_vazia(lista *l) {
    return l->tam == 0;
}

//back - Print number from back and then erase it
//O(1)
void back(lista *l) {
    if(lista_vazia(l)) {
        printf("No job for Ada?\n");
    }
    else {
        printf("%d\n", l->v[--l->fim]);
        l->tam--;
    }
}
//front - Print number from front and then erase it
//O(1)
void front(lista *l) {
    if(lista_vazia(l)) {
        printf("No job for Ada?\n");
    }
    else {
        printf("%d\n", l->v[l->inicio++]);
        l->tam--;
    }
}
//reverse - Reverses all elements in queue
//O(n)
void reverse() {
    invertida = !invertida;
}

//push_back N - Add element N to back
//O(1)
void push_back(lista *l) {
    int x;
    scanf("%d", &x);
    l->v[l->fim++] = x;
    l->tam++;
}

//toFront N - Put element N to front
//O(1)
void toFront(lista *l) {
    int x;
    scanf("%d", &x);
    l->v[--l->inicio] = x;
    l->tam++;
}

void imprime_lista(lista *l) {
    for(int i = l->inicio; i < l->fim; i++)
        printf("[%d, %d] ",i, l->v[i]);
    printf("\n");
}

int main(void) {
    int N;
    scanf("%d", &N);

    lista *l = malloc(sizeof(lista));
    l->v = malloc(sizeof(Item) * 2*N);
    l->tam = 0;
    l->inicio = N-1;
    l->fim = N-1;

    while(N--) {
        char comando[20];
        scanf("%s ", comando);
        //printf("%s\n", comando);
        switch (comando[0])
        {
        case 'b':
            if(invertida)
                front(l);
            else
                back(l);
            break;
        case 'f':
            if(invertida) 
                back(l);
            else 
                front(l);
            break;
        case 'r':
            reverse(l);
            break;
        case 'p':
            if(invertida)
                toFront(l);
            else
                push_back(l);
            break;

        case 't':
            if(invertida)
                push_back(l);
            else
                toFront(l);
            break;
        
        default:
            break;
        }
        //imprime_lista(l);

    }
}