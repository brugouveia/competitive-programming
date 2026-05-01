#include <iostream>
#include <queue>

using namespace std;

string tabuleiro[101];
int n, m, ia, ib, ja, jb, dist[101][101];
int x[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
int y[8] = {-1, 0, 1, 1,-1, 1,-1, 0};

bool isSafe(int i, int j){
	return i > -1 && j > -1 && i < m && j < n && tabuleiro[i][j] != 'Z';
}

int BFS(){	
	dist[ia][ja] = 0;
	queue <pair<int,int> > q;
	q.push({ia,ja});
	
	while(!q.empty() && dist[ib][jb] == -1){
		int i = q.front().first;
		int j = q.front().second;
		q.pop();
		
		for(int k = 0; k < 8; k++){
			int a = x[k] + i, b = y[k] + j;
			if(isSafe(a, b) && tabuleiro[a][b] != 'X' && dist[a][b] == -1){
				q.push({a,b});
				dist[a][b] = dist[i][j] + 1;
			}
		}
	}
	return dist[ib][jb];
}

int main(){
	int x[8] = { 1, 2, 1, 2,-2,-1,-2,-1};
	int y[8] = {-2,-1, 2, 1, 1, 2,-1,-2};
	int t, i, j;
	cin >> t;
	
	while(t--){
		cin >> m >> n;
		
		for(i = 0; i < m; i++)
			cin >> tabuleiro[i];
		
		for(i = 0; i < m; i++){
			for(j = 0; j < n; j++){
				dist[i][j] = -1;
				if(tabuleiro[i][j] == 'Z'){
					for(int k = 0; k < 8; k++){
						int a = x[k] + i, b = y[k] + j;
						if(isSafe(a, b) && tabuleiro[a][b] != 'B' && tabuleiro[a][b] != 'A') tabuleiro[a][b] = 'X';
					}
				}
				else if(tabuleiro[i][j] == 'A'){ ia = i; ja = j; }
				else if(tabuleiro[i][j] == 'B'){ ib = i; jb = j; }
			}
		}
		int caminho = BFS();
		if(caminho < 0) cout << "King Peter, you can't go now!\n";
		else cout << "Minimal possible length of a trip is " << caminho << endl;
	}
}
