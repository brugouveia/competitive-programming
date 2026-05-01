#include <iostream>

using namespace std;

char mat[26][26];
bool used[26][26];
int n;

void floodfill(int i, int j){
	used[i][j]=true;
	
	if(j<n-1 and !used[i][j+1] and mat[i][j+1]) floodfill(i,j+1);
	if(i<n-1 and !used[i+1][j] and mat[i+1][j]) floodfill(i+1,j); 
	if(j>0 and !used[i][j-1] and mat[i][j-1]) floodfill(i,j-1);
	if(i>0 and !used[i-1][j] and mat[i-1][j]) floodfill(i-1,j);
	if(i>0 and j>0 and !used[i-1][j-1] and mat[i-1][j-1]) floodfill(i-1,j-1);
	if(i<n-1 and j<n-1 and !used[i+1][j+1] and mat[i+1][j+1]) floodfill(i+1,j+1);
	if(i<n-1 and j>0 and !used[i+1][j-1] and mat[i+1][j-1]) floodfill(i+1,j-1);
	if(i>0 and j<n-1 and !used[i-1][j+1] and mat[i-1][j+1]) floodfill(i-1,j+1);
}

int main(){
	int i,j,a=0;
	
	while(cin>>n){
		a++;
		int cont=0;
		
		for(i=0; i<n; i++)
			for(j=0; j<n; j++){
				cin>>mat[i][j];
				if(mat[i][j]=='0') used[i][j]=1;
				else used[i][j]=0;
			}
		
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				if(!used[i][j]){
					cont++;
					floodfill(i,j);
				}
		cout<<"Image number "<<a<<" contains "<<cont<<" war eagles.\n";
	}
}
