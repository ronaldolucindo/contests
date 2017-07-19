/* 

KNAPSACK - The Knapsack Problem
http://www.spoj.com/problems/KNAPSACK/
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
    int s, n;
    scanf("%d %d", &s, &n);
    int itemPeso[n+1];
    int itemValor[n+1];
    for(int i=0; i<n; i++){
        int p, v;
        scanf("%d %d", &p, &v);
        itemPeso[i]=p;
        itemValor[i]=v;
    }
    maxItem(s,n, itemValor, itemPeso);
    return 0;
}

    