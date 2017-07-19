/* 

BICHO - JOGO DO BICHO
http://br.spoj.com/problems/BICHO/
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <cstdio>
using namespace std;

bool quatroDigitos(int a, int b){
    return ((a%10000)==(b%10000));
}
bool tresDigitos(int a, int b){
    return ((a%1000)==(b%1000));
}
bool doisDigitos(int a, int b){
    return((a%100)==(b%100));
}
bool mesmoGrupo(int a, int b){
    int m1=a%100;
    int m2=b%100;
    if((m1==97||m1==98||m1==99||m1==00) && (m2==97||m2==98||m2==99||m2==00))
        return true;
    else if(((m1+3)/4)==(m2+3)/4)
        return true;
    else
        return false;
}

int main(int argc, char** argv) {
    double v;
    int n,m;
    while(true){
        scanf("%lf %d %d",&v, &n, &m);
        if(v==0 && n==0 && m==0)
            break;
        double resultado;
        if(quatroDigitos(n,m)){
            resultado= v*3000;
            printf("%.2lf\n",resultado);
        }
        else if(tresDigitos(n,m)){
            resultado= v*500;
            printf("%.2lf\n",resultado);
        }
        else if(doisDigitos(n,m)){
            resultado=v*50;
            printf("%.2lf\n",resultado);
        }
        else if(mesmoGrupo(n,m)){
            resultado=v*16;
            printf("%.2lf\n",resultado);
        }
        else
            printf("0.00\n"); 
    }

    return 0;
}