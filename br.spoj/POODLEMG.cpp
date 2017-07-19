/* 

POODLEMG - POODLE
http://br.spoj.com/problems/POODLEMG/
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <cstdio>

using namespace std;

int calculaPaginas(int n, int p){
    int quociente,resto;
    quociente=n/p;
    resto=n%p;
    if(resto>0)
        quociente++;
    if(quociente >20)
        quociente=20;
    return quociente;
}

int main(int argc, char** argv) {
    while(true){
        int n,p;
        scanf("%d %d", &n, &p);
        if(n==0 && p==0)
            break;
        int resultado=calculaPaginas(n,p);
        if(resultado <= 6)
            printf("Poodle\n");
        else{
            printf("P");
            for(int i=0; i<resultado-4; i++){
                printf("o");
            }
            printf("dle\n");
                
        }
        
    }
    return 0;
}