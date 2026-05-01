#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int start = -1, _end = -1;

bool cycle(vector<int> vec[], vector<int> &parent, vector<int> &state, int u)
{
    state[u] = 1; // visited

    for (int v : vec[u])
    {
        if (state[v] == 0) // not visited
        {
            parent[v] = u;
            if (cycle(vec, parent, state, v))
                return true;
        }
        else if (state[v] == 1)
        {
            start = v;
            _end = u;
            return true;
        }
    }

    state[u] = 2; // finished
    return false;
}

int main()
{
    int n, m, a, b;
    cin >> n >> m;
    vector<int> vec[n + 1];
    vector<int> parent(n + 1, -1);
    vector<int> state(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        vec[a].push_back(b);
    }

    bool isCycle = false;

    for (int i = 1; i <= n; i++)
    {
        if (state[i] == 0 && cycle(vec, parent, state, i))
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
