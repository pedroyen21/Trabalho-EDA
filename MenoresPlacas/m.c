#include <stdio.h>
#include <stdlib.h>

// Minha ideia e colocar os numeros ja na ordem dentro da lista encadeada.
// Sempre que o comando for 2, imprimir os menores e apagar a lista

typedef int Item;

typedef struct {
    Item conteudo;
    struct celula *prox;
} celula; // lista encadeada

int apaga_lista(){};

int insere_na_ordem(){

};

void imprime_menores(int n){}

int main(void) {

    celula *le = malloc(sizeof(celula));
    le->prox = NULL;

    int comando;
    while(scanf("%d", &comando) == 1) {
        int n;
        scanf("%d", &n);
        
        if(comando == 1) {
            insere_na_ordem(le, n);
        }
        else {
            imprime_menores(le, n);
            apaga_lista(le);    
        }
    }
}



