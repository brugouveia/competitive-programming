#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

vector<int> vec[10001];
bool vis[10001];
pii maior; // node, dist

void dfs(int inicio, int dist)
{
    if (dist > maior.second)
    {
        maior = {inicio, dist};
    }

    vis[inicio] = true;

    for (int i = 0; i < vec[inicio].size(); i++)
    {
        int k = vec[inicio][i];
        if (!vis[k])
        {
            dfs(k, dist + 1);
        }
    }
}

int main()
{
    int n, a, b;
    cin >> n;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        vis[i] = false;
    maior = {a, 0};
    dfs(maior.first, maior.second);

    for (int i = 1; i <= n; i++)
        vis[i] = false;
    maior = {maior.first, 0};
    dfs(maior.first, maior.second);

    cout << maior.second << endl;
}
