/* 

URI2222 - PLAYING WITH SETS
https://www.urionlinejudge.com.br/judge/en/problems/view/2222
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char** argv) {
    int instancias;
    scanf("%d", &instancias);
    for(int i=0; i< instancias; i++){
        int numConjuntos;
        scanf("%d", &numConjuntos);
        set<int> conjunto[numConjuntos];
        for(int j=0; j<numConjuntos; j++){
            int elementos;
            scanf("%d", &elementos);
            for(int k=0; k<elementos; k++ ){
                int tmp;
                scanf("%d",&tmp);
                conjunto[j].insert(tmp);
                
            }
            
        }
        int numOperacoes;
        scanf("%d", &numOperacoes);
        for(int l=0; l<numOperacoes; l++){
            int op, c1, c2;
            scanf("%d %d %d",&op, &c1, &c2);
            if(op==1){
                set<int> interc;
                set_intersection(conjunto[c1-1].begin(),conjunto[c1-1].end(), 
                        conjunto[c2-1].begin(), conjunto[c2-1].end(),
                        insert_iterator< set<int> >
                        ( interc, interc.begin() ));
                printf("%ld\n", interc.size());
            }
            else if(op==2){
                set<int> uniao;
                set_union(conjunto[c1-1].begin(),conjunto[c1-1].end(), 
                        conjunto[c2-1].begin(), conjunto[c2-1].end(),
                        insert_iterator< set<int> >
                        ( uniao, uniao.begin() ));
                printf("%ld\n", uniao.size());
                
            }
            
        }
        
    }

    return 0;
}