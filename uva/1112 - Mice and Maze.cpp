#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int,int> ii;
vector<ii> vec[101];
int e, n, t;

int dijkstra(){
	int i, dist[101], cont = 0;
	for(i = 1; i <= n; i++) dist[i] = INT_MAX;
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push({e, 0});
	dist[e] = 0;
	
	while(!pq.empty()){
		int pri = pq.top().first;
		pq.pop();
		
		for(i = 0; i < vec[pri].size(); i++){
			ii p = vec[pri][i];
			
			if(dist[p.first] > dist[pri] + p.second){
				dist[p.first] = dist[pri] + p.second;
				pq.push({p.first, dist[p.first]});
			}
		}
	}
	for(i = 1; i <= n; i++){
		if(dist[i] <= t) cont++;
		vec[i].clear();
	}
	return cont;
}

int main(){
	int cases, i, j, p;
	cin >> cases;
	
	while(cases--){
		int m;
		cin >> n >> e >> t >> m;
		
		while(m--){
			cin >> i >> j >> p;
			vec[j].push_back({i, p});
		}
		cout << dijkstra() << endl;
		if(cases) cout << endl;
	}
}
