#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int farthestNode;

void dfs(vector<int> vec[], vector<int>& dist, int u) {
    if (dist[u] > dist[farthestNode])
        farthestNode = u;

    for (int v : vec[u]) {
        if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            dfs(vec, dist, v);
        }
    }
}

int main() {
    int n, m, a, b;
    cin >> n;

    vector<int> vec[n + 1];
    vector<int> distA(n + 1, -1);
    vector<int> distB(n + 1, -1);

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    farthestNode = 1;

    distA[farthestNode] = 0;
    dfs(vec, distA, farthestNode);

    fill(distA.begin(), distA.end(), -1);

    distA[farthestNode] = 0;
    dfs(vec, distA, farthestNode);

    distB[farthestNode] = 0;
    dfs(vec, distB, farthestNode);

    for (int i = 1; i <= n; i++) {
        cout << max(distA[i], distB[i]) << " ";
    }
}
