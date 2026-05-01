#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> vec[201];
int cor[201];

int bicoloring(int inicio) {
    if(cor[inicio] != -1) {
        return 0;
    }
    
    queue<int> q;
	cor[inicio] = 0;
	q.push(inicio);
	int qtdCor[2] = {0, 0};
	
	while(q.size()) {
	    int u = q.front();
	    q.pop();
	    qtdCor[cor[u] % 2]++;
	    
	    for(int i = 0; i < vec[u].size(); i++) {
	        int k = vec[u][i];
	        
	        if(cor[k] == -1) {
	            cor[k] = 1 - cor[u];
	            q.push(k);
	        } else if(cor[k] == cor[u]) {
	            return -1;
	        }
	    }
	}
	
    if(!qtdCor[0] && !qtdCor[1]) return 1;
    if(!qtdCor[0] || !qtdCor[1]) return max(qtdCor[0], qtdCor[1]);
    return min(qtdCor[0], qtdCor[1]);
}

int main() {
    int t, n, m, x, y;
    cin >> t;
    
    while(t--) {
        cin >> n >> m;
        
        for(int i = 0; i < m; i++) {
            cin >> x >> y;
            vec[x].push_back(y);
            vec[y].push_back(x);
        }
        
        for(int i = 0; i < n; i++) cor[i] = -1;
        
        int qtd = 0;
        
        for(int i = 0; i < n; i++) {
            int res = bicoloring(i);
            if (res == -1) {
                qtd = -1;
                break;
            }
            qtd += res;
        }
        
        cout << qtd << "\n";
        
        for(int i = 0; i < n; i++) vec[i].clear();
    }

    return 0;
}
