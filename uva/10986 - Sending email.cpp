#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> ii;
int ini, fim, dist[20001];
vector<ii> vec[20001];

int dijkstra(){
	dist[ini] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push({ini, 0});
	
	while(!pq.empty()){
		int pri = pq.top().first;
		pq.pop();
		
		for(int i = 0; i < vec[pri].size(); i++){
			ii p = vec[pri][i];
			
			if(dist[p.first] > dist[pri] + p.second){
				dist[p.first] = dist[pri] + p.second;
				pq.push({p.first, dist[p.first]});
			} 
		}
	}
	return dist[fim];
}

int main(){
	int cases, a, i, j, n, m, w;
	cin >> cases;
	
	for(a = 1; a <= cases; a++){
		cin >> n >> m >> ini >> fim;
		
		while(m--){
			cin >> i >> j >> w;
			vec[i].push_back({j, w});
			vec[j].push_back({i, w});
		}
		for(i = 0; i < n; i++) dist[i] = 2147483647;
		cout << "Case #" << a << ": " ;
		i = dijkstra();
		if(i == 2147483647) cout << "unreachable\n";
		else cout << i << endl;
		for(i = 0; i < n; i++) vec[i].clear();
	}
}
