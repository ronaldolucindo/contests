/* 

MTOTALF - TOTAL FLOW
http://www.spoj.com/problems/MTOTALF/
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <cstdio>
#include <queue>
#include <limits.h>
#include <locale>
#define MAX_NOS 52

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
    int n;
    scanf("%d", &n);
    Grafo g(MAX_NOS);
    for(int i=0; i<n; i++){
        char x[2],y[2];
        int s, t, f;
        scanf("%s %s %d", x, y, &f);
        if(x[0]>='a' && x[0]<='z')
            x[0]+='Z'+1-'a';
        if(y[0]>='a' && y[0]<='z')
            y[0]+='Z'+1-'a';
        s= (int)x[0]-'A';
        t= (int)y[0]-'A';
        g.add(s,t,f);  
    }
    int resultado, nascente, celeiro;
    nascente=0;
    celeiro= 'Z'-'A';
    resultado=g.fordFulkerson(nascente,celeiro);
    printf("%d\n", resultado);
    return 0;
}