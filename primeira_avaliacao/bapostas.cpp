#include <stdio.h>

int s[10000];

int n;

int kadane(){

	int maxTotal = -1;

	int maxAtual = 0;

	for(int i = 0; i < n; i++){

		maxAtual += s[i];

		if(maxAtual < 0){
			maxAtual = 0;
		}

		if(maxAtual > maxTotal){
			maxTotal = maxAtual;
		}
	}

	return maxTotal;

}

int main(){

	while(1){

		scanf("%d",&n);

		if(n == 0)break;

		for(int i = 0; i < n; i++){
			scanf("%d",&s[i]);
		}

		int somaMax = kadane();

		if(somaMax > 0){
			printf("The maximum winning streak is %d.\n",somaMax);
		}else{
			printf("Losing streak.\n");
		}
	}
}