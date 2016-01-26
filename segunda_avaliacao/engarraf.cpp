#include <cstdio>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <iostream>
#include <cstring>
#include <set>

#define INF 200000000
#define MAXVERTICES 102
#define MAXARESTAS 10000

using namespace std;

typedef struct{
	list<pair<int,int> > adj;
}vertice;

int dist[MAXVERTICES];
int pai[MAXVERTICES];
int cor[MAXVERTICES];
int n, m;


void dijkstra(int ori, vertice ladj[MAXVERTICES]){
	
	set<pair<int, int> > td;

	td.insert(make_pair(0, ori));

	


	for(int i = 1; i <= n; i++){
		dist[i] = INF;
	}
	dist[ori] = 0;

	while(!td.empty()){
		//cout << "haha" << endl;
		int vert = td.begin()->second;

		td.erase(td.begin());

		for(list<pair<int,int> >::iterator it = ladj[vert].adj.begin(); it != ladj[vert].adj.end(); it++){
			
			//cout << "vert " << vert << " adj " << it->first <<  " dist " << dist[it->first] << endl;
			 
			if( dist[it->first] > dist[vert] + it->second ){

				if( dist[it->first] != INF )
					td.erase(td.find(make_pair(dist[it->first], it->first)));

				dist[it->first] = dist[vert] + it->second;
				td.insert(make_pair(dist[it->first], it->first));

			}
		}
		
	}
}


int main(){
	int s, d;

	while(true){

		vertice adj[MAXVERTICES];


		cin >> n >> m;

		if(n == 0 && m == 0) break;

		for(int i = 0; i < m; i++){
			int x, y , t;

			cin >> x >> y >> t;

			adj[x].adj.push_back(make_pair(y,t));
		}

		cin >> s >> d;

		/*for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cout << peso[i][j] << " ";
			}
			cout << endl;
		}*/

		dijkstra(s,adj);

		int distancia = dist[d];

		if(distancia != INF)

			cout << dist[d] << endl;
		else
			cout << -1 << endl;

		/*while(pai[d] != -1){
			//cout << "pai de " << d << endl;
			d = pai[d];
		}
	}
} 