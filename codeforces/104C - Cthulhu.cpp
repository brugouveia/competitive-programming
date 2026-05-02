#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> vec[], vector<bool>& vis, int u) {
    vis[u] = true;

    for (int v : vec[u]) {
        if (!vis[v]) {
            dfs(vec, vis, v);
        }
    }
}

int main() {
    int n, m, a, b;
    cin >> n >> m;

    vector<int> vec[n + 1];
    vector<bool> vis(n + 1, 0);

    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    dfs(vec, vis, 1);

    bool ok = true;
    for (int i = 2; i <= n && ok; i++) {
        if (!vis[i]) {
            ok = false;
        }
    }

    if (n == m && ok) {
        cout << "FHTAGN!\n";
    }
    else {
        cout << "NO\n";
    }
}
