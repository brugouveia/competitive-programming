#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

map<char,string> m = {{'0',"0000"},{'1',"0001"},{'2',"0010"},{'3',"0011"},{'4',"0100"},
                    {'5',"0101"},{'6',"0110"},{'7',"0111"},{'8',"1000"},{'9',"1001"},
                    {'a',"1010"},{'b',"1011"},{'c',"1100"},{'d',"1101"},{'e',"1110"},{'f',"1111"}};
map<int, string> type = {{1, "A"},{0, "W"},{2, "K"},{3, "J"},{4, "S"},{5, "D"}};
int row, col, qtb;
bool grid_end;
string matsup[501];

bool isValid(int i, int j){
	return i > -1 && i < row && j > -1 && j < col * 4;
}

void dfs2(int i, int j){
	if(!isValid(i, j)){ grid_end = true; return; }
	if(matsup[i][j] != '0') return;
	
	matsup[i][j] = '2';
	
	dfs2(i+1, j);
	dfs2(i-1, j);
	dfs2(i, j+1);
	dfs2(i, j-1);
}

void dfs1(int i, int j){
	if(!isValid(i, j) || matsup[i][j] == '2') return;
	if(matsup[i][j] == '0'){
		dfs2(i, j);
		if(!grid_end) qtb++;
		else grid_end = false;
		return;
	}
	matsup[i][j] = '2';
	
	dfs1(i+1, j);
	dfs1(i-1, j);
	dfs1(i, j+1);
	dfs1(i, j-1);
}

int main(){
	int i, j, cases = 1;
	char c;
	
	while(cin >> row >> col && (row || col)){
		string image;
		grid_end = false;
		
		for(i = 0; i < row; i++){
			for(j = 0; j < col; j++){
				cin >> c;
				matsup[i] += m[c];
			}
		}
		for(i = 0; i < row; i++){
			for(j = 0; j < col * 4; j++){
				if(matsup[i][j] == '1'){
					qtb = 0;
					dfs1(i, j);
					image += type[qtb];
				}
			}
		}
		sort(image.begin(), image.end());
		cout << "Case " << cases++ << ": " << image << endl;
		for(i = 0; i < row; i++) matsup[i] = "";
	}
}
