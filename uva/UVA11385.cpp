/* 

UVA11385 - DA VINCI CODE
http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2380 
RONALDO MEDEIROS LUCINDO

*/


#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#define MAX_FIB 44


using namespace std;

vector<long> fibonacci(){
    vector<long> result(MAX_FIB,0);
    int x=1,y=2,aux;
    result[0]=x;
    result[1]=y;
    for(int i=2; i<MAX_FIB; i++){
        aux=x+y;
        result[i]=aux;
        x=y;
        y=aux;
    }
    return result;
    
}
int fibIndex(long n, vector<long> v){
    for(int i=0; i< v.size(); i++){
        if(n==v[i])
            return i;
    }
}

void removeBlank(string &str){
    while(!str.empty() && isspace(*str.rbegin()))
        str.erase(str.length()-1);
}

int main(int argc, char** argv) {
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n;
        cin >> n;
        vector<long> num(n);
        for(int j=0; j<n; j++){
            cin >> num[j];
        }
        cin.ignore();
        string s;
        getline(cin, s);
        vector<long> fibNum=fibonacci();
        string resultado(100,' ');
        int index,j=0,k=0;
        while(j<s.length() && k<num.size()){
            index=(int)s[j]-'A';
            if(index>=0 && index <=25){
               int aux= fibIndex(num[k],fibNum);
               resultado[aux]=s[j];
               k++;
                
            }
            j++;
        }
        removeBlank(resultado);
        cout << resultado << endl;
        
    }

    return 0;
}