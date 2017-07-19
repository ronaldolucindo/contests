/* 
 
BSEARCH1 - BINARY SEARCH
http://www.spoj.com/problems/BSEARCH1/
RONALDO MEDEIROS LUCINDO  

*/

#include <stdlib.h>
#include <stdio.h>

int buscaBinaria(int* vetor, int chave, int tamanho){
	int inicio=0;
	int fim=tamanho;
	while(1){
		if(fim < inicio){
			return -1;
		}
		int meio= inicio + (fim-inicio)/2;
		if(chave == vetor[meio]){
			int j=meio-1;
			while(1){
				if(chave == vetor[j]){
					j--;
				}
				else{
					return j+1;
				}
			}
			return meio;
		}
		if(chave < vetor[meio]){
			fim=meio-1;
		}
		else{
			inicio=meio+1;
		}
	}
	

}

int main(){
	int n, q, i;
	scanf("%d", &n);
	scanf("%d", &q);
	int numeros[n];
	for(i=0; i<n; i++){
		scanf("%d", &numeros[i]);
	}
	for(i=0; i<q; i++){
		int x, resultado;
		scanf("%d", &x);
		resultado=buscaBinaria(numeros,x,n);
		printf("%d\n", resultado );
	}
	return 0;
}