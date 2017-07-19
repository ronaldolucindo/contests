/* 

IREVIR - IR E VIR
http://br.spoj.com/problems/IREVIR/
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <cstdio>

using namespace std;

class Graph{
public:
    int V, E;
    int **matriz;
    int contador;
    
    
    Graph(int n, int m){
        this->V=n;
        this->E=m;
        this->matriz= new int*[n];
        for(int i=0; i<n; i++){
            this->matriz[i]= new int[n];
        }
    }
    ~Graph(){
        for(int i = 0; i < V; ++i)
            delete [] matriz[i];
        delete [] matriz;
    }
    void dfs(int k, bool visitado[]){
        this->contador++;
        visitado[k]=true;
        for(int i=0; i<this->V; i++){
            if(!visitado[i] && this->matriz[k][i]==1){
                dfs(i,visitado);
            }
        }
    }
    int dfsAux(){
        for(int i=0; i<this->V; i++){
            this->contador=0;
            bool *visitado= new bool[this->V];
            this->dfs(i,visitado);
            if(this->contador != this->V){
                printf("0\n");
                return 0;
            }
        }
        printf("1\n");
        return 1;
    }
};

int main(int argc, char** argv) {
    while(true){
        int n,m;
        scanf("%d", &n);
        if(n==0){
            break;
        }
        else{
            scanf("%d", &m);
            Graph *G = new Graph(n,m);
            for(int i=0; i<G->E ; i++ ){
                int v, w, p;
                scanf("%d", &v);
                scanf("%d", &w);
                scanf("%d", &p);
                if(p==2){
                    G->matriz[v-1][w-1]=1;
                    G->matriz[w-1][v-1]=1;
                }
                else{
                    G->matriz[v-1][w-1]=1;
                }
                
            }
            G->dfsAux();
        }  
    }
    return 0;
}