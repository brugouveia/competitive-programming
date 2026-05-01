#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> vec[2501];
int dist[2501];

void BFS(int inicio) {
    queue<int> q;
	dist[inicio] = 0;
	q.push(inicio);
	int qtd[2501] = {};
	
	while(q.size()) {
	    int u = q.front();
	    q.pop();

	    for(int k : vec[u]) {
	        if(dist[k] == -1) {
	            dist[k] = dist[u] + 1;
	            q.push(k);
	            qtd[dist[k]]++;
	        }
	    }
	}
	
	int maximum = 0, first = 0;
    for (int i = 1; i < 2501; ++i) {
        if (qtd[i] > maximum) {
            maximum = qtd[i];
            first = i;
        }
    }
	
	if(maximum == 0) cout << "0\n";
	else cout << maximum << ' ' << first << "\n";
}

int main() {
    int n, m, x, t;
    cin >> n;
    
    for(int i = 0; i < n; i++) {
        cin >> m;
        
        while(m--) {
            cin >> x;
            vec[i].push_back(x);
        }
    }
    
    cin >> t;
    while(t--) {
        cin >> x;
        for(int i = 0; i < n; i++) dist[i] = -1;
        BFS(x);
    }
}
