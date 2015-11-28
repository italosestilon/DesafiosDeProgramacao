#include <iostream>
#include <map>
#include <stdio.h>
#include <string.h>

using namespace std;

char a[7], b[7];

int toDec(char c){
	if(c >= 65)
		return (c - 55);
	return c - '0';
}

char toChar(int i){
	if(i >= 10)
		return (i + 55);
	return i + '0';
}

void printSoma(int soma){

	if(soma > 35)
		printSoma(soma/36);

	printf("%c",toChar(soma%36) );
}


int main(){

	while(1){

		scanf("%s %s",a,b);

		if(!strcmp(a,"0") && !strcmp(a,"0")) break;

		int aD = 0, bD = 0;

		int aLenth = strlen(a);

		int bLenth = strlen(b);

		int potDez = 1;

		for(int i = aLenth-1; i >= 0; i--){

			aD += potDez * toDec(a[i]);

			potDez *= 36;
		}

		potDez = 1;

		for(int i = bLenth-1; i >= 0; i--){
		
			bD += potDez * toDec(b[i]);

			potDez *= 36;
		}
		int soma = aD + bD;

		//cout << aD << " " << bD << endl;

		printSoma(soma);

		cout << endl;
	}


}