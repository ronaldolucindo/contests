/* 

METEORO - METEOROS
http://br.spoj.com/problems/METEORO/
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <cstdio>
#include <ios>

using namespace std;

bool estaDentro(pair<int,int> lim1,pair<int,int> lim2, pair<int,int> p){
    return (p.first >= lim1.first && p.second <= lim1.second 
            && p.first<=lim2.first && p.second >= lim2.second);
}

int main(int argc, char** argv) {
    int teste=0;
    while(true){
        int n,contador=0;
        pair<int,int> p1,p2;
        scanf("%d %d %d %d", &p1.first, &p1.second, &p2.first, &p2.second);
        if(p1.first==0 && p1.second ==0 && p2.first==0 && p2.second==0)
            break;
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            pair<int,int> p;
            scanf("%d %d", &p.first, &p.second);
            if(estaDentro(p1,p2,p))
                contador++;
    }
    teste++;
    printf("Teste %d\n", teste);
    printf("%d\n", contador);
    }
    
    return 0;
}