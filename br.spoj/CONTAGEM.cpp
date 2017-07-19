/* 

CONTAGEM - NAO É MAIS UM JOGUINHO CANADENSE
http://br.spoj.com/problems/CONTAGEM/
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;

unsigned long long calculaCaminhos(string str){
    unsigned long long resultado=0;
    int r;
    if(str.size()==1){
        if(str[0]=='a')
            return 0;
        else
            return 1;
    }
    for(int i=0; i<str.size(); i++){
        if(str[i]=='b'){
            r=str.size()-i-1;
            resultado=resultado+(long long)pow(2,r);
        }
    }
    return resultado;
}
int main(int argc, char** argv) {
    int instancias=0;
    while(true){
        string str;
        cin >> str;
        if(feof(stdin))
            break;
        if(!str.empty()){
            unsigned long long res=calculaCaminhos(str);
            instancias++;
            cout << "Palavra " << instancias << "\n";
            cout << res << "\n";
            cout << "\n";
        }
    }

    return 0;
}