#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool isSimpleCycle;

void dfs(vector<int> vec[], vector<bool> &vis, int u)
{
    vis[u] = true;

    if (vec[u].size() != 2)
        isSimpleCycle = false;

    for (int v : vec[u])
    {
        if (!vis[v])
        {
            dfs(vec, vis, v);
        }
    }
}

int main()
{
    int n, m, a, b, count = 0;
    cin >> n >> m;
    vector<int> vec[n + 1];
    vector<bool> vis(n + 1, false);

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
            isSimpleCycle = true;
            dfs(vec, vis, i);
            count += isSimpleCycle;
        }
    }

    cout << count << endl;
}
