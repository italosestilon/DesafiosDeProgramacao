#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int chaves[22],m,d;

int minQtdSubs2(){

	int qtdSubconjuntos = (1 << d) - 1;
	int menorQtd = 1<<22;

	while(qtdSubconjuntos >= 0){
		unsigned int c = 0;

		for (int i = 0; i < d; ++i)
			if(qtdSubconjuntos & 1 << i){
				c |= chaves[i];
			}

		if(__builtin_popcount(c) >= m && __builtin_popcount(qtdSubconjuntos) < menorQtd){
			
			menorQtd = __builtin_popcount(qtdSubconjuntos);
		}

		qtdSubconjuntos--;
	}
	return menorQtd;
}

int main(){

	int c;

	cin >> c;

	while(c--){
		cin >> m >> d;

		memset(chaves,0,sizeof chaves);
		for(int i = 0; i < d; i++){

			int qtd;

			cin >> qtd;


			for(int j = 0; j < qtd; j++){

				int chave;

				cin >> chave;

				chaves[i] |= 1 << chave;

			}
		}

		int qtd = minQtdSubs2();
		
		if(qtd == 1<<22){
			cout << "Desastre!" << endl;
		}else{
			cout << qtd << endl;
		}
	}
}