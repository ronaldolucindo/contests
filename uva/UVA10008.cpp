/* 

UVA10008 - WHAT'S CRYPTANALYSIS
https://uva.onlinejudge.org/index.php?option=onlinejudge&Itemid=99999999&page=show_problem&category=&problem=949
RONALDO MEDEIROS LUCINDO

*/

#include <cstdlib>
#include <string>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<pair<int,int> > contaLetras(string str, vector<pair<int,int> > &resultado){
    for(int i=0; i<str.size(); i++){
        char aux=toupper(str.at(i));
        int indice= aux-'A';
        if(indice<=25 && indice>=0){
            resultado.at(indice).first=indice;
            resultado.at(indice).second++;        
        }
    }
    return resultado;
}

bool compara(const pair<int,int> &a,const pair<int,int> &b){
    if(a.second > b.second)
        return true;
    if(a.second ==b.second){
        return (a.first<b.first);
    }
    else
        return false; 
}

int main(int argc, char** argv) {
    int n;
    vector<pair<int,int> > resultado(26,make_pair(0,0));
    cin >> n;
    cin.ignore();
    for(int i=0; i<n; i++){
        string str;
        getline(cin,str);
        contaLetras(str,resultado);
    }
    sort(resultado.begin(),resultado.end(),compara);
    for(int i=0; i<resultado.size(); i++){
        if(resultado.at(i).second>0){
            char letra=resultado.at(i).first+'A';
            cout << letra <<" " << resultado.at(i).second <<"\n";
        }
    }

    return 0;
}