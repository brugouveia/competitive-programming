#include <iostream>
using namespace std;

int n, m, cell;
bool used[25][25];
string mat[25];

void ff(int i, int j){
	if( i < 0 || j < 0 || i >= n || j >= m || mat[i][j] == '0' || used[i][j] ) return;
	
	used[i][j] = true;
	cell++;
	
	ff( i, j+1);
	ff( i+1, j); 
	ff( i, j-1);
	ff( i-1, j);
	ff( i-1, j-1);
	ff( i+1, j+1);
	ff( i+1, j-1);
	ff( i-1, j+1);
}

int main(){
	int cases, i, j;
	string str;
	cin >> cases;
	cin.ignore();
	cin.ignore();
	
	while(cases--){
		int bigger = i = 0;
		
		while(getline(cin,str) && str != ""){
			mat[i] = str;
			i++;
		}
		n = i;
		m = mat[0].size();
		
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				used[i][j] = false;
				
		for(i = 0; i < n; i++)
			for(j = 0; j < m; j++)
				if(!used[i][j]){
					cell = 0;
					ff(i, j);
					if(cell > bigger) bigger = cell;
				}
			
		cout << bigger << endl;
		if(cases) cout << endl;	
	}
}
