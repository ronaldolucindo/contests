/* 

ENERGIA - TRANSMISSÃO DE ENERGIA
http://br.spoj.com/problems/ENERGIA/
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
                return 0;
            }
        }
        return 1;
    }
};

int main(int argc, char** argv) {
    int numTestes=0;
    while(true){
        int n,m;
        scanf("%d", &n);
        scanf("%d", &m);
        if(n==0 || m==0){
            break;
        }
        else{
            numTestes++;
            Graph *G = new Graph(n,m);
            for(int i=0; i<G->E ; i++ ){
                int v, w;
                scanf("%d", &v);
                scanf("%d", &w);
                G->matriz[v-1][w-1]=1; 
                G->matriz[w-1][v-1]=1;
            }
            int resultado;
            resultado=G->dfsAux();
            printf("Teste %d\n",numTestes);
            if(resultado==0){
                printf("falha\n");
                printf("\n");
            }
            else{
                printf("normal\n");
                printf("\n");
            }
        }
    }
    return 0;
}