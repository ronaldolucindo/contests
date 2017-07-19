/* 

JDENTIST - DENTISTA
http://br.spoj.com/problems/JDENTIST
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <cstdio>

typedef struct horario{
    int inicio;
    int termino;
};

using namespace std;

int cmp(const void * a, const void * b){
    struct horario* x = (struct horario*)a;
    struct horario* y = (struct horario*)b;
    if(x->termino > y->termino)
        return 1;
    else if(x->termino < y->termino)
        return -1;
    else
        return 0;
}

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    horario h[n];
    for(int i=0; i<n; i++){
        int x,y;
        scanf("%d %d", &x, &y);
        h[i].inicio=x;
        h[i].termino=y;
    }
    qsort(h,n,sizeof(horario),cmp);
    int ht=h[0].termino;
    int resultado=1;
    for(int i=1; i<n; i++){
        if(h[i].inicio >= ht){
            resultado++;
            ht=h[i].termino;
        }
    }
    printf("%d\n", resultado);

    return 0;
}