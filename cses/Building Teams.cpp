#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool bfs(vector<int> vec[], vector<int> &team, int atual)
{
    queue<int> q;
    q.push(atual);
    team[atual] = 0;

    while (q.size())
    {
        int front = q.front();
        q.pop();

        for (int k : vec[front])
        {
            if (team[k] == -1)
            {
                team[k] = 1 - team[front];
                q.push(k);
            }
            else if (team[k] == team[front])
            {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;

    vector<int> vec[n + 1];
    vector<int> team(n + 1, -1);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    bool possible = true;
    for (int i = 1; i <= n && possible; i++)
    {
        if (team[i] == -1)
        {
            possible = bfs(vec, team, i);
        }
    }

    if (!possible)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            cout << team[i] + 1 << " \n"[i == n];
        }
    }
}
