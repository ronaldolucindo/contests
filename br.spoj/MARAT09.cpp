/* 

MARAT09 - MARATONA
http://br.spoj.com/problems/MARAT09/
RONALDO MEDEIROS LUCINDO

*/
#include <cstdlib>
#include <cstdio>
#define DIST_TOTAL 42195

using namespace std;

bool verificaDistancias(int* p, int size, int d){
    for(int i=1; i< size; i++){
        int res= p[i]-p[i-1];
        if(res > d)
            return false;
    }
    return true;
}

int main(int argc, char** argv) {
    int n, m;
    scanf("%d %d", &n, &m);
    int posto[n+1];
    for(int i=0; i<n; i++){
        scanf("%d", &posto[i]);
    }
    posto[n]=DIST_TOTAL;
    bool resultado = verificaDistancias(posto,n+1,m);
    if(resultado)
        printf("S\n");
    else
        printf("N\n");
    return 0;
}
