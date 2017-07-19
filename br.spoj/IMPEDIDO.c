/* 

IMPEDIDO - ELE ESTÁ IMPEDIDO
http://br.spoj.com/problems/IMPEDIDO/
RONALDO MEDEIROS LUCINDO 

*/

#include <stdlib.h>
#include <stdio.h>

int compara(const void* x, const void* y){
	return ( *(int*)x - *(int*)y);
}

int main(){
	int a, d, i;
	while(1){
		scanf("%d", &a);
		scanf("%d", &d);
		if(a != 0 && d != 0){
			int atacantes[a];
			int defensores[d];
			for(i=0; i<a; i++){
				scanf("%d", &atacantes[i]);
			}
			for(i=0; i<d; i++){
				scanf("%d", &defensores[i]);
			}
			qsort(atacantes, a, sizeof(int), compara);
			qsort(defensores, d, sizeof(int), compara);
			if(atacantes[0] < defensores[1]){
				printf("Y\n");
			}
			else{
				printf("N\n");
			}
		}
		else{
			break;
		}
	}
	return 0;
}