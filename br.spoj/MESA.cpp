/* 

MESA - MESA DA SRA MONTAGNY
http://br.spoj.com/problems/MESA/
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <cstdio>
#include <list>
#include <vector>

using namespace std;

class Grafo{
public:
    int v;
    list<int> *adjacencia;
    
    Grafo(int n){
        this->v=n;
        adjacencia= new list<int>[n];
    }
    void add(int v, int w){
        adjacencia[v].push_back(w);
        adjacencia[w].push_back(v);
    }
    bool bfs(int n){
        bool *visitado= new bool[v];
        visitado[n]=true;
        vector<int>cor(v,0);
        list<int> fila;
        fila.push_back(n);
        list<int>::iterator it;
        int count=0;
        while(!fila.empty()){
            n=fila.front();
            if(cor[n]==0)
                cor[n]=1;
            fila.pop_front();
            for(it=adjacencia[n].begin(); it != adjacencia[n].end(); it++){
                if(cor[*it]==cor[n])
                        return false;
                if(cor[*it]==0){
                    if(cor[n]==1)
                        cor[*it]=2;
                    else
                        cor[*it]=1;
                }
                if(!visitado[*it]){
                    visitado[*it]=true;
                    fila.push_back(*it);
                    
                }
            }
            
        }
       return true; 
    }
    
};
int main(int argc, char** argv) {
    int n, m, instancias=1;
    while(1){
        scanf("%d %d", &n, &m);
        if(feof(stdin))
            break;
        Grafo g(n);
        for(int i=0; i<m; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            g.add(a-1,b-1);
        }
        bool resultado;
        resultado=g.bfs(0);
        printf("Instancia %d\n", instancias);
        if(resultado==true){
            printf("sim\n\n");
        }
        else{
            printf("nao\n\n");
        }
        instancias++;
    }
    return 0;
}

