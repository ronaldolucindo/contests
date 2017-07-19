/* 

NLOGONIA - DIVISÃO DA NLOGÔNIA
http://br.spoj.com/problems/NLOGONIA/
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <cstdio>

using namespace std;

class Ponto{
public:
    int x;
    int y;
    
    Ponto(int a, int b){
        x=a;
        y=b;
    }
    
    void determinaPais(Ponto &inicial){
        if(x==inicial.x || y==inicial.y)
            printf("divisa\n");
        else if(x<inicial.x){
            if(y>inicial.y)
                printf("NO\n");
            else
                printf("SO\n");
        }
        else if(x>inicial.x) {
            if(y>inicial.y)
                printf("NE\n");
            else
                printf("SE\n");
        }
    }
};

int main(int argc, char** argv) {
    int k;
    while(true){
        scanf("%d",&k);
        if(k==0)
            break;
        int x0,y0,xi,yi;
        scanf("%d %d", &x0, &y0);
        Ponto inicial(x0,y0);
        for(int it=0; it<k; it++){
            scanf("%d %d", &xi, &yi);
            Ponto p(xi,yi);
            p.determinaPais(inicial);
        }
    }
    return 0;
}