#include <iostream>
#include <queue>

using namespace std;

int n,m;

int quadro[53][53];

bool visitado[53][53][10];

int X[] = {0,1,0, 0,-1};
int Y[] = {0,0,1,-1, 0};

typedef struct estado
{
	int px;
	int py;
	int turno;

}Estado;


bool movimentoValido(int x, int y, int altura, int turno){

	if(x >= 1 && y >= 1 && x <= n && y <= m && (quadro[x][y]+turno)%10 <= ((altura+turno)%10)+1){
		if(!visitado[x][y][((turno+1)%10)])
			return true;
		else
			return false;
	}
	else
		return false;
}

int bfs(Estado origem){

	queue<Estado> fila;
	fila.push(origem);

	while(!fila.empty()){

		Estado estado = fila.front();
		fila.pop();

		if(estado.px == n && estado.py == m){

			return estado.turno;
		}

		int px = estado.px;
		int py = estado.py;

		for(int dir = 0; dir < 5; dir++){

			if(movimentoValido(px+X[dir],py+Y[dir],quadro[px][py],estado.turno)){
				Estado novo;
				novo.px = px+X[dir];
				novo.py = py+Y[dir];
				novo.turno = estado.turno + 1;
				fila.push(novo);
				visitado[novo.px][novo.py][novo.turno % 10] = true;

				//cout << novo.px << " " << novo.py << " " << novo.turno << endl;
			}
		}
	}
	return -1;
}

int main(){

	cin >> n >> m;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> quadro[i][j];
			for(int k = 0; k < 9; k++){
				visitado[i][j][k] = false;
			}
		}
	}

	Estado origem;
	origem.px = 1;
	origem.py = 1;
	origem.turno = 0;

	cout << bfs(origem);
}