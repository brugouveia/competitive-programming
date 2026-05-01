#include <iostream>
#include <map>
 
using namespace std;
 
int main() {
    int t, n, max, num;
    
    cin >> t;
    
    while (t--) {
        cin >> n;
        
        map<int, int> mapa; // num => qtd
        max = n * (n - 1);
        bool bigger = false;
        
        for(int i = 0; i < n * n; i++) {
            cin >> num;
            mapa[num]++;
            
            if (mapa[num] > max) {
              bigger = true;
            }
        }
        
        if (bigger) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
