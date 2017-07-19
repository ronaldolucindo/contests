/* 

UVA820 - INTERNET BANDWIDTH
http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=761
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <cstdio>
#include <queue>
#include <limits.h>
#include <locale>

using namespace std;

class Grafo{
private:
    int V;
    int* pai;
    int** matriz;
    int** fluxo;
    
public:
    Grafo(int n){
        V=n;
        pai = new int[n];
        matriz = new int*[n];
        fluxo = new int*[n];
        for(int i=0; i<n; i++){
            matriz[i] = new int[n];
            fluxo[i] = new int[n];
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matriz[i][j]=0;
            }
        }
    }
    ~Grafo(){
        delete [] pai;
        for(int i=0; i<V; i++)
            delete [] matriz[i];
        delete [] matriz;
        
    }
    void add(int x, int y, int f){
            matriz[x][y]+=f;
            matriz[y][x]+=f;     
        
    }
    bool bfs(int s, int t){
        queue<int> q;
        vector<bool> visitado(V,false);
        q.push(s);
        pai[s]=-1;
        visitado[s]=true;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=0; i<V; i++){
                if(visitado[i]==false && fluxo[u][i]>0){
                    visitado[i]=true;
                    q.push(i);
                    pai[i]=u;
                }
            }
        }
        return (visitado[t]==true);
    }
    int fordFulkerson(int s, int t){
        for(int i=0; i<V; i++)
            for(int j=0; j<V; j++)
                fluxo[i][j]=matriz[i][j];
        int u, v, fluxoMaximo=0;
        while(bfs(s,t)){
            int fluxoCaminho= INT_MAX;
            for(v=t; v!=s; v=pai[v]){
                u=pai[v];
                fluxoCaminho=min(fluxoCaminho,fluxo[u][v]);
            }
            for(v=t; v!=s; v=pai[v]){
                u=pai[v];
                fluxo[u][v]-= fluxoCaminho;
                fluxo[v][u]+= fluxoCaminho;
                
            }
            fluxoMaximo += fluxoCaminho;
        }
        return fluxoMaximo;    
    }
};

int main(int argc, char** argv) {
    int instancia=0;
    while(true){
        int n, s, t, c;
        scanf("%d", &n);
        if(n==0)
            break;
        Grafo g(n);
        scanf("%d %d %d", &s, &t, &c);
        for(int i=0; i<c; i++){
            int v,u,b;
            scanf("%d %d %d", &v, &u, &b);
            g.add(v-1,u-1,b);
        }
        int resultado=g.fordFulkerson(s-1,t-1);
        instancia++;
        printf("Network %d\n", instancia);
        printf("The bandwidth is %d.\n", resultado);
        printf("\n");
    }
    return 0;
}