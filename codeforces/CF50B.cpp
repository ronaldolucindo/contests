/* 

CF50B - CHOOSING SYMBOLS PAIRS
http://codeforces.com/problemset/problem/50/B
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
    string s;
    getline(cin, s);
    vector<long long> contador(36,0);
    char aux;
    int indice;
    for(long i=0; i<s.length(); i++){
        aux=s.at(i);
        indice=(int)aux-'a';
        if(indice >=0 && indice<=25){
            contador[indice+10]++;
        }
        else{
            indice=(int)s.at(i)-'0';
            contador[indice]++;
        }
    }
    long long soma=0;
    for(int i=0; i<contador.size(); i++){
        soma+=contador[i]*contador[i];
    }
        cout << soma;

    return 0;
}