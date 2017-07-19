/* 

POPULAR - POPULARIDADE
http://br.spoj.com/problems/POPULAR/
RONALDO MEDEIROS LUCINDO

*/

#include <stdlib.h>
#include <stdio.h>

int compara(const void* a, const void* b){
	return ( *(int*)a - *(int*)b);
}

void zeraVetor(int* vetor, int size){
	int i;
	for(i=0; i<size; i++){
		vetor[i]=0;
	}
}

int main(){
	while(1){
		int n, i, j;
		scanf("%d", &n);
		if(n==0){
			break;
		}
		int matrix[n][n];
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				scanf("%d", &matrix[i][j]);
			}
			
		}
		int resultados[n];
		zeraVetor(resultados, n);
		for(i=0; i<n; i++){
			for(j=0; j<n; j++){
				if(matrix[j][i] == 1){
					resultados[i]++;
				}
			}
		}
		qsort(resultados, n, sizeof(int), compara);
		
		printf("%d\n", resultados[n-1] );
	}
	
	return 0;
}