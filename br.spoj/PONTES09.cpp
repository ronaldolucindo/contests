/* 

PONTES09 - CAMINHO DAS PONTES
http://br.spoj.com/problems/PONTES09/
RONALDO MEDEIROS LUCINDO

*/


#include <cstdlib>
#include <cstdio>
#include <list>
#include <queue>
#define INFINITO 10000000

using namespace std;

class Grafo{
public:
    int v;
    list<pair <int,int> > *adjacencia;
    
    Grafo(int n){
        this->v=n;
        adjacencia= new list<pair <int,int> >[n];
    }
    void add(int v, int w, int t){
        adjacencia[v].push_back(make_pair(w, t));
        adjacencia[w].push_back(make_pair(v, t));
    }
    int dijkstra(int s, int d){
        bool visitado[this->v];
        int distancias[this->v];
        for(int i=0; i<this->v; i++){
            visitado[i]=false;
            distancias[i]=INFINITO;
        }
        distancias[s]=0;
        priority_queue<pair <int, int>, vector<pair <int, int> >, 
                greater<pair <int, int> > > pqueue;
        pqueue.push(make_pair(distancias[s], s));
        while(!pqueue.empty()){
            int w=pqueue.top().second;
            pqueue.pop();
            if(visitado[w] == false){
                visitado[w]=true;
                list<pair <int, int> >::iterator i;
                for(i=adjacencia[w].begin(); 
                        i!=adjacencia[w].end(); i++ ){
                    int u= i->first;
                    int custo= i->second;
                    if(distancias[u] > (distancias[w] +custo)){
                        distancias[u]=distancias[w]+custo   ;
                        pqueue.push(make_pair(distancias[u],u));
                    }
                }
            }
        }
        return distancias[d]; 
    }   
 };

int main(int argc, char** argv) {
    int n, m;
    scanf("%d %d", &n, &m);
    int size=n+1;
    Grafo g(n+2);
    for(int i=0; i<m; i++){
        int s, t, b;
        scanf("%d %d %d", &s, &t, &b);
        g.add(s,t,b);
    }
    int resultado = g.dijkstra(0,n+1);
    printf("%d\n", resultado);
    return 0;
}