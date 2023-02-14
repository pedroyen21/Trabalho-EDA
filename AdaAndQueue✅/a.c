#include <stdio.h>
#include <stdlib.h>

//ideia: inverter os comandos em vez de inverter o vetor

#define exch(A, B) {Item t = A; A = B; B = t;}

int invertida = 0; // invertida começa em 0 por não estar invertida

typedef int Item;

typedef struct { //struct da lista
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
void back(lista *l) {  //Imprima o número de trás e depois apague-o
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
void front(lista *l) { //Imprima o número da frente e depois apague-o
    if(lista_vazia(l)) {
        printf("No job for Ada?\n");
    }
    else {
        printf("%d\n", l->v[l->inicio++]);
        l->tam--;
    }
}
//reverse - Reverses all elements in queue
//O(1)
void reverse() {  //Inverte todos os elementos na fila no caso so os comandos
    invertida = !invertida; 
}

//push_back N - Add element N to back
//O(1)
void push_back(lista *l) {   //Adiciona o elemento N ao fundo
    int x;
    scanf("%d", &x);
    l->v[l->fim++] = x;
    l->tam++;
}

//toFront N - Put element N to front
//O(1)
void toFront(lista *l) { //Coloca o elemento N na frente
    int x;
    scanf("%d", &x);
    l->v[--l->inicio] = x;
    l->tam++;
}

int main(void) {
    int N;
    scanf("%d", &N);

    lista *l = malloc(sizeof(lista)); //inicializa a lista
    l->v = malloc(sizeof(Item) * 2*N);
    l->tam = 0;
    l->inicio = N-1;
    l->fim = N-1;

    while(N--) { // faz um switch case vai decrementando o número de instruções
        char comando[20];
        scanf("%s ", comando);
        //printf("%s\n", comando);
        switch (comando[0]) // Simplificou pegando so a primeira letra do comando já indentifica por serem diferentes.
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
            reverse(l); // pediu para inverter faz o reverse dela
            break;
        case 'p':
            if(invertida)
                toFront(l); //se está invertida no lugas do front vc faz o back
            else
                push_back(l);
            break;

        case 't':
            if(invertida)
                push_back(l); // Se não faz o front mesmo
            else
                toFront(l);
            break;
        
        default:
            break;
        }
        //imprime_lista(l);

    }
}