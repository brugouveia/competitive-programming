#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<int> parent(100001);

int bfs(vector<int> vec[])
{
    vector<int> dist(n + 1, -1);

    queue<int> q;
    q.push(1);
    dist[1] = 1;
    parent[1] = 0;

    while (q.size())
    {
        int u = q.front();
        q.pop();

        if (u == n)
            return dist[n];

        for (int v : vec[u])
        {
            if (dist[v] == -1)
            {
                q.push(v);
                dist[v] = dist[u] + 1;
                parent[v] = u;
            }
        }
    }

    return -1;
}

int main()
{
    int m, a, b;
    cin >> n >> m;

    vector<int> vec[n + 1];

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    int ans = bfs(vec);

    if (ans == -1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        cout << ans << endl;

        vector<int> hist;
        for (int i = n; i != 1; i = parent[i])
            hist.push_back(i);
        hist.push_back(1);

        reverse(hist.begin(), hist.end());

        for (int i : hist)
            cout << i << ' ';
    }
}
