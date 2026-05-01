#include <iostream>
#include <map>
using namespace std;

bool used[50][50];
char mat[50][50];
int n, m;
map<char,int> mapa;

bool isSafe(int i, int j){
	return mat[i+1][j] != 'T' && mat[i-1][j] != 'T' && mat[i][j+1] != 'T' && mat[i][j-1] != 'T';
}

void DFS(int i, int j){
	if(i < 1 || j < 1 || i > n-2 || j > m-2 || mat[i][j] == '#' || used[i][j]) return;
	
	mapa[mat[i][j]]++;
	used[i][j] = true;
	
	if(isSafe(i, j)){
		DFS(i+1, j);
		DFS(i-1, j);
		DFS(i, j+1);
		DFS(i, j-1);
	}
}

int main(){
	while(cin >> m >> n){
		int i, j, in, jn;
		
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++){
				cin >> mat[i][j];
				used[i][j] = false;
				if(mat[i][j] == 'P') in = i, jn = j;
			}
		
		DFS(in, jn);
		cout << mapa['G'] << endl;
		mapa.clear();
	}
}
