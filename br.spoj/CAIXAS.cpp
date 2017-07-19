/* 

CAIXAS - DESEMPILHANDO CAIXAS
http://br.spoj.com/problems/CAIXAS/
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    while(true){
        int n,p;
        scanf("%d %d", &n, &p);
        if(n==0 && p==0)
            break;
        int pilha[p];
        int indexC1, pilhaC1;
        for(int count=0; count<p; count++){
            int pSize;
            scanf("%d", &pSize);
            pilha[count]=pSize;
            for(int i=0; i<pSize; i++){
                int ci;
                scanf("%d",&ci);
                if(ci==1){
                    indexC1=i+1;
                    pilhaC1=count;
                }
            }
        }
        int acima, direita, esquerda;
        acima=pilha[pilhaC1]-indexC1;
        direita=acima;
        esquerda=acima;
        for(int i=pilhaC1-1; i>=0; i-- ){
            if(pilha[i]>=indexC1)
                esquerda= esquerda+pilha[i]-indexC1+1;
            else
                break;
        }
        for(int i=pilhaC1+1; i<p; i++){
            if(pilha[i]>=indexC1)
                direita= direita+pilha[i]-indexC1+1;
            else
                break;
        }
        
        int resultado=min(esquerda,direita);
        printf("%d\n", resultado);
    }
    return 0;
}
