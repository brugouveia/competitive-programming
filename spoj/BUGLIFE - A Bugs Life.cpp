#include <iostream>
#include <queue>
using namespace std;

bool bipartite(vector<int> vec[], vector<int>& color, int u) {
    queue<int> q;
    q.push(u);
    color[u] = 0;

    while (q.size()) {
        int front = q.front();
        q.pop();

        for (int v : vec[front]) {
            if (color[v] == -1) {
                color[v] = 1 - color[front];
                q.push(v);
            }
            else if (color[v] == color[front]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    int t, n, m, a, b;
    cin >> t;

    for (int c = 1; c <= t; c++) {
        cin >> n >> m;

        vector<int> vec[n + 1];
        vector<int> color(n + 1, -1);

        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            vec[a].push_back(b);
            vec[b].push_back(a);
        }

        bool isBipartite = true;
        for (int i = 1; i <= n && isBipartite; i++) {
            if (color[i] == -1)
                isBipartite = bipartite(vec, color, i);
        }

        if (isBipartite) {
            cout << "Scenario #" << c << ":\nNo suspicious bugs found!\n";
        }
        else {
            cout << "Scenario #" << c << ":\nSuspicious bugs found!\n";
        }
    }
}
