#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct reg{
    Item e;
    struct reg *prox;
} no;

typedef struct {
    int tam;
    no *inicio;
} fila;

int lista_vazia(fila *f) {
    return f->tam == 0;
}

//printa o numero de tras e o apaga
void back(fila *f) {
    if(lista_vazia(f)) {
        printf("No job for Ada?\n");
        return;
    }
    no *p, *q;
    p = f->inicio;

    if(f->tam == 1) {
        printf("%d\n", p->e);
        f->inicio = NULL;
        f->tam--;
        free(p);
        return;
    }
    
    q = p->prox;
    while(q->prox) { 
        p = q;
        q = q->prox;
    }

    printf("%d\n", q->e);
    free(q);
    p->prox = NULL;
    f->tam--;
}

//printa numero da frente e o apaga
void front(fila *f) {
    if(lista_vazia(f)) {
        printf("No job for Ada?\n");
        return;
    }
    no *p = f->inicio;
    f->inicio = p->prox;
    printf("%d\n", p->e);
    free(p);
    f->tam--;
}

//reverte fila
no *reverse(no *a, no *b) {
    if(!b) {
        return a;
    }
    no *c = b->prox;
    b->prox = a;
    return reverse(b, c);
}

//adiciona elemento atras
void push_back(fila *f) {
    no *p = f->inicio;
    no *nova = malloc(sizeof(no));
    if(!nova) {
        printf("Erro na alocacao de memoria push_back\n");
        return;
    };
    scanf("%d", &nova->e);

    while(p->prox) 
        p = p->prox;
    p->prox = nova;
    nova->prox = NULL;
    f->tam++;
}
//adiciona elemento na frente
void toFront(fila *f) {
    no *nova = malloc(sizeof(no));
    if(!nova) {
        printf("Erro alocacao de memoria toFront\n");
        return;
    }
    scanf("%d", &nova->e);
    if(lista_vazia(f)) {
        nova->prox = NULL;
        f->inicio = nova;
    }
    else {
        nova->prox = f->inicio->prox;
        f->inicio = nova;
    }
    f->tam++;
}

void imprime_lista(fila *f) {
    no *p = f->inicio;
    for(int i = 0; i < f->tam; i++) {
        printf("[%d, %d] ", i,p->e);
        p = p->prox;
    }
    printf("\n");
}

int main(void) {
    int N;
    scanf("%d", &N);

    fila *f = malloc(sizeof(fila));
    f->tam = 0;
    f->inicio = NULL;

    while(N--) {
        char comando[20];
        scanf("%s ", comando);
        //printf("%s\n", comando);
        switch (comando[0])
        {
        case 'b':
            back(f);
            break;
        case 'f':
            front(f);
            break;
        case 'r':
            if(f->tam > 1) 
                f->inicio = reverse(f->inicio, f->inicio->prox);
            break;
        case 'p':
            push_back(f);
            break;

        case 't':
            toFront(f);
            break;
        
        default:
            break;
        }
           // imprime_lista(f);

    }
}