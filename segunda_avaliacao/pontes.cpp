#include <cstdio>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <iostream>
#include <cstring>
#include <set>

#define INF 0x7ffffff
#define MAXVERTICES 10010
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

	for(int i = 0; i <= n+1; i++){
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



		vertice adj[MAXVERTICES];


		cin >> n >> m;

		

		for(int i = 0; i < m; i++){
			int x, y , t;

			cin >> x >> y >> t;

			adj[x].adj.push_back(make_pair(y,t));
			adj[y].adj.push_back(make_pair(x,t));
		}

		//cin >> s >> d;

		/*for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				cout << peso[i][j] << " ";
			}
			cout << endl;
		}*/

		dijkstra(0,adj);
		
		cout << dist[n+1];
		

		/*while(pai[d] != -1){
			//cout << "pai de " << d << endl;
			d = pai[d];
		}*/
	
} 