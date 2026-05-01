#include <iostream>
#include <vector>
#include <map>
using namespace std;

int cont;
map <int,bool> used;

void DFS(int u, vector <int> vec[10001]){
	used[u] = true;
	cont++;
	
	for(int i = 0; i < vec[u].size(); i++){
		int k = vec[u][i];
		if(!used[k]) DFS(k, vec);
	}
}

int main(){
	int cases, n, m, l, i, a, b;
	cin >> cases;
	
	while(cases--){
	    vector <int> domino[10001];
		cont = 0;
		cin >> n >> m >> l; 
		
		for(i = 0; i < m; i++){
			cin >> a >> b;
			domino[a].push_back(b);
		}
		
		for(i = 0; i < l; i++){
			cin >> a;
			if(!used[a]) DFS(a, domino);
		}
		used.clear();
		cout << cont << endl;
	}
}
