#include <stdio.h>
#include <iostream>

using namespace std;

int matriz[31][1001];

int n;

int a[31];

void soma(int k){
	int w;

	for (int i = 0; i <= n; ++i)
	{
		for (int j = 0; j <= k; ++j)
		{
			if(j == 0)
				matriz[i][j] = 1;
			else
				matriz[i][j] = 0;
		}
		
	}

	matriz[0][0] = 1;

	for(int i = 1; i <= n; i++){

		for(int j = 1; j <= k; j++){

			matriz[i][j] = matriz[i-1][j] || matriz[i][j];

			if(j - a[i-1] >= 0)
				matriz[i][j] |= matriz[i-1][j-a[i-1]];
		}

	}  
}

int main(){

	int d, c = 0;

	while(scanf("%d",&d) != EOF){
		c++;
		n = d;

		int isA = 1;

		for(int i = 0; i < d; i++){
			scanf("%d",&a[i]);
		}

		soma(a[d-1]);

		printf("Case #%d:",c);

		for(int i = 0; i < d; i++){

			cout << " " << a[i];
		}

		cout << endl;

		for(int j = d; j >= 2; j--){
			if(matriz[j-1][a[j-1]])
				isA = 0;
		}

		if(isA) printf("This is an A-sequence.\n");
		else printf("This is not an A-sequence.\n");
	}

}