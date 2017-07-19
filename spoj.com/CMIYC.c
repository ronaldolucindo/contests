/* 

CMIYC - CATCH ME IF YOU CAN
http://www.spoj.com/problems/CMIYC/
RONALDO MEDEIROS LUCINDO

*/

#include <stdlib.h>
#include <stdio.h>


int main(){
	int casosTeste, i;
	scanf("%d", &casosTeste);
	for(i=0; i<casosTeste; i++){
		long long n;
		scanf("%ld", &n);
		if(n%3 != 0){
			printf("0\n");
		}
		else{
			printf("%ld\n",n/3 );
		}
	}
	
	return 0;
}