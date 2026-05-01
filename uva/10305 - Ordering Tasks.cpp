#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> vec[101];
bool vis[101];
stack<int> p;

void dfs(int u){
	vis[u] = 1;
	
	for(int i = 0; i < vec[u].size(); i++){
		int k = vec[u][i];
		if(!vis[k]) dfs(k);
	}
	p.push(u);
}

int main(){
	int n, m, i, j;
	
	while(cin >> n >> m && (n || m)){
		for(i = 1; i <= n; i++) vis[i] = 0;
		
		while(m--){
			cin >> i >> j;
			vec[i].push_back(j);
		}
		
		for(i = 1; i <= n; i++)
			if(!vis[i]) dfs(i);
	
		while(!p.empty()){
			cout << p.top();
			p.pop();
			if(p.size()) cout << ' ';
		}
		cout << endl;
		for(i = 1; i <= n; i++) vec[i].clear();
	}
}
