/* 

URI1961 - JUMPING FROG
https://www.urionlinejudge.com.br/judge/en/problems/view/1961
RONALDO MEDEIROS LUCINDO

*/
int verificaJogo(int *v, int size, int pulo){
	int i, j;
	for(i=0,j=1; i<size, j<size ; i++, j++){
		if(abs(v[j]-v[i]) > pulo){
			printf("GAME OVER\n");
			return 0;
		}
	}
	printf("YOU WIN\n");
	return 1;
}

int main(){
	int p, i, n;
	scanf("%d %d", &p, &n);
	int canos[n];
	for(i=0; i<n; i++){
		scanf("%d", &canos[i]);
	}
	verificaJogo(canos,n,p);



	return 0;
}