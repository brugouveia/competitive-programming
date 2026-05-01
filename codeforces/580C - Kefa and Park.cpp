#include <iostream>
#include <vector>
using namespace std;

int n, m, cnt = 0;

void dfs(vector<int> vec[], vector<int> &consec, vector<bool> &cat, int u)
{
    if (consec[u] > m)
        return;

    if (u != 1 && vec[u].size() == 1)
        cnt++;

    for (int v : vec[u])
    {
        if (consec[v] == -1)
        {
            if (cat[v])
                consec[v] = consec[u] + 1;
            else
                consec[v] = 0;

            dfs(vec, consec, cat, v);
        }
    }
}

int main()
{
    int a, b;
    cin >> n >> m;
    vector<int> vec[n + 1];
    vector<int> consec(n + 1, -1);
    vector<bool> cats(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        cats[i] = a;
    }

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    consec[1] = cats[1];
    dfs(vec, consec, cats, 1);

    cout << cnt << endl;
}
