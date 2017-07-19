/* 

CANDY - CANDY I
http://www.spoj.com/problems/CANDY/
RONALDO MEDEIROS LUCINDO

*/

#include <stdlib.h>
#include <stdio.h>


int main(){
	while(1){
		int n, i, j, soma=0;
		scanf("%d", &n);
		if(n == -1){
			break;
		}
		int pacote[n];
		for(i=0; i<n; i++){
			scanf("%d", &pacote[i]);
			soma=soma+pacote[i];

		}
		if((soma%n) != 0){
			printf("-1\n");
		}
		else{
			int balasPorCaixa=soma/n;
			int mudancas=0;
			for(i=0; i<n; i++){
				if(pacote[i] < balasPorCaixa){
					mudancas=mudancas+(balasPorCaixa-pacote[i]);
				}
			}
			printf("%d\n", mudancas );
		}
	}
	
	return 0;
}