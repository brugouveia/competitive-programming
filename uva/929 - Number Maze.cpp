#include <iostream>
#include <queue>
#include <climits>

using namespace std;

int n, m, mat[1000][1000], dist[1000][1000];
typedef pair<int, pair<int,int> > iii;
int x[4] = {1,-1, 0, 0};
int y[4] = {0, 0,-1, 1};

void dijkstra(){
	// {dist[i][j], {i,j}}
	priority_queue<iii, vector<iii>, greater<iii> > pq;
	pq.push({dist[0][0] = mat[0][0], {0,0}});
	
	while(pq.size()){
		int a = pq.top().second.first;  // i
		int b = pq.top().second.second; // j
		int c = pq.top().first;       // dist
		pq.pop();
		
		for(int i = 0; i < 4; i++){
			int k = a + x[i];
			int l = b + y[i];
			
			if(k < n && k >= 0 && l >=0 && l < m){
				if(dist[k][l] > c + mat[k][l]){
					dist[k][l] = c + mat[k][l];
					pq.push({dist[k][l], {k,l}});
				}
			}
		}
	}
	printf("%i\n", dist[n-1][m-1]);
}

int main(){
	int t;
	scanf("%i", &t);
	
	while(t--){
		scanf("%i %i", &n, &m);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				scanf("%i", &mat[i][j]);
				dist[i][j] = INT_MAX;
			}
		}
		dijkstra();
	}
}
