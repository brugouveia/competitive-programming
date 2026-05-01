#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, cor[201];
vector<int> adj[201];

string bfs(){
	queue<int> q;
	cor[0] = 0;
	q.push(0);
	
	while(!q.empty()){
		int u = q.front();
		q.pop();
		
		for(int i = 0; i < adj[u].size(); i++){
			int k = adj[u][i];
			
			if(cor[k] == -1){
				cor[k] = 1 - cor[u];
				q.push(k);
			}
			else if(cor[k] == cor[u]) return "NOT BICOLORABLE.\n";
		}
	}
	return "BICOLORABLE.\n";
}

int main(){
	while(cin >> n >> m && n){
		int a, b;
		
		while(m--){
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for(a = 0; a < n; a++) cor[a] = -1;
		cout << bfs();
		for(a = 0; a < n; a++) adj[a].clear();
	}
}
