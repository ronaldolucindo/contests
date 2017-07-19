/* 

URI1028 - FIGURINHAS
https://www.urionlinejudge.com.br/judge/en/problems/view/1028
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
    int n;
    scanf("%d", &n);
    for(int it=0; it<n; it++){
        int f1, f2;
        scanf("%d %d",&f1, &f2);
        int resultado=mdc(f1,f2);
        printf("%d\n", resultado);
    }

    return 0;
}