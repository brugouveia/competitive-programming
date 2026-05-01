#include <iostream>
#include <queue>
using namespace std;

int dist[10001], vet[10001];

int BFS(int ini, int fim, int r){
	dist[ini] = 0;
	queue<int> q;
	q.push(ini);
    
	while(!q.empty() && dist[fim] == -1){
		int k = q.front();
		q.pop();
		
		for(int i = 0; i < r; i++){
			int a = k + vet[i];
			
			if(a >= 10000) a -= 10000; 
			
			if(dist[a] == -1){
				q.push(a);
				dist[a] = dist[k] + 1;
			}
		}
	}
	return dist[fim];
}

int main(){
	int ini, fim, r, cases = 0;
	
	while(cin >> ini >> fim >> r && (ini || fim || r)){
		for(int i = 0; i <= 10000; i++) dist[i] = -1;
		cases++;
		int a;
		
		for(int i = 0; i < r; i++){
			cin >> a;
			vet[i] = a;
		}
		a = BFS(ini, fim, r);
		cout << "Case " << cases << ": ";
		if(a > -1) cout << a << endl;
		else cout << "Permanently Locked\n";
	}
}
