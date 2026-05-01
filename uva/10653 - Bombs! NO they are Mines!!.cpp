#include <iostream>
#include <queue>
using namespace std;

bool vis[1001][1001];
int n,m,r,c,dist[1001][1001];

int BFS(int i, int j){
	vis[i][j]=true;
	dist[i][j]=0;
	queue <pair<int,int> > q;
	q.push(make_pair(i,j));
	
	while(!q.empty() && dist[r][c]==-1){
		i = q.front().first;
		j = q.front().second;
		q.pop();
		
		if(i+1<n and !vis[i+1][j] and dist[i+1][j]==-1){
			dist[i+1][j]=dist[i][j]+1;
			q.push(make_pair(i+1,j));
		}
		if(j+1<m and !vis[i][j+1] and dist[i][j+1]==-1){
			dist[i][j+1]=dist[i][j]+1;
			q.push(make_pair(i,j+1));
		}
		if(j>=1 and !vis[i][j-1] and dist[i][j-1]==-1){
			dist[i][j-1]=dist[i][j]+1;
			q.push(make_pair(i,j-1));
		}
		if(i>=1 and !vis[i-1][j] and dist[i-1][j]==-1){
			dist[i-1][j]=dist[i][j]+1;
			q.push(make_pair(i-1,j));
		}
	}
	return dist[r][c];
}

int main(){
	int i,j,rb,qt;
	
	while(cin>>n>>m && (n || m)){
		cin>>rb;
		
		for(i=0; i<n; i++)
			for(j=0; j<m; j++){
				vis[i][j]=false;
				dist[i][j]=-1;
			}
		
		while(rb--){
			cin>>r>>qt;
			
			while(qt--){
				cin>>c;
				vis[r][c]=true;
			}
		}
		cin>>i>>j>>r>>c;
		cout<<BFS(i,j)<<endl;
	}
}
