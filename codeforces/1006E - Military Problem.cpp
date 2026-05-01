#include <iostream>
#include <vector>
#include <set>
using namespace std;

int n, m;
vector<int> path;

void dfs(vector<set<int>> &vec, int posInPath[], int tam[], int u)
{
    posInPath[u] = path.size();
    path.push_back(u);

    for (int v : vec[u])
        dfs(vec, posInPath, tam, v);

    tam[u] = path.size() - posInPath[u];
}

int main()
{
    int a, b;
    cin >> n >> m;

    vector<set<int>> vec(n + 1);
    int posInPath[n + 1], tam[n + 1];

    for (int i = 2; i <= n; i++)
    {
        cin >> a;
        vec[a].insert(i);
    }

    dfs(vec, posInPath, tam, 1);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        if (b > tam[a])
            cout << -1 << endl;
        else
            cout << path[posInPath[a] + b - 1] << endl;
    }
}
