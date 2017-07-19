/* 

CALCADMG - CAMINHANDO PELA CALÇADA
http://br.spoj.com/problems/CALCADMG/
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <cstdio>

using namespace std;

int mdc(int a, int b){
    if(b==0)
        return a;
    else
        return mdc(b,a%b);
}

int main(int argc, char** argv) {
    int t;
    int a,b,c,d;
    scanf("%d",&t);
    for(int it=0; it<t; it++){
        scanf("%d %d %d %d", &a, &b, &c, &d);
        int resultado=mdc(abs(c-a),abs(d-b))+1;
        printf("%d\n", resultado);
    }
    return 0;
}