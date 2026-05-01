#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

map<int, vector<int> > mapa;
map<int, int> dist, dist2;
int ini, ttl;

int BFS(){
	int cont = 0;
	dist[ini] = 0;
	queue<int> q;
	q.push(ini);
	
	while(!q.empty() && dist[q.front()] <= ttl){
		int a = q.front();
		q.pop();
		cont++;
		
		for(int i=0; i<mapa[a].size(); i++){
			int k = mapa[a][i];
			if(dist[k] == -1){
				dist[k] = dist[a] + 1;
				q.push(k);
			}
		}
	}
	return mapa.size() - cont; 
}

int main(){
	int n, a, b, i, cases = 0;
	
	while(cin >> n && n){
		
		for(i=0; i<n; i++){
			cin >> a >> b;
			mapa[a].push_back(b);
			mapa[b].push_back(a);
			dist2[a] = dist2[b] = -1;
		}
		while(cin >> ini >> ttl && (ini || ttl)){
			cases++;
			for(auto it:dist2) dist[it.first] = -1;
			cout << "Case " << cases << ": " << BFS() << " nodes not reachable from node " << ini << " with TTL = " << ttl << ".\n";
		}
		dist2.clear();
		mapa.clear();
	}
}
