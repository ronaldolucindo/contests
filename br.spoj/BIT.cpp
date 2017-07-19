/* 

BIT - BITS TROCADOS
http://br.spoj.pl/problems/BIT
RONALDO MEDEIROS LUCINDO

*/



#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

class Caixa{
public:
    int saque;
    int notas[4] = {0,0,0,0};
    
    Caixa(int v){
        saque=v;
    }
    void selecionaNotas(){
        while(saque!=0){
            if(saque>=50){
                notas[0]++;
                saque=saque-50;
            }
            else if(saque>=10){
                notas[1]++;
                saque=saque-10;
            }
            else if(saque>=5){
                notas[2]++;
                saque=saque-5;
            }
            else if(saque>=1){
                notas[3]++;
                saque=saque-1;
            }
        }
        printf("%d %d %d %d\n",notas[0], notas[1], notas[2], notas[3]);

    }
    
    
    
};


int main(int argc, char** argv) {
    int instancia=1;
    while(true){
        int v;
        scanf("%d", &v);
        if(v==0)
            break;
        Caixa c(v);
        printf("Teste %d\n", instancia);
        instancia++;
        c.selecionaNotas();
        printf("\n");
       
        
    }

    return 0;
}

