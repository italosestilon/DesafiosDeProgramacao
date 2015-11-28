#include <iostream>
#include <stdio.h>

using namespace std;

char pre[54],em[54];

int n;

void pos(int inicio, int fim){

	if(inicio > fim) return;
	if(inicio == fim){
		cout << em[inicio];
		return;
	}

	int raiz = -1;

	for(int i = 0; i < n; i++){
		for(int j = inicio; j <= fim; j++){
			if(pre[i] == em[j]){
				
				raiz = j;
				break;
			}
		}
		if(raiz != -1) break;
	}

	pos(inicio, raiz - 1);
	pos(raiz + 1, fim);
	cout << em[raiz];
}

int main(){

	int casos;

	cin >> casos;

	for(int c = 0; c < casos; c++){

		cin >> n;

		scanf("%s %s",pre,em);

		pos(0,n-1);

		cout << endl;

	}
}