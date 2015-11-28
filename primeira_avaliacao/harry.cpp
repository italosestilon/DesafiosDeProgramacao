#include <iostream>
#include <map>
#include <stdio.h>

using namespace std;

int matriz[501][501], r,c;

int main(){
	int casos;

	scanf("%d",&casos);

	while(casos--){
		scanf("%d %d",&r,&c);
		
		for(int i = 0; i < r; i++){
			
			for(int j = 0; j < c; j++){
				scanf("%d",&matriz[i][j]);
			}
			
		}

		matriz[r-1][c-1] = 1;

		for(int i = r-2; i >= 0; i--){

			matriz[i][c-1] = matriz[i+1][c-1] - matriz[i][c-1];

			if(matriz[i][c-1] <= 0)
				matriz[i][c-1] = 1;
		}

		for(int i = c-2; i >= 0; i--){

			matriz[r-1][i] = matriz[r-1][i+1] - matriz[r-1][i];

			if(matriz[r-1][i] <= 0)
				matriz[r-1][i] = 1;
		}

		for(int i = r-2; i >= 0; i--){
			for(int j = c-2; j >= 0; j--){
				matriz[i][j] = min(matriz[i+1][j],matriz[i][j+1]) - matriz[i][j];
				if(matriz[i][j] <= 0)
					matriz[i][j] = 1;
			}
		}

		cout << matriz[0][0] << endl;
	}
}