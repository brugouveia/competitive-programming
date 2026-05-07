#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

bool endDFS = false;
int sumTotal = 0, sumRight = 0;

void dfs(vector<pii> vec[], int u, int parent) {
    if (u == 1 && parent != -1) {
        endDFS = true;
        return;
    }

    for (auto [v, w] : vec[u]) {
        if (v != parent && !endDFS) {
            sumRight += w;
            dfs(vec, v, u);
        }
    }
}

int main() {
    int n, a, b, c;
    cin >> n;

    vector<pii> vec[n + 1];

    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        vec[a].push_back({b, c});
        vec[b].push_back({a, 0});

        sumTotal += c;
    }

    dfs(vec, 1, -1);

    cout << min(abs(sumTotal - sumRight), sumRight) << endl;
}
