#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> sub; // employee, subordinates

int dfs(vector<int> vec[], int atual)
{
    if (!vec[atual].size())
    {
        return 1;
    }

    int cont = 0;
    for (int i = 0; i < vec[atual].size(); i++)
    {
        int k = vec[atual][i];

        cont += dfs(vec, k);
    }
    sub[atual] = cont;
    return cont + 1;
}

int main()
{
    int n, a;
    cin >> n;

    vector<int> vec[n + 1];

    for (int i = 2; i <= n; i++)
    {
        cin >> a;
        vec[a].push_back(i);
    }

    dfs(vec, 1);

    cout << sub[1];
    for (int i = 2; i <= n; i++)
    {
        cout << ' ' << sub[i];
    }
    cout << endl;
}
