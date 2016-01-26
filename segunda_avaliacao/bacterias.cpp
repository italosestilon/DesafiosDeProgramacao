#include <cmath>
#include <cstdio>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <iostream>
#include <cstring>
#include <set>

using namespace std;

int main(){

	int n, d, c;

	cin >> n;

	double melhor = 0;

	int numeroDoMelhor = 0;

	for(int i = 0; i < n; i++){
		cin >> d >> c;

		double atual = c * log(d);

		if(atual > melhor){
			melhor = atual;
			//cout << melhor << endl;
			numeroDoMelhor = i;
		}

	}

	cout << numeroDoMelhor;
}