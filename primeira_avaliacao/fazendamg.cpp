#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int matriz[1502][1502],l,c;


int area = 0;
int perimetro = 0;

void contarPerimetro(int limiteEsq, int limiteDir, int limiteCime, int limiteBaixo){
	for(int i = limiteEsq; i < limiteDir; i++){

		for(int j = limiteCime; j < limiteBaixo; j++){
			if(matriz[i][j] == 1){
				perimetro += 4;

				if(j > 0 && matriz[i][j - 1])
					perimetro--;
				if(j < (1502- 1) && matriz[i][j + 1])
					perimetro--;
				if(i > 0 && matriz[i - 1][j])
					perimetro--;
				if(i < (1502 - 1) && matriz[i + 1][j])
					perimetro--;
			}
		}
	}
}

int main(){

	int n;
	while(1){
		cin >> n;

		if(n == 0) break;

		area = perimetro = 0;

		memset(matriz,0,sizeof matriz);

		int limiteEsq = 1502, limiteDir = -1, limiteCime = 1502, limiteBaixo = -1;

		while(n--){

			int x, y;

			cin >> x >> y >> l >> c;

			if(y < limiteCime)
				limiteCime = y;

			if(y + c > limiteBaixo)
				limiteBaixo = y + c;

			if(x < limiteEsq)
				limiteEsq = x;

			if(x+l > limiteDir)
				limiteDir = x + l;

			for(int i = x; i < l+x; i++){
				for(int j = y; j< c+y; j++ ){
					if(matriz[i][j] == 0){
						area++;
						matriz[i][j] = 1;
					}
				}
			}
		}

		contarPerimetro(limiteEsq,limiteDir,limiteCime, limiteBaixo);
		
		cout << area << " " << perimetro <<  endl;
	}
}