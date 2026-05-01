#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(vector<int> vec[], vector<bool> &vis, int inicio)
{
    vis[inicio] = true;

    for (int i = 0; i < vec[inicio].size(); i++)
    {
        int k = vec[inicio][i];
        if (!vis[k])
        {
            dfs(vec, vis, k);
        }
    }
}

int main()
{
    int n, m, a, b, cont = 0;
    cin >> n >> m;

    vector<int> vec[n + 1];
    vector<bool> vis(n + 1, false);
    vector<pair<int, int>> roads;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(vec, vis, i);
            if (i > 1)
            {
                cont++;
                roads.push_back({i - 1, i});
            }
        }
    }

    cout << cont << endl;
    for (auto road : roads)
    {
        cout << road.first << ' ' << road.second << endl;
    }
}
