/* 

DESCULPA - PEDIDO DE DESCULPAS
http://br.spoj.com/problems/DESCULPA
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

void maxItem(int s, int tamanho, int *itemValor, int *itemPeso){
    int M[tamanho+1][s+1];
    for(int i=0; i<=tamanho; i++){
        for(int j=0; j<=s; j++){
            if(i==0 || j==0)
                M[i][j]=0;
            else if(itemPeso[i-1] <= j)
                M[i][j]= max(itemValor[i-1]+M[i-1][j-itemPeso[i-1]], M[i-1][j]);
            else
                M[i][j]=M[i-1][j];
        }
    }
    printf("%d\n", M[tamanho][s]);
}

int main(int argc, char** argv) {
    int instancia=1;
    while(true){
        int c,f;
        scanf("%d %d", &c, &f);
        if(c==0 && f==0)
            break;
        int itemPeso[f+1];
        int itemValor[f+1];
        
        for(int i=0; i<f; i++){
            int n,d;
            scanf("%d %d", &n, &d);
            itemPeso[i]=n;
            itemValor[i]=d;
        }
        printf("Teste %d\n", instancia);
        instancia++;
        maxItem(c,f,itemValor,itemPeso);
        printf("\n");
    }

    return 0;
}


