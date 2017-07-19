/* 

PEDAGIO - PEDAGIO
http://br.spoj.com/problems/PEDAGIO/
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <list>
#include <set>
#include <cstdio>
#include <vector>

using namespace std;

class Grafo{
public:
    int v;
    list<int> *adjacencia;
    set<int> resultado;
    vector<int> distancia;
    int limite;
    
    Grafo(int n, int l){
        this->v=n;
        adjacencia= new list<int>[n];
        this->limite=l;
        vector<int> aux(v,0);
        this->distancia=aux;
    }
    void add(int v, int w){
        adjacencia[v].push_back(w);
        adjacencia[w].push_back(v);
    }
    void bfs(int n){
        bool *visitado= new bool[v];
        for(int i=0; i<v; i++)
            visitado[i]=false;
        visitado[n]=true;
        list<int> fila;
        fila.push_back(n);
        list<int>::iterator it;
        while(!fila.empty() ){
            n=fila.front();
            fila.pop_front();
            for(it=adjacencia[n].begin(); it != adjacencia[n].end(); it++){
                if(!visitado[*it]){
                    distancia[*it]=distancia[n]+1;
                    visitado[*it]=true;
                    fila.push_back(*it);
                }
            }
        }
        for(int i=0; i<distancia.size(); i++){
            if(distancia[i] <= limite && distancia[i]>0){
                this->resultado.insert(i+1);
            }
        }
        
    }
    
};
int main(int argc, char** argv) {
    int testes=1;
    while(true){
        int c, e, l, p;
        scanf("%d %d %d %d", &c, &e, &l, &p);
        if( c == 0 && e==0 && l==0 && p==0)
            break;
        Grafo g(c,p);
        for(int i=0; i<e; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            g.add(a-1,b-1);
        }
        g.bfs(l-1);
        set<int>::iterator j;
        printf("Teste %d\n", testes);
        for(j=g.resultado.begin(); j!=g.resultado.end(); j++){
            if(*j != l)
                printf("%d ",*j);
        }
        printf("\n\n");
        testes++;
    }

    return 0;
}