/* 

REDOTICA - REDE OTICA
http://br.spoj.com/problems/REDOTICA/
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
    void prim(){
       priority_queue<pair <int, int>, vector<pair <int, int> >, 
                greater<pair <int, int> > > pqueue;
       int origem=0;
       vector<int> pai(v,-1);
       vector<bool> incluido(v,false);
       vector<int> chave(v,INFINITO);
       pqueue.push(make_pair(0,origem));
       chave[origem]=0;
       while(!pqueue.empty()){
           int t=pqueue.top().second;
           incluido[t]=true;
           pqueue.pop();
           list< pair<int,int> >::iterator i;
           for(i=adjacencia[t].begin(); i!=adjacencia[t].end(); i++){
               int s = i->first;
               int custo = i->second;
               if(incluido[s]==false && chave[s] >custo){
                   chave[s]=custo;
                   pqueue.push(make_pair(chave[s],s));
                   pai[s]=t;
               }
           } 
       }
       for(int i=0; i<v; i++){
           if(pai[i]!= -1){
               if(pai[i] > i)
                   printf("%d %d\n", i+1, pai[i]+1);
               else
                   printf("%d %d\n", pai[i]+1, i+1);
           }
       }
    }
 };

int main(int argc, char** argv) {
    int instancias=0;
    while(true){
        int n, m;
        scanf("%d %d", &n, &m);
        if(n==0 && m==0)
            break;
        Grafo g(n);
        for(int i=0; i<m; i++){
            int x, y, z;
            scanf("%d %d %d", &x, &y, &z);
            g.add(x-1,y-1,z);
        }
        instancias++;
        printf("Teste %d\n", instancias);
        g.prim();
        printf("\n");
    }

    return 0;
}