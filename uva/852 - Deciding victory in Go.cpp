#include <iostream>

using namespace std;

char mat[9][9], ponto;
int cont;

void dfs(int i, int j){
	if(i < 0 || j < 0 || i > 8 || j > 8 || mat[i][j] == '1') return;
	
	if(mat[i][j] != '.'){
		if(ponto != '2'){
			if(ponto != mat[i][j] && ponto != '.') ponto = '2';
			else ponto = mat[i][j];
		}
		return;
	}
	cont++;
	mat[i][j] = '1';
	dfs(i+1, j);
	dfs(i-1, j);
	dfs(i, j+1);
	dfs(i, j-1);
}

int main(){
	int cases, i, j;
	cin >> cases;
	
	while(cases--){
		int black = 0, white = 0;
		
		for(i = 0; i < 9; i++)
			for(j = 0; j < 9; j++)
				cin >> mat[i][j];
				
		for(i = 0; i < 9; i++){
			for(j = 0; j < 9; j++){
				if(mat[i][j] == '.'){
					cont = 0;
					ponto = '.';
					dfs(i, j);
					if(ponto == 'O') white += cont;
					else if(ponto == 'X') black += cont;
				}
				else if(mat[i][j] == 'O') white++;
				else if(mat[i][j] == 'X') black++;
			}
		}
		cout << "Black " << black << " White " << white << endl;
	}
}
