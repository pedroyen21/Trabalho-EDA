#include <stdio.h>

typedef struct {
    int l;
    int c;
} torre;

typedef struct {
    char r;
    int v;
} campo;

typedef struct {
    int linhas;
    int colunas;
    campo v[100][100];
} terreno;

int dentrodolimite(int i, int j, int l, int c) {
    if(i >= 0 && i <= l - 1 && j >= 0  && j <= c - 1) 
        return 1; 
    else 
        return 0;
}

int alcance(terreno *ter, torre t, int alt) {
    int lidos = 0;
    for(int i = t.l - alt; i <= t.l + alt; i++)
        for(int j = t.c - alt; j <= t.c + alt; j++){
            if(dentrodolimite(i, j, ter->linhas, ter->colunas) && ter->v[i][j].r != 't' && ter->v[i][j].v == 0) {
                ter->v[i][j].r = '.';
                ter->v[i][j].v = 1;
                lidos++;
            }
        }
    return lidos;
}

void imprimeterreno(terreno *ter) {
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

    torre torres[10000];
    int t = 0;

    terreno ter;
    ter.linhas = N;
    ter.colunas = M;
    
    for(int i = 0; i < N; i++) {
        scanf("\n");
        for(int j = 0; j < M; j++) {
            scanf("%c", &ter.v[i][j].r);
            if(ter.v[i][j].r == 't') {
                torres[t].l = i;
                torres[t].c = j;
                t++; 
            }
            ter.v[i][j].v = 0;
        }
    }

    int lidos = 0;
    for(int i = 0; i < t; i++) {
        int a;
        scanf("%d", &a);
        lidos += alcance(&ter, torres[i], a);
    }
        printf("%d\n", lidos);
        imprimeterreno(&ter);

    


}