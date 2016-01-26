#include <cstdio>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <iostream>
#include <cstring>
#include <set>
#include <algorithm>

#define INF 200000000
#define MAXVERTICES 1004
#define MAXARESTAS 10002

using namespace std;

typedef struct{
	int incio;
	int fim;
	int peso;
}aresta;

int pai[MAXVERTICES],rank[MAXVERTICES];

bool cmp(aresta a, aresta b){
	return a.peso < b.peso;
}

void fazer_conjunto(int v){
	pai[v] = v;
	rank[v] = 0;
}

int encontra(int v){
	if(pai[v] == v)
		return v;
	pai[v]=encontra(pai[v]);

	return pai[v];
}

void uniao(int u, int v){
	int raizU = encontra(u);
	int raizV = encontra(v);

	if(raizV != raizU){
		if(rank[raizU] < rank[raizV]){
			pai[raizU] = raizV;
		}else{
			if(rank[raizU] > rank[raizV])
				pai[raizV] = raizU;
			else{
				pai[raizV] = raizU;
				rank[raizU]++;
			}
		}
	}
}

int main(){
	int n, m, contador, pesoTotal;

	vector<aresta> ar;

	cin >> n >> m;

	for(int i = 0; i < m; i++){
		int u,v,p;

		cin >> u >> v >> p;
		aresta a;

		a.incio = u;
		a.fim = v;
		a.peso = p;
		ar.push_back(a);
		
	}

	sort(ar.begin(), ar.end(), cmp);

	for(int i = 0; i < n ; i++){
		fazer_conjunto(i);
	}
	contador = 0;
	pesoTotal = 0;

	for(int i = 0; i < ar.size() && contador < n-1; i++){
		if(encontra(ar[i].incio) != encontra(ar[i].fim)){
			contador++;
			uniao(ar[i].incio,ar[i].fim);
			pesoTotal += ar[i].peso;
		}
	}

	cout << pesoTotal;

	return 0;
}