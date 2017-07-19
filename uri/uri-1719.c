/* 

URI 1719 - Simple Computers
https://www.urionlinejudge.com.br/judge/en/problems/view/1719
Ronaldo Medeiros Lucindo

*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int incrementPC(int pc);
void binaryString(unsigned char c);


int main(){
	char str[9];
	while(!feof(stdin) && scanf("%s\n",str)){
		unsigned char memory[33];
		unsigned char accu=0;
		int pc=0;
		memory[0]=strtoul(str,NULL,2);
		int i;
		for(i=1;i<32;i++){
			scanf("%s\n",str);
			memory[i]=strtoul(str,NULL,2);
		}
		while(1){
			unsigned op=memory[pc]>>5;
			unsigned address= memory[pc] & 31;
			if(op==0){
				pc=incrementPC(pc);
				memory[address]=accu;
			}
			else if(op==1){
				pc=incrementPC(pc);
				accu=memory[address];
			}
			else if(op==2){
				pc=incrementPC(pc);
				if(accu==0){
					pc=address;
				}
			}
			else if(op==3){
				pc=incrementPC(pc);
			}
			else if(op==4){
				pc=incrementPC(pc);
				accu--;
			}
			else if(op==5){
				pc=incrementPC(pc);
				accu++;
			}
			else if(op==6){
				pc=incrementPC(pc);
				pc=address;
			}
			else if(op==7){
				binaryString(accu);
				break;
			}

		}
	}
	return 0;
}

int incrementPC(int pc){
	int result=pc+1;
	if(result>31){
		result=0;
	}
	return result;
}
void binaryString(unsigned char c){
	int i=7;
	char result[9]="";
	while(i>=0){
		if(c&(1<<i)){
			strcat(result,"1");
		}
		else{
			strcat(result,"0");
		}
		i--;	
	}
	printf("%s\n",result );
}