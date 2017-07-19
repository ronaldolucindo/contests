/* 

UVA357 - LET ME COUNT THE WAYS
http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=293
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <cstdio>
#include <vector>
#define MAX_VAL 30001

using namespace std;


int main(int argc, char** argv) {
    int moedas[]={1,5,10,25,50};
        vector<long> M(MAX_VAL,0);
        M[0]=1;
        for(int i=0; i<5; i++){
            for(int j=moedas[i]; j<MAX_VAL; j++){
                M[j] += M[j-moedas[i]];
            }
        }
    while(true){
        int n;
        scanf("%d", &n);
        if(feof(stdin))
            break;
        
        if(M[n]>1)
            printf("There are %ld ways to produce %d cents change.\n", M[n], n);
        else
            printf("There is only %ld way to produce %d cents change.\n", M[n], n);
        
        
    }
    return 0;
}