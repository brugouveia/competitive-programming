#include <iostream>
#include <queue>
#include <map>
using namespace std;

int mat[101][101];
map <string, int> even_odd;
int row, col, n, m;

bool canVisit(int i, int j){
	return i < row && j < col && i > -1 && j > -1;
}

void BFS(){
	int x[8] = { m, n, n, m,-m,-n,-n,-m};
	int y[8] = { n, m,-m,-n, n, m,-m,-n};
	mat[0][0] = 1;
	queue< pair<int, int> > q;
	q.push({0,0});
	int i, j, k, u, v;
	
	while(!q.empty()){
		map<pair<int, int>, bool> Using;
		int cont = 0;
		i = q.front().first;
		j = q.front().second;
		q.pop();
		
		for(k = 0; k < 8; k++){
			u = i + x[k];
			v = j + y[k];
			
			if(canVisit(u, v) && mat[u][v] != -1 && !Using[{u, v}]){
				cont++;
				Using[{u, v}] = true;
				if(!mat[u][v]){
					mat[u][v] = 1;
					q.push({u, v});
				}
			}
		}
		if(cont%2 == 0) even_odd["even"]++;
		else even_odd["odd"]++;
		Using.clear();
	}
}

int main(){
	int cases, w, u , v;
	cin >> cases;
	
	for(int i = 1; i <= cases; i++){
		even_odd.clear();
		cin >> row >> col >> m >> n >> w;
		
		for(u = 0; u < row; u++)
			for(v = 0; v < col; v++)  
				mat[u][v] = 0;
					
		while(w--){
			cin >> u >> v;
			mat[u][v] = -1;
		}
		BFS();
		cout << "Case " << i << ": " << even_odd["even"] << ' ' << even_odd["odd"] << endl;
	}
}
