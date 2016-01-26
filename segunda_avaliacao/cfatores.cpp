#include <iostream>
#include <cmath>
using namespace std;

int fatoracao(int n){

	int limite = sqrt(n);

	int i = 2, countPrimos  = 0;

	while(n > 1){

		int count = 0;

		while(n % i == 0){
			count++;
			n = n/i;
		}

		if(count > 0) countPrimos++;

		//limite = sqrt(n);

		i++;
	}

	return countPrimos;

}

int main(){

	int n;

	while(1){
		cin >> n;

		if(n == 0) break;

		cout << n << " : " << fatoracao(n) << endl;
	}
}