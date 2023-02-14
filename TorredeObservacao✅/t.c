#include <stdio.h>

typedef struct {  //struct da linhas e colunas
    int l;
    int c;
} torre;

typedef struct { // r = conteudo do campo e v = visto
    char r;
    int v;
} campo;

typedef struct { // limite máximo quantidade de linhas e colunas e campo máximo 100 linhas e 100 colunas
    int linhas;
    int colunas;
    campo v[100][100]; // quantidade de elementos
} terreno;

int dentrodolimite(int i, int j, int l, int c) {  // verificar se esta dentro no limite no caso do usuário para 00
    if(i >= 0 && i <= l - 1 && j >= 0  && j <= c - 1) // número de linhas e colunas dentro do campo
        return 1; 
    else 
        return 0;
}

int alcance(terreno *ter, torre t, int alt) {
    int lidos = 0;
    for(int i = t.l - alt; i <= t.l + alt; i++) //identica a quetão do campo por liberar
        for(int j = t.c - alt; j <= t.c + alt; j++){ // Altura 1 = liberar 8 quadrados adjacentes a torre
            if(dentrodolimite(i, j, ter->linhas, ter->colunas) && ter->v[i][j].r != 't' && ter->v[i][j].v == 0) {
                ter->v[i][j].r = '.'; // mudar para . retirando o jogo da velha
                ter->v[i][j].v = 1; // se já foi visto não posso alterar ele
                lidos++; // Já foi lido a torre
            }
        }
    return lidos; // Retorna a quantidade de lidos
}

void imprimeterreno(terreno *ter) { // recebe o terreno altero ele e imprimo ele de volta
    for(int i = 0; i < ter->linhas; i++){
        for(int j = 0; j < ter->colunas; j++)
            printf("%c", ter->v[i][j].r);
        printf("\n");
    }
}
// interar pelas torres
int main(void) {
    int N, M;
    scanf("%d %d\n", &N, &M);

    torre torres[10000]; // 100 * 100 torres em todos os espaçoes 
    int t = 0;

    terreno ter;
    ter.linhas = N;             // seto as linhas e colunas do terreno
    ter.colunas = M;
    
    for(int i = 0; i < N; i++) { // definir e imprimir o campo
        scanf("\n");
        for(int j = 0; j < M; j++) {
            scanf("%c", &ter.v[i][j].r);
            if(ter.v[i][j].r == 't') { // Alimanetando a Matriz, caso seja uma t = torre
                torres[t].l = i; // coloco no vetor de torres
                torres[t].c = j; // colocar na linha e coluna
                t++; // soma o contador de torres
            }
            ter.v[i][j].v = 0; // v de visto no caso começa com 0
        }
    }

    int lidos = 0;
    for(int i = 0; i < t; i++) { // a = altura das torres 
        int a;
        scanf("%d", &a); // define a altura da torre
        lidos += alcance(&ter, torres[i], a); // uma interração para cara torre
    }
        printf("%d\n", lidos);  // quantos quadrados foram lidos
        imprimeterreno(&ter);

}