#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { int t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

int separa(Item *V,int l,int r)
{
  int i=l-1, j=r; Item v=V[r];
  for(;;)
  {
    while(less(V[++i],v));
    while(less(v,V[--j])) if(j==l) break;
    if(i>=j) break;
    exch(V[i],V[j]);
  }
  exch(V[i],V[r])
  return i;
}

void quicksortM3(Item *V,int l, int r)
{
  if (r<=l) return;

  cmpexch(V[(l+r)/2],V[r]);
    cmpexch(V[l],V[(l+r)/2]);
      cmpexch(V[r],V[(l+r)/2]);

  int j=separa(V,l,r);
  quicksortM3(V,l,j-1);
  quicksortM3(V,j+1,r);
}

int main() {

    int placa[101];
    int o, nump;
    int quanti = 0;

    while(scanf("%d %d", &o, &nump) != EOF){
        if(o == 1) {
            if(quanti > 100){
                if(placa[quanti-1] > nump){ // Inserindo um elemento maior que o seu último do vetor.
                    placa[quanti-1] = nump;
                    quicksortM3(placa, 0, quanti-1);
                }
            }
            else{
                placa[quanti] = nump;
                quicksortM3(placa, 0, quanti);
                quanti++;
            }
        }
        if(o == 2){
            for(int i = 0; i < nump; i++){
                if(i == nump-1){
                    printf("%d\n", placa[i]);
                }
                else {
                    printf("%d ", placa[i]);
                }
            }
        }
    }

    return 0;
}