#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

vector<pair<int,int> > v;
int m[502][502],k,l;

int custo(){

    for(int i = 0; i < 502; i++)
    	for(int j = 0; j < 502; j++)
        	m[i][j]=1<<29;

	for(int i = 0; i < k; i++){
		m[i][0] = (i+1)*v[i].second;
	}

	for(int j = 1; j < l; j++){
		for(int i = j; i < k; i++){
			int menor = 1 << 29;
			for(int o = 1; o <= i; o++){
				menor = min(menor, m[i-o][j-1]+ o*v[i].second);
			}
			m[i][j] = menor;
		}
	}

	return m[k-1][l-1];
}

int main(){

	while(1){

		cin >> k >> l;

		v.clear();

		if(not cin) break;
		if(!k && !l) break;

		for (int i = 0; i < k; i++)
		{
			int d,p;
			cin >> d >> p;

			v.push_back(make_pair(d,p));
		}
		sort(v.begin(),v.end());
		cout << custo() << endl;
	}

}

