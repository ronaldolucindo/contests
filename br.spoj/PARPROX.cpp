/* 

PARPROX - PONTOS
http://br.spoj.com/problems/PARPROX/
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <cstdio>
#include <vector>
#include <limits.h>
#include <math.h>
#include <cfloat>

using namespace std;

float distancia(pair< int,int> x1, pair< int,int> x2){
    return sqrt(pow(x2.first-x1.first,2)+pow(x2.second-x1.second,2));
}

float menorDistancia(vector< pair< int,int> > &pontos){
    float min=FLT_MAX;
    for(int i=0; i<pontos.size(); i++){
        for(int j=0; j<pontos.size(); j++){
            float dist=distancia(pontos[i],pontos[j]);
            if(i!=j && dist<min)
                min=dist;
        }
    }
    return min;
}

int main(int argc, char** argv) {
    int n,a,b;
    scanf("%d", &n);
    vector< pair< int,int> > pontos(n,make_pair(0,0));
    for(int i=0; i<n; i++){
        scanf("%d %d", &a, &b);
        pontos[i].first=a;
        pontos[i].second=b;
    }
    
    float resultado=menorDistancia(pontos);
    printf("%.3f\n", resultado);

    return 0;
}