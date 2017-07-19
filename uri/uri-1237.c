/* 

URI 1237 - Compare Substring
https://www.urionlinejudge.com.br/judge/en/problems/view/1237
Ronaldo Medeiros Lucindo

*/

#include <stdlib.h>
#include <stdio.h>
#include "string.h"

int main(){
	char str1[55];
	char str2[55];
	while(!feof(stdin) && gets(str1)!=NULL && gets(str2)!=NULL){
		int substr=0;
		int count=0,i,j,k,l;
		for (i = 0; i < strlen(str1); i++){
			for(j=0; j< strlen(str2); j++){
				if(str1[i]==str2[j] && str1[i]!=NULL && str2[j]!=NULL){
					count=1;
					k=i+1;
					l=j+1;
					while(k<=strlen(str1) || l<=strlen(str2)){
						if(str1[k]==str2[l] && str1[k]!=NULL && str2[l]!=NULL){
							count++;
							k++;
							l++;
						}
						else{	
							if(count>substr){
								substr=count;
							}
							count=0;
							break;		
						}				
					}
				}
			}
		}
	printf("%d\n", substr );
	substr=0;
	}
	return 0;

}