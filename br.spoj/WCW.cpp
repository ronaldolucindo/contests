/* 

WCW - ELEMENTAR, MEU CARO WATSON!
http://br.spoj.com/problems/WCW/
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    int instancias;
    scanf("%d", &instancias);
    for(int i=0; i<instancias; i++){
        int n;
        scanf("%d",&n);
        int sequencia[n+1];
        sequencia[0]=0;
        for(int j=1; j<=n; j++){
            int aux;
            scanf("%d",&aux);
            sequencia[j]=aux;
        }
        int trocas=0;
        for(int j=1; j<=n; j++){
            if(sequencia[j]!=j){
                swap(sequencia[j],sequencia[sequencia[j]]);
                j--;
                trocas++;
            }     
        }
        printf("%d\n", trocas);
    }
    return 0;
}