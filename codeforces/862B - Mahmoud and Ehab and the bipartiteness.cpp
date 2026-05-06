#include <iostream>
#include <vector>
using namespace std;

int sum[2] = {0, 0};

void dfs(vector<int> vec[], vector<int> &color, int u) {
    for (int v : vec[u]) {
        if (color[v] == -1) {
            color[v] = 1 - color[u];
            sum[color[v]]++;
            dfs(vec, color, v);
        }
    }
}

int main() {
    int n, a, b;
    cin >> n;

    vector<int> vec[n + 1];
    vector<int> color(n + 1, -1);

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    color[1] = 0;
    sum[0]++;
    dfs(vec, color, 1);

    cout << (1ll * sum[0] * sum[1]) - (n - 1) << endl;
}
