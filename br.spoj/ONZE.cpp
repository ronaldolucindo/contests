/* 

ONZE - VOCÊ PODE DIZER 11
http://br.spoj.com/problems/ONZE/
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;
bool eh_divisivel(string &str){
    int somaPar=0, somaImpar=0;
    for(int i=0; i<str.length(); i++){
        int aux=(int) str[i]-'0';
        if(((i+1)%2)==0)
            somaPar+=aux;
        else
            somaImpar+=aux;
    }
    int num=somaImpar-somaPar;
    return((num%11)==0);
}

int main(int argc, char** argv) {
    string str;
    while(true){
        cin >>str;
        if(str.length()==1 && str[0]=='0')
            break;
        if(eh_divisivel(str))
            cout << str <<" is a multiple of 11.\n";
        else
            cout << str << " is not a multiple of 11.\n";
        
    }

    return 0;
}