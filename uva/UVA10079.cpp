/* 

UVA10079 - PIZZA CUTTING
http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1020
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <cstdio>

using namespace std;


int main(int argc, char** argv) {
    long n;
    while(true){
        scanf("%ld", &n);
        if(n<0)
            break;
        long long result;
        result= (n*n+n)/2+1;
        printf("%lld\n",result);
    }

    return 0;
}