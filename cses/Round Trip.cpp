#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int start = -1, _end = -1;

bool cycle(vector<int> vec[], vector<int> &parent, vector<bool> &vis, int u)
{
    vis[u] = true;

    for (int v : vec[u])
    {
        if (!vis[v])
        {
            parent[v] = u;
            if (cycle(vec, parent, vis, v))
                return true;
        }
        else if (v != parent[u])
        {
            start = v;
            _end = u;
            return true;
        }
    }

    return false;
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    vector<int> vec[n + 1];
    vector<int> parent(n + 1, 0);
    vector<bool> vis(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    bool isCycle = false;

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0 && cycle(vec, parent, vis, i))
        {
            isCycle = true;
            break;
        }
    }

    if (!isCycle)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        stack<int> st;
        st.push(start);
        for (int i = _end; i != start; i = parent[i])
            st.push(i);
        st.push(start);

        cout << st.size() << endl;

        while (st.size())
        {
            int top = st.top();
            st.pop();
            cout << top << " ";
        }
    }
}
