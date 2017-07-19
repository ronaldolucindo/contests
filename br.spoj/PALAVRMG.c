/* 

PALAVRMG - PALAVRAS ORDENADAS 
http://br.spoj.com/problems/PALAVRMG/
RONALDO MEDEIROS LUCINDO

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void eh_ordenada(char* str){
	int i, flag=1;
	for(i=0; i < strlen(str)-1; i++){
		if(tolower(str[i]) >= tolower(str[i+1])){
			flag=0;
			printf("%s: N\n", str);
			break;
			
		}
	}
	if(flag==1){
		printf("%s: O\n", str);
	}
}

int main(){
	int p, i;
	
	scanf("%d", &p);
	for(i=0; i < p; i++){
		char palavra[42];
		scanf("%s", palavra);
		eh_ordenada(palavra);

	}
	
	return 0;
}