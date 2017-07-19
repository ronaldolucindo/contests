/* 

PLACAR - QUEM VAI SER REPROVADO
http://br.spoj.com/problems/PLACAR/
RONALDO MEDEIROS LUCINDO

*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct aluno{
	char nome[21];
	int solucoes;
}aluno;


int compara(const void* a, const void* b){
	struct aluno* x = (struct aluno*)a;
	struct aluno* y = (struct aluno*)b;
	if(x->solucoes > y->solucoes)
		return 1;
	else if(x->solucoes < y->solucoes)
		return -1;
	else{
		return strcoll(x->nome, y->nome)*(-1);
	}
}

int main(){
	int n, i, instancias=1;
	while(1){
		scanf("%d", &n);
		if(feof(stdin))
			break;
		struct aluno alunos[n];
		for(i=0; i<n; i++){
			scanf("%s", alunos[i].nome);
			scanf("%d", &alunos[i].solucoes);

		}
		qsort(alunos, n, sizeof(aluno), compara);
		printf("Instancia %d\n", instancias);
		instancias++;
		printf("%s\n", alunos[0].nome );
		printf("\n");
	}
	return 0;
}