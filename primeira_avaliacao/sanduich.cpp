#include <stdio.h>

#define M 1300031

int n;

int main(){

	int c;

	scanf("%d",&c);

	while(c--){
		scanf("%d",&n);
		unsigned long long int soma = 0;
		unsigned long long int  soma2 = 0;
		int a;
		for(int i = 1; i <= n; i++){
			scanf("%d",&a);
			a %= M;
			soma2 += a;
			soma = (((soma2)*(a)) + soma)%M;
			
		}

		printf("%lld\n",soma);
	}
}