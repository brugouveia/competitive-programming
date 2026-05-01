#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int main(){
	string ini,fim,str;
	int n, i, j;
	cin>>n;
	
	while(n--){
		map <int, vector<string> > mapa;
		map <string, int> dist;
		
		while(cin>>str && (str!="*"))
			mapa[str.size()].push_back(str);
			
		cin.ignore();
		while(getline(cin,fim) && fim!=""){
			str="";
			for(i=0; i<fim.size(); i++){
				if(fim[i]==' '){
					ini = str;
					str = "";
				}
				else str+=fim[i];
			}
			fim = str;
			
			queue <string> q;
			q.push(ini);
			dist[ini]=1;
			
			while(dist[fim]==0){
				str = q.front();
				q.pop();
				
				for(i=0; i<mapa[str.size()].size(); i++){ 
					string a = mapa[str.size()][i];
					
					if(!dist[a]){
						int dif = 0;
						
						for(j=0; j<a.size() && dif<2; j++)
							if(str[j]!=a[j]) dif++;
						
						if(dif == 1){
							q.push(a);
							dist[a] = dist[str] + 1;
						}
					}
				}
			}
			cout << ini <<' '<< fim <<' '<< dist[fim]-1 << "\n";
			dist.clear();
		}
		if(n) cout << endl;
	}
}
