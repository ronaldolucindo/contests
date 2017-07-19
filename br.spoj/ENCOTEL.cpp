/* 

ENCOTEL - ENCONTRE O TELEFONE
http://br.spoj.com/problems/ENCOTEL/
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

string converteNumero(string str){
    string resultado;
    for(int i=0; i<str.size(); i++){
        if(str.at(i)=='A' || str.at(i)=='B' || str.at(i)=='C')
            resultado.append("2");
        else if(str.at(i)=='D' || str.at(i)=='E' || str.at(i)=='F')
            resultado.append("3");
        else if(str.at(i)=='G' || str.at(i)=='H' || str.at(i)=='I')
            resultado.append("4");
        else if(str.at(i)=='J' || str.at(i)=='K' || str.at(i)=='L')
            resultado.append("5");
        else if(str.at(i)=='M' || str.at(i)=='N' || str.at(i)=='O')
            resultado.append("6");
        else if(str.at(i)=='P' || str.at(i)=='Q' || str.at(i)=='R' || str.at(i)=='S')
            resultado.append("7");
        else if(str.at(i)=='T' || str.at(i)=='U' || str.at(i)=='V')
            resultado.append("8");
        else if(str.at(i)=='W' || str.at(i)=='X' || str.at(i)=='Y' || str.at(i)=='Z')
            resultado.append("9");
        else if(str.at(i)=='0')
            resultado.append("0");
        else if(str.at(i)=='1')
            resultado.append("1");
        else if(str.at(i)=='-')
            resultado.append("-");
    }
    return resultado;

    
}
int main(int argc, char** argv) {
    string str,resultado;
    while(getline(cin,str)){
        resultado=converteNumero(str);
        cout << resultado << "\n";
    }

    return 0;
}