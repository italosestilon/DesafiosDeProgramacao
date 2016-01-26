#include <iostream>

using namespace std;

int main(){
	int x1, y1, x2, y2, n, qtd = 0, teste = 0;

	while(true){
		qtd = 0;
		teste++;

		cin >> x1 >> y1 >> x2 >> y2 >> n;

		if(x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0)
			break;

		for(int i = 0; i < n; i++){
			int x, y;

			cin >> x >> y;

			if(x >= x1 && x <= x2 && y >= y2 && y <= y1)
				qtd++;
		}
 
		cout << "Teste " << teste << endl;
		cout << qtd << endl << endl;
	}

}