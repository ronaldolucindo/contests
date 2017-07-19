/* 

URI 1246 - Parking Lot
https://www.urionlinejudge.com.br/judge/en/problems/view/1246
Ronaldo Medeiros Lucindo

*/

#include <stdlib.h>
#include <stdio.h>
int Findcar(int car[][3], int size, int plate, int* position);
int haveSpace(int* lot, int lotSize, int carSize);
void createLot(int* lot, int lotSize);
void createCarList(int car[][3], int size);
int main(){
	int parkLength;
	int operations;
	int money=0;
	int i,j;
	while(!feof(stdin) && scanf("%d%d\n",&parkLength, &operations)){
		int parkingLot[parkLength];
		createLot(parkingLot,parkLength);
		int car[operations][3];
		createCarList(car,operations);
		for(i=0;i<operations;i++){
			char mode;
			scanf("%c",&mode);
			if(mode=='C'){
				int carPlate, carLength;
				scanf("%d%d\n",&carPlate,&carLength);
				int fit=haveSpace(parkingLot,parkLength,carLength);
				if(fit >=0){
					for(j=0;j<operations;j++){
						if(car[j][0]==0){
							car[j][0]=carPlate;
							car[j][1]=carLength;
							car[j][2]=fit;
							break;
						}
					}
					int aux=0;
					int k=fit;
					while(aux<carLength){
						parkingLot[k]=1;
						aux++;
						k++;
					}
					money+=10;
				}
			}
			else if(mode=='S'){
				int plate, leavingCar, position;;
				scanf("%d\n",&plate);
				leavingCar=Findcar(car,operations,plate,&position);
				int aux=0, k=position;
				
				while(aux<leavingCar){
					parkingLot[k]=0;
					aux++;
					k++;
				}
			}
		}
		printf("%d\n",money );
		money=0;
	}
	return 0;

}
int Findcar(int car[][3], int size, int plate, int* position){
	int i, result, sum=0;
	for(i=0;i<size;i++){
		if(car[i][0]==plate){
			result=car[i][1];
			car[i][0]=0;
				int l;
				for(l=0;l<i;l++){
						sum= sum+car[l][1];
				}
				 *position=car[l][2];			
			return result;	
		}
	}
}

int haveSpace(int* lot, int lotSize, int carSize){
	int i, count=0, result= -1;
	for(i=0;i<lotSize;i++){
		if(lot[i]==0){
			count++;
			if(count==carSize){
				result=(i-count)+1;
				break;
			}
		}
		else{
			count=0;
		}

	}
	return result;
}

void createLot(int* lot, int lotSize){
	int i;
	for(i=0;i<lotSize;i++){
		lot[i]=0;
	}
}
void createCarList(int car[][3], int size){
	int i;
	for(i=0;i<size;i++){
		car[i][0]=0;
		car[i][1]=0;
	}
}

