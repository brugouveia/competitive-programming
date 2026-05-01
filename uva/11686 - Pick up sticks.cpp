#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> vec[1000000];
int vis[1000000], possible;
stack<int> p;

void dfs(int u){
	vis[u] = 1;
	
	for(int i = 0; i < vec[u].size(); i++){
		int k = vec[u][i];
		if(!vis[k]) dfs(k);
		else if(vis[k] == 1) possible = 0;
	}
	vis[u] = 2;
	p.push(u);
	vec[u].clear();
}

int main(){
	int n, m, i, j;
	
	while(cin >> n >> m && (n || m)){
		for(i = 1; i <= n; i++) vis[i] = 0;
		possible = 1;
		
		while(m--){
			cin >> i >> j;
			vec[i].push_back(j);
		}
		
		for(i = 1; i <= n; i++)
			if(!vis[i])
				dfs(i);
				
		if(possible){
			while(!p.empty()){
				cout << p.top() << endl;
				p.pop();
			}
		}
		else{
			cout << "IMPOSSIBLE\n";
			while(!p.empty()) p.pop();
		}
	}
}
